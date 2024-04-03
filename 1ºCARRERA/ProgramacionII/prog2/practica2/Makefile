p2_e4 : p2_e4.o stack_fp.o int.o node.o graph.o
	gcc p2_e4.o stack_fp.o int.o node.o graph.o -o p2_e4
p2_e4.o : p2_e4.c
	gcc -c p2_e4.c
stack_fp.o : stack_fp.c stack_fp.h
	gcc -c stack_fp.c
int.o : int.c int.h
	gcc -c int.c
node.o : node.c node.h
	gcc -c node.c
graph.o : graph.c graph.h
	gcc -c graph.c
