CC = gcc
CFLAGS = -Wall -pedantic -ansi

.PHONY: all clean_objets clean_program clean_gchfiles clean

all: ocabas set_test die_test space_test clean_objets clean_gchfiles

ocabas: game.o command.o game_loop.o space.o graphic_engine.o screen.o game_reader.o object.o player.o set.o die.o
	$(CC) $(CFLAGS) $^ -o $@

set_test: set.o set_test.o
	$(CC) $(CFLAGS) $^ -o $@

die_test: die.o die_test.o
	$(CC) $(CFLAGS) $^ -o $@

space_test: space.o space_test.o set.o
	$(CC) $(CFLAGS) $^ -o $@


game.o: game.c game.h command.h space.h types.h player.h object.h game_reader.h set.h die.h
	$(CC) -c $(CFLAGS) $^

command.o: command.c command.h
	$(CC) -c $(CFLAGS) $^

game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h types.h player.h object.h 
	$(CC) -c $(CFLAGS) $^

space.o: space.c types.h space.h set.h
	$(CC) -c $(CFLAGS) $^

screen.o: screen.c screen.h
	$(CC) -c $(CFLAGS) $^

graphic_engine.o: graphic_engine.c screen.h graphic_engine.h game.h command.h space.h types.h
	$(CC) -c $(CFLAGS) $^

game_reader.o: game_reader.c game_reader.h space.h types.h game.h command.h player.h object.h
	$(CC) -c $(CFLAGS) $^

object.o: object.c object.h types.h 
	$(CC) -c $(CFLAGS) $^

player.o: player.c player.h types.h
	$(CC) -c $(CFLAGS) $^

set.o: set.c set.h types.h
	$(CC) -c $(CFLAGS) $^

die.o: die.c die.h types.h
	$(CC) -c $(CFLAGS) $^

set_test.o: set_test.c set.h types.h
	$(CC) -c $(CFLAGS) $^

die_test.o: die_test.c die.h types.h
	$(CC) -c $(CFLAGS) $^

space_test.o: space_test.c space.h space_test.h types.h types.h
	$(CC) -c $(CFLAGS) $^


clean_objets:
	@rm -f *.o 
clean_gchfiles:
	@rm -f *.gch
clean_program:
	@rm -f ocabas
clean: clean_objets clean_gchfiles clean_program