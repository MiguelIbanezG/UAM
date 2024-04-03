import ast
import inspect
from ast_utils import ASTNestedForCounter

#Test numero 2 del ejercicio 1A
def fun1(p):
    for a in [10, 20, 30]:
        print(a)
    for x in range(10):
        print(x)

def fun2(p):
    for a in [10, 20, 30]:
        print(a)
    for i in [10, 20, 30]:
        for j in [10, 20, 30]:
            for k in [10, 20, 30]:
                print(i)
    for b in [10, 20, 30]:
        print(b)

def fun3():
    for a in [10]:
        for b in [10]:
            for c in [10]:
                print(c)
        for b in [10]:
            print(a)
        for b in [10]:
            for c in [10]:
                for d in [10]:
                    for e in [10]:
                        print(e)
                for x in [10]:
                    print(x)

def main() -> None:
    counter = ASTNestedForCounter()
    source = inspect.getsource(fun1)
    my_ast = ast.parse(source)
    print("Maximum number of nested for loops:", counter.visit(my_ast))
    source = inspect.getsource(fun2)
    my_ast = ast.parse(source)
    print("Maximum number of nested for loops:", counter.visit(my_ast))
    source = inspect.getsource(fun3)
    my_ast = ast.parse(source)
    print("Maximum number of nested for loops:", counter.visit(my_ast))
        
main()