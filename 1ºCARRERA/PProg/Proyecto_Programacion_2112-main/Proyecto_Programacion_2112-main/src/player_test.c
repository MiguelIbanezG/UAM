#include "player.h"
#include "test.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "player_test.h"

#define MAX_TESTS 27
#define EXIT_SUCCESS 0

int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_player_create();
  if (all || test == 2) test2_player_create();
  if (all || test == 3) test1_player_set_name();
  if (all || test == 4) test2_player_set_name();
  if (all || test == 5) test3_player_set_name();
  if (all || test == 6) test1_player_set_addObject();
  if (all || test == 7) test2_player_set_addObject();
  if (all || test == 8) test3_player_set_addObject();
  if (all || test == 9) test1_player_set_delObject();
  if (all || test == 10) test2_player_set_delObject();
  if (all || test == 11) test3_player_set_delObject();
  if (all || test == 12) test1_player_set_location();
  if (all || test == 13) test2_player_set_location();
  if (all || test == 14) test3_player_set_location();
  if (all || test == 15) test1_player_set_Inventorymax();
  if (all || test == 16) test2_player_set_Inventorymax();
  if (all || test == 17) test3_player_set_Inventorymax();
  if (all || test == 18) test1_player_get_name();
  if (all || test == 19) test2_player_get_name();
  if (all || test == 20) test1_player_get_id();
  if (all || test == 21) test2_player_get_id();
  if (all || test == 22) test1_player_get_location();
  if (all || test == 23) test2_player_get_location();
  if (all || test == 24) test1_player_get_Inventorytam();
  if (all || test == 25) test2_player_get_Inventorytam();
  if (all || test == 26) test1_player_get_Inventorymax();
  if (all || test == 27) test2_player_get_Inventorymax();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_player_create(){
    int result;
    Player *p;

    p = player_create(5);
    result = p != NULL;

    PRINT_TEST_RESULT(result);
    player_destroy(p);
}

void test2_player_create(){
    Player *p;

    p = player_create(4);
    PRINT_TEST_RESULT(player_get_id(p) == 4);
    player_destroy(p);
}

void test1_player_set_name(){
    Player *p;
    p = player_create(5);

    PRINT_TEST_RESULT(player_set_name(p, "manolo") == OK);
    player_destroy(p);
}

void test2_player_set_name(){
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_name(p, "manolo") == ERROR);
}

void test3_player_set_name(){
    Player *p;

    p = player_create(5);
    PRINT_TEST_RESULT(player_set_name(p, NULL) == ERROR);
    player_destroy(p);
}

void test1_player_set_addObject(){
    Player *p;
    p = player_create(5);

    PRINT_TEST_RESULT(player_set_addObject(p, 5) == OK);
    player_destroy(p);
}

void test2_player_set_addObject(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_set_addObject(p, 5) == ERROR);
}

void test3_player_set_addObject(){
    Player *p;

    p = player_create(5);

    PRINT_TEST_RESULT(player_set_addObject(p, NO_ID) == ERROR);
    player_destroy(p);
}

void test1_player_set_delObject(){
    Player *p;

    p = player_create(5);

    player_set_addObject(p, 5);
    PRINT_TEST_RESULT(player_set_delObject(p, 5) == OK);
    player_destroy(p);
}

void test2_player_set_delObject(){
    Player *p;

    p = player_create(5);

    player_set_addObject(p, 5);
    PRINT_TEST_RESULT(player_set_delObject(p, NO_ID) == ERROR);
    player_destroy(p);
}

void test3_player_set_delObject(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_set_delObject(p, 5) == ERROR);
}

void test1_player_set_location(){
    Player *p;

    p = player_create(5);
    PRINT_TEST_RESULT(player_set_location(p, 5) == OK);
    player_destroy(p);
}

void test2_player_set_location(){
    Player *p;

    p = player_create(5);
    PRINT_TEST_RESULT(player_set_location(p, NO_ID) == ERROR);
    player_destroy(p);
}

void test3_player_set_location(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_set_location(p, 5) == ERROR);
}

void test1_player_set_Inventorymax(){
    Player *p;

    p = player_create(5);
    PRINT_TEST_RESULT(player_set_Inventorymax(p, 5) == OK);
    player_destroy(p);
}

void test2_player_set_Inventorymax(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_set_Inventorymax(p, 5) == ERROR);
}

void test3_player_set_Inventorymax(){
    Player *p;

    p = player_create(5);
    PRINT_TEST_RESULT(player_set_Inventorymax(p, -1) == ERROR);
    player_destroy(p);
}

void test1_player_get_name(){
    Player *p;

    p = player_create(5);
    player_set_name(p, "manolo");
    PRINT_TEST_RESULT(strcmp(player_get_name(p), "manolo") == 0);
    player_destroy(p);
}

void test2_player_get_name(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_get_name(p) == NULL);
}

void test1_player_get_id(){
    Player *p;

    p = player_create(5);
    PRINT_TEST_RESULT(player_get_id(p) == 5);
    player_destroy(p);
}

void test2_player_get_id(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_get_id(p) == NO_ID);
}

void test1_player_get_location(){
    Player *p;

    p = player_create(5);
    player_set_location(p, 5);
    PRINT_TEST_RESULT(player_get_location(p) == 5);
    player_destroy(p);
}

void test2_player_get_location(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_get_location(p) == NO_ID);
}

void test1_player_get_Inventorytam(){
    Player *p;

    p = player_create(5);
    player_set_addObject(p, 5);
    PRINT_TEST_RESULT(player_get_Inventorytam(p) == 1);
    player_destroy(p);
}

void test2_player_get_Inventorytam(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_get_Inventorytam(p) == 0);
}

void test1_player_get_Inventorymax(){
    Player *p;

    p = player_create(5);
    player_set_Inventorymax(p, 5);
    PRINT_TEST_RESULT(player_get_Inventorymax(p) == 5);
    player_destroy(p);
}

void test2_player_get_Inventorymax(){
    Player *p = NULL;

    PRINT_TEST_RESULT(player_get_Inventorymax(p) == 0);
}

