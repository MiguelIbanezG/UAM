C = gcc
CFLAGS = -Wall -pedantic -ansi


.PHONY: all clean_objets clean_program clean_gchfiles clean

all1: p1_e1 clean_objets clean_gchfiles

all2: p1_e2 clean_objets clean_gchfiles


p1_e1: vertex.o p1_e1.o
	$(CC) $(CFLAGS) $^ -o $@

p1_e2: vertex.o graph.o p1_e2.o
	$(CC) $(CFLAGS) $^ -o $@


vertex.o: vertex.c vertex.h types.h
	$(CC) -c $(CFLAGS) $^

graph.o: graph.c vertex.h graph.h types.h
	$(CC) -c $(CFLAGS) $^

p1_e1.o: p1_e1.c vertex.h types.h
	$(CC) -c $(CFLAGS) $^

p1_e2.o: p1_e2.c vertex.h graph.h types.h 
	$(CC) -c $(CFLAGS) $^


clean_objets:
	@rm -f *.o 
clean_gchfiles:
	@rm -f *.gch
clean_program1:
	@rm -f p1_e1
clean_program2:
	@rm -f p1_e2

clean: clean_objets clean_gchfiles clean_program1 clean_program2