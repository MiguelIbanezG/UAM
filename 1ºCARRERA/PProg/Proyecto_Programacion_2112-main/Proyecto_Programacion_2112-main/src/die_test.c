/** 
 * @brief Testea el funcionamiento del dado
 * 
 * @file die_test.c
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 20-03-2021 
 * Editado y comentado por: Miguel Ibáñez
 */
#include <stdio.h>
#include <stdlib.h>
#include "die.h"
#include "test.h"
#include "die_test.h"

#define MAX_TESTS 17
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


  if (all || test == 1) test1_die_create();
  if (all || test == 2) test2_die_create();
  if (all || test == 3) test3_die_create();
  if (all || test == 4) test4_die_create();
  if (all || test == 5) test1_die_roll();
  if (all || test == 6) test2_die_roll();
  if (all || test == 7) test3_die_roll();
  if (all || test == 8) test1_die_lastroll();
  if (all || test == 9) test2_die_lastroll();
  if (all || test == 10) test1_die_get_id();
  if (all || test == 11) test2_die_get_id();
  if (all || test == 12) test1_die_get_min();
  if (all || test == 13) test2_die_get_min();
  if (all || test == 14) test1_die_get_max();
  if (all || test == 15) test2_die_get_max();
  if (all || test == 16) test1_die_get_last();
  if (all || test == 17) test2_die_get_last();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_die_create(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_get_id(d) == 5);
    die_destroy(d);
}

void test2_die_create(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_get_min(d) == 1);
    die_destroy(d);
}

void test3_die_create(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_get_max(d) == 6);
    die_destroy(d);
}

void test4_die_create(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_lastroll(d) > 0 || die_lastroll(d) < 7);
    die_destroy(d);
}

void test1_die_roll(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_lastroll(d) > 0 || die_lastroll(d) < 7);
    die_destroy(d);
}

void test2_die_roll(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_lastroll(d) >= 1 || die_lastroll(d) <= 6);
    die_destroy(d);
}

void test3_die_roll(){
    Die *d = NULL;

    PRINT_TEST_RESULT(die_roll(d) == -1);
}

void test1_die_lastroll(){
    Die *d;

    d = die_create(5, 1, 6);
    die_roll(d);
    PRINT_TEST_RESULT(die_lastroll(d) > 0 || die_lastroll(d) < 7);
    die_destroy(d);
}

void test2_die_lastroll(){
    Die *d = NULL;

    PRINT_TEST_RESULT(die_lastroll(d) > 0 || die_lastroll(d) < 7);
}

void test1_die_get_id(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_get_id(d) == 5);
    die_destroy(d);
}

void test2_die_get_id(){
    Die *d = NULL;

    PRINT_TEST_RESULT(die_get_id(d) == NO_ID);
}

void test1_die_get_min(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_get_min(d) == 1);
    die_destroy(d);
}

void test2_die_get_min(){
    Die *d = NULL;

    PRINT_TEST_RESULT(die_get_min(d) == -1);
}

void test1_die_get_max(){
    Die *d;

    d = die_create(5, 1, 6);
    PRINT_TEST_RESULT(die_get_max(d) == 6);
    die_destroy(d);
}

void test2_die_get_max(){
    Die *d = NULL;

    PRINT_TEST_RESULT(die_get_max(d) == -1);
}

void test1_die_get_last(){
    Die *d;

    d = die_create(5, 1, 6);
    die_roll(d);
    PRINT_TEST_RESULT(die_get_last(d) > 0 || die_get_last(d) < 7);
    die_destroy(d);
}

void test2_die_get_last(){
    Die *d = NULL;

    PRINT_TEST_RESULT(die_get_last(d) > 0 || die_get_last(d) < 7);
}