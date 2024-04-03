import ast
import inspect
from ast_utils import ASTNestedForCounter

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

def main() -> None:
    counter = ASTNestedForCounter()
    source = inspect.getsource(fun1)
    my_ast = ast.parse(source)
    print("Maximum number of nested for loops:", counter.visit(my_ast))
    #Should print 1

    source = inspect.getsource(fun2)
    my_ast = ast.parse(source)
    print("Maximum number of nested for loops:", counter.visit(my_ast))
    # Should print 3

if __name__ == '__main__':
    main()