import ast
from ast import AST, List, NodeVisitor, iter_fields
from typing import List
from copy import deepcopy
from ast import AST, NodeTransformer


class ASTNestedForCounter(ast.NodeVisitor):
    
    def generic_visit(self, node: ast.AST):
        res = 0
        lista = []
        for field, value in ast.iter_fields(node):
            
            if isinstance(value, list):
                for item in value:    
                    if isinstance(item, ast.AST):
                        res += self.visit(item)
                        if (type(item) == ast.For):
                           lista.append(res)
                           res = 0   
                        
            elif isinstance(value, ast.AST):
                self.visit(value)
                
        if lista: 
            return mayor(lista)
            
        return res

    def visit_For(self, node: ast.AST):
        return 1 + self.generic_visit(node)
         
def mayor(lista):
    max = lista[0]
    for x in lista:
        if x > max:
            max = x
    return max 
        

class ASTDotVisitor(ast.NodeVisitor):

    def __init__(self) -> None:
        super().__init__()
        self.counter = 0
        self.level = 0
        self.diagraph = "diagraph {\n"

    def printDiagrama(self, node):
        self.printArbol(node, -1, None)
        self.diagraph += "}"
        print(self.diagraph)
        
    def printArbol(self, node, pr, label):
        self.diagraph += "s" + str(self.counter) + "[label=\"" + type(node).__name__ + "("

        fg = False
        for field, value in ast.iter_fields(node):
            if not isinstance(value, list) and not isinstance(value, ast.AST):
                fg = True
                self.diagraph += str(field) + "="
                if isinstance(value, str):
                    self.diagraph += "\'" + str(value) + "\', "
                else:
                    self.diagraph += str(value) + ", "
        if fg:
            self.diagraph = self.diagraph.rstrip(self.diagraph[-1])
            self.diagraph = self.diagraph.rstrip(self.diagraph[-1])

        self.diagraph += ")\", shape=box]\n"

        if pr != -1 and label is not None:
            self.diagraph += "s" + str(pr) + " -> s" + str(self.counter) + "[label=\"" + str(label) + "\"]\n"
        lv = self.counter

        self.counter += 1
        for field, value in ast.iter_fields(node):
            if isinstance(value, list):
                for elem in value:
                    if isinstance(elem, ast.AST):
                        self.printArbol(elem, lv, field)
            if isinstance(value, ast.AST):
                self.printArbol(value, lv, field)


class ASTReplaceVar(NodeTransformer):

    def __init__(self, var: str, value1: AST):
        self.id = var
        self.value_n = value1

    def visit_Name(self, node: AST) -> AST:
        id1 = False
        ld = False
        
        for field, value in iter_fields(node):
            if field == 'id' and value == self.id:
                id1 = True
            if field == 'ctx' and "<ast.Load" in str(value):
                ld = True
        
        if id1 and ld:
            return self.value_n
        return node


class ASTUnroll(NodeTransformer):
    
    def visit_For(self, node: AST) -> AST:
        nombre = None
        lista = None
        etiq = getattr(node, "target")
        lista1 = getattr(node, "iter")
        if "Name" == etiq.__class__.__name__ and \
            "List" == lista1.__class__.__name__:
            nombre = getattr(etiq, "id")
            lista = getattr(lista1, "elts")
        
        if nombre is None or lista is None:
            return node
        
        body = getattr(node, "body")
        resultado = list()
        while len(lista):
            res1 = lista.pop(0)
            repet = ASTReplaceVar(nombre, res1)
            for elemento in body:
                copy = deepcopy(elemento)
                if not "For" == elemento.__class__.__name__:
                    repet.visit(copy)
                    resultado.append(copy)
                else:
                    copy1 = self.visit(copy)
                    if isinstance(copy1, List):
                        for elemento2 in copy1:
                            repet.visit(elemento2)
                            resultado.append(elemento2)
                    else:
                        resultado.append(copy1)
        return resultado



