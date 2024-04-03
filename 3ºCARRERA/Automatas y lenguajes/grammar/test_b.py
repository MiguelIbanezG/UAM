import ast
import inspect
from ast_utils import ASTDotVisitor

def print_if_pos(num):
    if num > 0:
        print(num)
    

dotVisitor = ASTDotVisitor()
source = inspect.getsource(print_if_pos)
my_ast = ast.parse(source)
dotVisitor.printDiagrama(my_ast)



        
