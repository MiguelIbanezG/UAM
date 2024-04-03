/** 
 * @brief Testea el funcionamiento de
 * las funciones de inventory.c
 * 
 * @file inventory_test.c
 * @author Mario Iribas
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Mario Iribas 
 */
#include <stdio.h>
#include "inventory.h"
#include "test.h"
#include "inventory_test.h"
#include <stdlib.h>

#define MAX_TESTS 24
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


  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test2_inventory_create();
  if (all || test == 3) test1_inventory_set_addId();
  if (all || test == 4) test2_inventory_set_addId();
  if (all || test == 5) test3_inventory_set_addId();
  if (all || test == 6) test1_inventory_set_delId();
  if (all || test == 7) test2_inventory_set_delId();
  if (all || test == 8) test3_inventory_set_delId();
  if (all || test == 9) test4_inventory_set_delId();
  if (all || test == 10) test1_inventory_setMax();
  if (all || test == 11) test2_inventory_setMax();
  if (all || test == 12) test3_inventory_setMax();
  if (all || test == 13) test1_inventory_getId();
  if (all || test == 14) test2_inventory_getId();
  if (all || test == 15) test3_inventory_getId();
  if (all || test == 16) test1_inventory_getMax();
  if (all || test == 17) test2_inventory_getMax();
  if (all || test == 18) test1_inventory_existId();
  if (all || test == 19) test2_inventory_existId();
  if (all || test == 20) test3_inventory_existId();
  if (all || test == 21) test4_inventory_existId();
  if (all || test == 22) test1_inventory_getTam();
  if (all || test == 23) test2_inventory_getTam();
  if (all || test == 24) test3_inventory_getTam();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_inventory_create(){
    Bag *b;
    int result;

    b = inventory_create();
    result = b != NULL;
    PRINT_TEST_RESULT(result);
    inventory_destroy(b);
}

void test2_inventory_create(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_getMax(b) == 20);
    inventory_destroy(b);
}

void test1_inventory_set_addId(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_set_addId(b, 5) == OK);
    inventory_destroy(b);
}

void test2_inventory_set_addId(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_set_addId(b, NO_ID) == ERROR);
    inventory_destroy(b);
}

void test3_inventory_set_addId(){
    Bag *b = NULL;

    PRINT_TEST_RESULT(inventory_set_addId(b, 5) == ERROR);
}

void test1_inventory_set_delId(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_set_delId(b, 5) == OK);
    inventory_destroy(b);
}

void test2_inventory_set_delId(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_set_delId(b, NO_ID) == ERROR);
    inventory_destroy(b);
}

void test3_inventory_set_delId(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_set_delId(b, 5) == ERROR);
    inventory_destroy(b);
}

void test4_inventory_set_delId(){
    Bag *b = NULL;

    PRINT_TEST_RESULT(inventory_set_delId(b, 5) == ERROR);
}

void test1_inventory_setMax(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_setMax(b, 5) == OK);
    inventory_destroy(b);
}

void test2_inventory_setMax(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_setMax(b, -1) == ERROR);
    inventory_destroy(b);
}

void test3_inventory_setMax(){
    Bag *b = NULL;

    PRINT_TEST_RESULT(inventory_setMax(b, 5) == ERROR);
}

void test1_inventory_getId(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_getId(b, 0) == 5);
    inventory_destroy(b);
}

void test2_inventory_getId(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_getId(b, 1) == NO_ID);
    inventory_destroy(b);
}

void test3_inventory_getId(){
    Bag *b = NULL;

    PRINT_TEST_RESULT(inventory_getId(b, 0) == NO_ID);
}

void test1_inventory_getMax(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_getMax(b) == 20);
    inventory_destroy(b);
}

void test2_inventory_getMax(){
    Bag *b = NULL;

    PRINT_TEST_RESULT(inventory_getMax(b) == -1);
}

void test1_inventory_existId(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_existId(b, 5) == TRUE);
    inventory_destroy(b);
}

void test2_inventory_existId(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_existId(b, 1) == FALSE);
    inventory_destroy(b);
}

void test3_inventory_existId(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_existId(b, NO_ID) == FALSE);
    inventory_destroy(b);
}

void test4_inventory_existId(){
    Bag *b = NULL;

    PRINT_TEST_RESULT(inventory_existId(b, 5) == FALSE);
}

void test1_inventory_getTam(){
    Bag *b;

    b = inventory_create();
    inventory_set_addId(b, 5);
    PRINT_TEST_RESULT(inventory_getTam(b) == 1);
    inventory_destroy(b);
}

void test2_inventory_getTam(){
    Bag *b;

    b = inventory_create();
    PRINT_TEST_RESULT(inventory_getTam(b) == 0);
    inventory_destroy(b);
}

void test3_inventory_getTam(){
    Bag *b = NULL;

    PRINT_TEST_RESULT(inventory_getTam(b) == -1);
}