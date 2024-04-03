/** 
 * @brief Testea la funcionalidad de set.c
 * 
 * 
 * @file set_test.c
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Miguel Ibáñez 
 */
#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "test.h"
#include "set_test.h"

#define MAX_TESTS 15
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


  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_add_id();
  if (all || test == 4) test2_set_add_id();
  if (all || test == 5) test3_set_add_id();
  if (all || test == 6) test1_set_del_id();
  if (all || test == 7) test2_set_del_id();
  if (all || test == 8) test3_set_del_id();
  if (all || test == 9) test1_set_findId();
  if (all || test == 10) test2_set_findId();
  if (all || test == 11) test1_set_idCheck();
  if (all || test == 12) test2_set_idCheck();
  if (all || test == 13) test1_set_getnIds();
  if (all || test == 14) test2_set_getnIds();
  if (all || test == 15) test3_set_getnIds();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create(){
    Set *s;
    int result;

    s = set_create();
    result = s != NULL;
    PRINT_TEST_RESULT(result);
    set_destroy(s); 
}

void test2_set_create(){
    Set *s;

    s = set_create();
    PRINT_TEST_RESULT(set_getnIds(s) == 0);
    set_destroy(s);
}

void test1_set_add_id(){
    Set *s;

    s = set_create();
    PRINT_TEST_RESULT(set_add_id(s, 5) == OK);
    set_destroy(s);
}

void test2_set_add_id(){
    Set *s;

    s = set_create();
    PRINT_TEST_RESULT(set_add_id(s, NO_ID) == ERROR);
    set_destroy(s);
}

void test3_set_add_id(){
    Set *s = NULL;

    PRINT_TEST_RESULT(set_add_id(s, 5) == ERROR);
}

void test1_set_del_id(){
    Set *s;

    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_del_id(s, 5) == OK);
    set_destroy(s);
}

void test2_set_del_id(){
    Set *s;
     
    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_del_id(s, NO_ID) == ERROR);
    set_destroy(s);
}

void test3_set_del_id(){
    Set *s = NULL;

    PRINT_TEST_RESULT(set_del_id(s, 5) == ERROR);
}

void test1_set_findId(){
    Set *s;

    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_findId(s, 0) == 5);
    set_destroy(s);
}

void test2_set_findId(){
    Set *s;

    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_findId(s, 1) == NO_ID);
    set_destroy(s);
}

void test1_set_idCheck(){
    Set *s;

    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_Idcheck(s, 5) == TRUE);
    set_destroy(s);
}

void test2_set_idCheck(){
    Set *s;

    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_Idcheck(s, NO_ID) == FALSE);
    set_destroy(s);
}

void test1_set_getnIds(){
    Set *s;

    s = set_create();
    set_add_id(s, 5);
    PRINT_TEST_RESULT(set_getnIds(s) == 1);
    set_destroy(s);
}

void test2_set_getnIds(){
    Set *s;

    s = set_create();
    PRINT_TEST_RESULT(set_getnIds(s) == 0);
    set_destroy(s);
}

void test3_set_getnIds(){
    Set *s = NULL;

    PRINT_TEST_RESULT(set_getnIds(s) == -1);
}
