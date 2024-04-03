import ast
import inspect
from ast_utils import ASTReplaceVar

#Test numero 2 del ejercicio 1C, añadiendo una variable var
def fun3(x):
    num = x + 2
    var = 1
    if num > 0:
        print(num, var)

source = inspect.getsource(fun3)
my_ast = ast.parse(source)
print(source)
repl = ASTReplaceVar("var", ast.Constant(4))
repl1 = ASTReplaceVar("num", ast.Constant(0))
repl.visit(my_ast)
repl1.visit(my_ast)
print(ast.unparse(my_ast))