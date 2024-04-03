import ast
from logging import NullHandler
import numbers

from typing import List, Optional, Union


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
        
       


         
                    
class ASTReplaceVar(ast.NodeTransformer):

    def __init__(self, nameVar: str): 
        self.nameVar = nameVar
        
    def visit_Num(self, node: ast.Num) -> ast.AST:
        return ast.Num(self.number)
    
    def visit_Constant(self, node: ast.Constant) -> ast.AST:
        return ast.Constant(self.number)


class ASTUnroll(ast.NodeTransformer):
    
    def visit_If(self, node: ast.If) -> Union[ast.AST, List[ast.stmt]]:
        
        self.generic_visit(node)
    
        if isinstance(node.test, ast.Constant) or isinstance(node.test, ast.NameConstant):
            if node.test.value:
                return node.body

            else:
                return node.orelse

        return node