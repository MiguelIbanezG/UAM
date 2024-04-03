CC = gcc
CFLAGS = -Wall -ansi -pedantic 
IFLAGS = -I./
LDFLAGS = -L./
LDLIBS = -lstack_fDoble
LIBS = libstack_fDoble.a

all: stack_fDoble.a p2_e2 clean_objects 
	
p2_e1a: p2_e1a.o $(LIBS) stack_fDoble.h types.h file_utils.h
	$(CC) $(CFLAGS) -o p2_e1a p2_e1a.o $(LDFLAGS) $(LDLIBS)

p2_e1b: p2_e1b.o $(LIBS) stack_fDoble.h types.h file_utils.h vertex.h vertex.o graph.o
	$(CC) $(CFLAGS) -o p2_e1b p2_e1b.o vertex.o graph.o $(LDFLAGS) $(LDLIBS)

p2_e2: p2_e2.o $(LIBS) stack_fDoble.h types.h queue.h file_utils.h vertex.h vertex.o graph.o queue.o
	$(CC) $(CFLAGS) -o p2_e2 p2_e2.o vertex.o graph.o queue.o $(LDFLAGS) $(LDLIBS)

p2_e1a.o: p2_e1a.c 
	$(CC) $(CFLAGS) -c -g p2_e1a.c
	
p2_e1b.o: p2_e1b.c stack_fDoble.o vertex.o graph.o
	$(CC) $(CFLAGS) -c -g p2_e1b.c

p2_e2.o: p2_e2.c vertex.o graph.o
	$(CC) $(CFLAGS) -c -g p2_e2.c
	
vertex.o: vertex.c vertex.h types.h
	$(CC) $(CFLAGS) -c -g vertex.c
	
graph.o: graph.c vertex.h graph.h types.h
	$(CC) $(CFLAGS) -c -g graph.c

queue.o: queue.c queue.h types.h
	$(CC) $(CFLAGS) -c -g queue.c

stack_fDoble.o: stack_fDoble.c stack_fDoble.h types.h 
	$(CC) $(CFLAGS) -c -g stack_fDoble.c

stack_fDoble.a: stack_fDoble.o 
	ar rcs libstack_fDoble.a stack_fDoble.o

clean_objects:
	rm *.o

clean: 
	rm p2_e1a p2_e1b p2_e2	
	
