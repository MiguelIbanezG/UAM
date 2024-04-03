Cflag = -pthread -ansi -Wall -pedantic -g

all: mrush

mrush: mrush.o pow.o pow.h 
	gcc $(Cflag) -o mrush mrush.o pow.o

mrush.o: mrush.c pow.h
	gcc $(Cflag) -c mrush.c 

pow.o: pow.c pow.h
	gcc $(Cflag) -c pow.c


clean_objets:
	rm *.o

clean_programm:
	rm mrush 

clean: clean_objets clean_programm
	