C= gcc
CFLAGS = -Wall -ansi -pedantic -pthread -g


all: voting


voting: voting.o
	$(C) $(CFLAGS) -o voting voting.o

voting.o: voting.c
	$(C) $(CFLAGS) -c voting.c





clean: clean_programs clean_objs

clean_objs:
	rm *.o

clean_programs:
	rm voting
	