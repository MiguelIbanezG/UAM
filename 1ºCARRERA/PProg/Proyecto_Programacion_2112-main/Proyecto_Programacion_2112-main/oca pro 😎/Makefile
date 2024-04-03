CC = gcc 
CFLAGS = -Wall -pedantic -ansi -g
SRC = ./src/
OBJ = ./obj/
INC = ./include/
INCLUDE = -I $(INC)

.PHONY: all test clean_objets clean

all: ocabas  
	

test: die_test set_test inventory_test link_test object_test clean_objets space_test player_test

./ocabas: $(OBJ)game.o $(OBJ)command.o $(OBJ)game_loop.o $(OBJ)space.o $(OBJ)graphic_engine.o $(OBJ)screen.o $(OBJ)game_reader.o $(OBJ)object.o $(OBJ)player.o $(OBJ)set.o $(OBJ)die.o $(OBJ)inventory.o $(OBJ)link.o
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)

set_test: $(OBJ)set.o $(OBJ)set_test.o
	$(CC) $(CFLAGS) $^ -o $@

die_test: $(OBJ)die.o $(OBJ)die_test.o
	$(CC) $(CFLAGS) $^ -o $@

space_test: $(OBJ)space.o $(OBJ)space_test.o $(OBJ)link.o $(OBJ)set.o 
	$(CC) $(CFLAGS) $^ -o $@

inventory_test: $(OBJ)inventory.o $(OBJ)inventory_test.o $(OBJ)set.o
	$(CC) $(CFLAGS) $^ -o $@

link_test: $(OBJ)link.o $(OBJ)link_test.o
	$(CC) $(CFLAGS) $^ -o $@

object_test: $(OBJ)object.o $(OBJ)object_test.o
	$(CC) $(CFLAGS) $^ -o $@

player_test: $(OBJ)player.o $(OBJ)player_test.o $(OBJ)inventory.o $(OBJ)set.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ)game.o: $(SRC)game.c $(INC)game.h $(INC)space.h $(INC)types.h $(INC)player.h $(INC)command.h $(INC)object.h $(INC)die.h $(INC)game_reader.h $(INC)set.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)command.o: $(SRC)command.c $(INC)command.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)game_loop.o: $(SRC)game_loop.c $(INC)graphic_engine.h $(INC)game.h $(INC)space.h $(INC)types.h $(INC)player.h $(INC)command.h $(INC)object.h $(INC)die.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)space.o: $(SRC)space.c $(INC)types.h $(INC)space.h $(INC)link.h $(INC)set.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)screen.o: $(SRC)screen.c $(INC)screen.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)graphic_engine.o: $(SRC)graphic_engine.c $(INC)screen.h $(INC)graphic_engine.h $(INC)game.h $(INC)space.h $(INC)types.h $(INC)player.h $(INC)command.h $(INC)object.h $(INC)die.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)game_reader.o: $(SRC)game_reader.c $(INC)game_reader.h $(INC)space.h $(INC)types.h $(INC)game.h $(INC)player.h $(INC)command.h $(INC)object.h $(INC)die.h $(INC)link.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)object.o: $(SRC)object.c $(INC)object.h $(INC)types.h 
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)player.o: $(SRC)player.c $(INC)player.h $(INC)types.h $(INC)inventory.h $(INC)set.h $(INC)object.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)set.o: $(SRC)set.c $(INC)set.h $(INC)types.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)die.o: $(SRC)die.c $(INC)die.h $(INC)types.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)inventory.o: $(SRC)inventory.c $(INC)inventory.h $(INC)types.h $(INC)set.h $(INC)object.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)link.o: $(SRC)link.c $(INC)link.h $(INC)types.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)set_test.o: $(SRC)set_test.c $(INC)set.h $(INC)types.h $(INC)set_test.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)die_test.o: $(SRC)die_test.c $(INC)die.h $(INC)types.h $(INC)die_test.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)space_test.o: $(SRC)space_test.c $(INC)space.h $(INC)types.h $(INC)space_test.h $(INC)test.h $(INC)set.h $(INC)link.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)inventory_test.o: $(SRC)inventory_test.c $(INC)inventory.h $(INC)types.h $(INC)set.h $(INC)object.h $(INC)inventory_test.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)link_test.o: $(SRC)link_test.c $(INC)link.h $(INC)types.h $(INC)link_test.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)object_test.o: $(SRC)object_test.c $(INC)object.h $(INC)types.h $(INC)object_test.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

$(OBJ)player_test.o: $(SRC)player_test.c  $(INC)player.h $(INC)test.h $(INC)types.h $(INC)player_test.h
	$(CC) -c -o$@ $(CFLAGS) $< $(INCLUDE)

clean_objects:
	@rm -rf $(OBJ)*.o 
clean_program:
	@rm -rf ocabas die_test set_test space_test inventory_test link_test player_test
clean: clean_objects clean_program