import ast
import inspect
from ast_utils import ASTUnroll

def fun4(p):
    for a in [10, 20, 30]:
        print(a)
        for b in [1, 2, 3]:
            print(2*a+b)
    for x in range(10):
        print(x)
    for i, x in enumerate([10, 20, 30]):
        print(i, x)
        
unroll = ASTUnroll()
source = inspect.getsource(fun4)
my_ast = ast.parse(source)
unroll.visit(my_ast)
print(ast.unparse(my_ast))
