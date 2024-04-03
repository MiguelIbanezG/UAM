CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
IFLAGS = -I./
LDFLAGS = -L./
LDLIBS1 = -ldelivery 
LDLIBS2 = -lqueue
LIBS1 = libdelivery.a 
LIBS2 = libqueue.a

all: p3_e1a p3_e1b p3_e2a p3_e2b p3_e3 clean_objects 
	
p3_e1a: p3_e1a.o vertex.o $(LIBS1) $(LIBS2) delivery.h queue.h product.h vertex.h types.h 
	$(CC) $(CFLAGS) -o p3_e1a p3_e1a.o vertex.o $(LDFLAGS) $(LDLIBS1) $(LDLIBS2)

p3_e1b: p3_e1b.o vertex.o $(LIBS1) $(LIBS2) delivery.h queue.h product.h vertex.h types.h 
	$(CC) $(CFLAGS) -o p3_e1b p3_e1b.o vertex.o $(LDFLAGS) $(LDLIBS1) $(LDLIBS2)

p3_e2a: p3_e2a.o $(LIBS1) types.h vertex.h vertex.o queue.o 
	$(CC) $(CFLAGS) -o p3_e2a p3_e2a.o vertex.o queue.o $(LDFLAGS) $(LDLIBS1)

p3_e2b: p3_e2b.o $(LIBS1) types.h vertex.h vertex.o queue.o
	$(CC) $(CFLAGS) -o p3_e2b p3_e2b.o vertex.o queue.o $(LDFLAGS) $(LDLIBS1)

p3_e3: p3_e3.o $(LIBS1) types.h vertex.h vertex.o list.h list.o
	$(CC) $(CFLAGS) -o p3_e3 p3_e3.o vertex.o list.o

p3_e1a.o: p3_e1a.c vertex.o
	$(CC) $(CFLAGS) -c -g p3_e1a.c $(IFLAGS)
	
p3_e1b.o: p3_e1b.c vertex.o 
	$(CC) $(CFLAGS) -c -g p3_e1b.c $(IFLAGS)

p3_e2a.o: p3_e2a.c vertex.o queue.o
	$(CC) $(CFLAGS) -c -g p3_e2a.c $(IFLAGS)

p3_e2b.o: p3_e2b.c vertex.o queue.o
	$(CC) $(CFLAGS) -c -g p3_e2b.c $(IFLAGS)

p3_e3.o: p3_e3.c vertex.o list.o
	$(CC) $(CFLAGS) -c -g p3_e3.c $(IFLAGS)
	
vertex.o: vertex.c vertex.h types.h
	$(CC) $(CFLAGS) -c -g vertex.c

queue.o: queue.c queue.h types.h
	$(CC) $(CFLAGS) -c -g queue.c

list.o: list.c list.h types.h
	$(CC) $(CFLAGS) -c -g list.c

clean_objects:
	rm *.o

clean: 
	rm p3_e1a p3_e1b p3_e2a p3_e2b p3_e3
	
