CC = gcc
CFLAGS = -Wall -pedantic -ansi -g

.PHONY: all test clean_objets clean

all: ocabas clean_objects 
test: die_test set_test space_test inventory_test link_test clean_objets

ocabas: game.o command.o game_loop.o space.o graphic_engine.o screen.o game_reader.o object.o player.o set.o die.o inventory.o  link.o
	$(CC) $(CFLAGS) $^ -o $@

set_test: set.o set_test.o
	$(CC) $(CFLAGS) $^ -o $@

die_test: die.o die_test.o
	$(CC) $(CFLAGS) $^ -o $@

space_test: space.o space_test.o set.o
	$(CC) $(CFLAGS) $^ -o $@

inventory_test: inventory.o inventory_test.o set.o
	$(CC) $(CFLAGS) $^ -o $@

link_test: link.o link_test.o
	$(CC) $(CFLAGS) $^ -o $@

game.o: game.c game.h space.h types.h player.h command.h object.h die.h game_reader.h set.h
	$(CC) -c $(CFLAGS) $<

command.o: command.c command.h
	$(CC) -c $(CFLAGS) $<

game_loop.o: game_loop.c graphic_engine.h game.h space.h types.h player.h command.h object.h die.h
	$(CC) -c $(CFLAGS) $<

space.o: space.c types.h space.h set.h
	$(CC) -c $(CFLAGS) $<

screen.o: screen.c screen.h
	$(CC) -c $(CFLAGS) $<

graphic_engine.o: graphic_engine.c screen.h graphic_engine.h game.h space.h types.h player.h command.h object.h die.h
	$(CC) -c $(CFLAGS) $<

game_reader.o: game_reader.c game_reader.h space.h types.h game.h player.h command.h object.h die.h link.h
	$(CC) -c $(CFLAGS) $<

object.o: object.c object.h types.h 
	$(CC) -c $(CFLAGS) $<

player.o: player.c player.h types.h inventory.h set.h object.h
	$(CC) -c $(CFLAGS) $<

set.o: set.c set.h types.h
	$(CC) -c $(CFLAGS) $<

die.o: die.c die.h types.h
	$(CC) -c $(CFLAGS) $<

inventory.o: inventory.c inventory.h types.h set.h object.h
	$(CC) -c $(CFLAGS) $<

link.o: link.c link.h types.h
	$(CC) -c $(CFLAGS) $<

set_test.o: set_test.c set.h types.h
	$(CC) -c $(CFLAGS) $<

die_test.o: die_test.c die.h types.h
	$(CC) -c $(CFLAGS) $<

space_test.o: space_test.c space.h types.h space_test.h test.h set.h
	$(CC) -c $(CFLAGS) $<

inventory_test.o: inventory_test.c inventory.h types.h set.h object.h
	$(CC) -c $(CFLAGS) $<

link_test.o: link_test.c link.h types.h
	$(CC) -c $(CFLAGS) $<


clean_objects:
	@rm -rf *.o 
clean_program:
	@rm -rf ocabas die_test set_test space_test inventory_test link_test
clean: clean_objects clean_program