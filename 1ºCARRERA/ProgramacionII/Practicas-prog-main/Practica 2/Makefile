CC = gcc
CFLAGS = -Wall -ansi -pedantic 
IFLAGS = -I./
LDFLAGS = -L./
LDLIBS = -lstack_fDoble
LIBS = libstack_fDoble.a

all: p2_e1a p2_e1b 
	
p2_e1a: p2_e1a.o $(LIBS) stack_fDoble.h types.h file_utils.h
	$(CC) $(CFLAGS) -o p2_e1a p2_e1a.o $(LDFLAGS) $(LDLIBS)

p2_e1b: p2_e1b.o $(LIBS) stack_fDoble.h types.h file_utils.h vertex.h vertex.o graph.o
	$(CC) $(CFLAGS) -o p2_e1b p2_e1b.o vertex.o graph.o $(LDFLAGS) $(LDLIBS)
	
p2_e1a.o: p2_e1a.c 
	$(CC) $(CFLAGS) -c -g p2_e1a.c
	
p2_e1b.o: p2_e1b.c vertex.o graph.o
	$(CC) $(CFLAGS) -c -g p2_e1b.c
	
vertex.o: vertex.c vertex.h types.h
	$(CC) $(CFLAGS) -c -g vertex.c
	
graph.o: graph.c vertex.h graph.h types.h
	$(CC) $(CFLAGS) -c -g graph.c

clean: 
	rm *.o p2_e1a p2_e1b
	
