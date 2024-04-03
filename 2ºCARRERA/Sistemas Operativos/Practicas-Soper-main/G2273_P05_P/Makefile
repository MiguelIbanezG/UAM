C= gcc
CFLAGS = -Wall -ansi -pedantic -g 
LIBF =  -pthread -lrt


all: miner monitor clean_objs



miner: miner.o pow.o pow.h 
	gcc $(Cflag) -o miner miner.o pow.o $(LIBF)

miner.o: miner.c pow.h
	gcc $(Cflag) -c miner.c 

pow.o: pow.c pow.h
	gcc $(Cflag) -c pow.c




monitor: monitor.o pow.o pow.h
	$(C) $(CFLAGS) -o monitor monitor.o pow.o $(LIBF)

monitor.o: monitor.c pow.h
	$(C) $(CFLAGS) -c monitor.c


clean: clean_programs clean_objs

clean_objs:
	rm *.o

clean_programs:
	rm miner | rm monitor


