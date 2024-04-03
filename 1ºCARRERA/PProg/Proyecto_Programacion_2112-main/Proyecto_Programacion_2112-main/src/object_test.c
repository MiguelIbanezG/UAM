#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include "test.h"
#include "object_test.h"

#define MAX_TESTS 18
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


  if (all || test == 1) test1_object_create();
  if (all || test == 2) test2_object_create();
  if (all || test == 3) test3_object_create();
  if (all || test == 4) test1_object_setDescription();
  if (all || test == 5) test2_object_setDescription();
  if (all || test == 6) test3_object_setDescription();
  if (all || test == 7) test1_object_set_name();
  if (all || test == 8) test2_object_set_name();
  if (all || test == 9) test3_object_set_name();
  if (all || test == 10) test1_object_get_id();
  if (all || test == 11) test2_object_get_id();
  if (all || test == 12) test1_object_getDescription();
  if (all || test == 13) test2_object_getDescription();
  if (all || test == 14) test1_object_get_name();
  if (all || test == 15) test2_object_get_name();
  if (all || test == 16) test1_object_Idcheck();
  if (all || test == 17) test2_object_IdCheck();
  if (all || test == 18) test3_object_IdCheck();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_object_create(){
    Object *o;
    int result;

    o = object_create(5);
    result = o != NULL;
    PRINT_TEST_RESULT(result);
    object_destroy(o);
}

void test2_object_create(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_get_id(o) == 5);
    object_destroy(o);
}

void test3_object_create(){

    PRINT_TEST_RESULT(object_create(NO_ID) == NULL);
}

void test1_object_setDescription(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_setDescription(o, "libro") == OK);
    object_destroy(o);
}

void test2_object_setDescription(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_setDescription(o, NULL) == ERROR);
    object_destroy(o);
}

void test3_object_setDescription(){
    Object *o = NULL;

    PRINT_TEST_RESULT(object_setDescription(o, "libro") == ERROR);
}

void test1_object_set_name(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, "libro") == OK);
    object_destroy(o);
}

void test2_object_set_name(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
    object_destroy(o);
}

void test3_object_set_name(){
    Object *o = NULL;

PRINT_TEST_RESULT(object_set_name(o, "libro") == ERROR);
}

void test1_object_get_id(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_get_id(o) == 5);
    object_destroy(o);
}

void test2_object_get_id(){
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
}

void test1_object_getDescription(){
    Object *o;

    o = object_create(5);
    object_setDescription(o, "libro");
    PRINT_TEST_RESULT(strcmp(object_getDescription(o), "libro") == 0);
    object_destroy(o);
}

void test2_object_getDescription(){
    Object *o = NULL;

    PRINT_TEST_RESULT(object_getDescription(o) == NULL);
}

void test1_object_get_name(){
    Object *o;

    o = object_create(5);
    object_set_name(o, "libro");
    PRINT_TEST_RESULT(strcmp(object_get_name(o), "libro") == 0);
    object_destroy(o);
}

void test2_object_get_name(){
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_Idcheck(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_Idcheck(o, 5) == TRUE);
    object_destroy(o);
}

void test2_object_IdCheck(){
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_Idcheck(o, 1) == FALSE);
    object_destroy(o);
}

void test3_object_IdCheck(){
    Object *o = NULL;

    PRINT_TEST_RESULT(object_Idcheck(o, 5) == FALSE);
}
