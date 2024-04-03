import ast
import inspect
from ast_utils import ASTReplaceVar

def fun3(x):
        
    num = x + 2
    if num > 0:
        print(num)
        
source = inspect.getsource(fun3)
my_ast = ast.parse(source)
print(source)
repl = ASTReplaceVar("num", ast.Constant(0))
repl.visit(my_ast)
print(ast.unparse(my_ast))
