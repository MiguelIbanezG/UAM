import ast
import inspect
from ast_utils import ASTUnroll

#Test numero 2 del ejercicio 1d
def fun4(p):
    for a in [10, 20, 30]:
        print(a)
        for b in [1, 2, 3]:
            print(2*a+b)
    for x in range(10):
        print(x)
    for i, x in enumerate([10, 20, 30]):
        print(i, x)
        
def fun5(p):
    for a in []:
        print(a)
        for b in [1,2,3]:
            print(a+b)
    for a in [10, 20]:
        print(a)
        for x in range(2):
            print(x)
    
unroll = ASTUnroll()
source = inspect.getsource(fun4)
my_ast = ast.parse(source)
unroll.visit(my_ast)
print(ast.unparse(my_ast))
source = inspect.getsource(fun5)
my_ast = ast.parse(source)
unroll.visit(my_ast)
print(ast.unparse(my_ast))