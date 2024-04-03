/** 
 * @brief Testea la funcionalidad de link.c
 * 
 * @file link_test.c
 * @author Ignacio González
 * @version 1.0 
 * @date 05-05-2021
 * Editado y comentado por: Ignacio González
 */
#include <stdio.h>
#include <string.h>
#include "link.h"
#include "test.h"
#include "types.h"
#include "link_test.h"
#include <stdlib.h>

#define MAX_TESTS 23
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


  if (all || test == 1) test1_link_create();
  if (all || test == 2) test2_link_create();
  if (all || test == 3) test3_link_create();
  if (all || test == 4) test1_link_setName();
  if (all || test == 5) test2_link_setName();
  if (all || test == 6) test3_link_setName();
  if (all || test == 7) test1_link_setIdSpace1();
  if (all || test == 8) test2_link_setIdSpace1();
  if (all || test == 9) test3_link_setIdSpace1();
  if (all || test == 10) test1_link_setIdSpace2();
  if (all || test == 11) test2_link_setIdSpace2();
  if (all || test == 12) test3_link_setIdSpace2();
  if (all || test == 13) test1_link_setConnection();
  if (all || test == 14) test2_link_setConnection();
  if (all || test == 15) test1_link_getId();
  if (all || test == 16) test2_link_getId();
  if (all || test == 17) test1_link_getSpace1Id();
  if (all || test == 18) test2_link_getSpace1Id();
  if (all || test == 19) test1_link_getSpace2Id();
  if (all || test == 20) test2_link_getSpace2Id();
  if (all || test == 21) test1_link_getName();
  if (all || test == 22) test1_link_getConnection();
  if (all || test == 23) test2_link_getConnection();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_link_create(){
    Link *l;
    int result;

    l = link_create(5);
    result = l != NULL;
    PRINT_TEST_RESULT(result);
    link_destroy(l);
}

void test2_link_create(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_getSpace1Id(l) == NO_ID && link_getSpace2Id(l) == NO_ID);
    link_destroy(l);
}

void test3_link_create(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_getConnection(l) == FALSE);
    link_destroy(l);
}

void test1_link_setName(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_setName(l, "link") == OK);
    link_destroy(l);
}

void test2_link_setName(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_setName(l, NULL) == ERROR);
    link_destroy(l);
}

void test3_link_setName(){
    Link *l = NULL;

    PRINT_TEST_RESULT(link_setName(l, "link") == ERROR);
}

void test1_link_setIdSpace1(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_setIdSpace1(l, 1) == OK);
    link_destroy(l);
}

void test2_link_setIdSpace1(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_setIdSpace1(l, NO_ID) == ERROR);
    link_destroy(l);
}

void test3_link_setIdSpace1(){
    Link *l = NULL;

    PRINT_TEST_RESULT(link_setIdSpace1(l, 5) == ERROR);
}

void test1_link_setIdSpace2(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_setIdSpace2(l, 1) == OK);
    link_destroy(l);
}

void test2_link_setIdSpace2(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_setIdSpace2(l, NO_ID) == ERROR);
    link_destroy(l);
}

void test3_link_setIdSpace2(){
    Link *l = NULL;

    PRINT_TEST_RESULT(link_setIdSpace2(l, 5) == ERROR);
}

void test1_link_setConnection(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(Link_setConnection(l, TRUE) == OK);
    link_destroy(l);
}

void test2_link_setConnection(){
    Link *l = NULL;

    PRINT_TEST_RESULT(Link_setConnection(l, TRUE) == ERROR);
}

void test1_link_getId(){
    Link *l;

    l = link_create(5);
    PRINT_TEST_RESULT(link_getId(l) == 5);
    link_destroy(l);
}

void test2_link_getId(){
    Link *l = NULL;

    PRINT_TEST_RESULT(link_getId(l) == NO_ID);
}

void test1_link_getSpace1Id(){
    Link *l;

    l = link_create(5);
    link_setIdSpace1(l, 5);
    PRINT_TEST_RESULT(link_getSpace1Id(l) == 5);
    link_destroy(l);
}

void test2_link_getSpace1Id(){
    Link *l = NULL;

    PRINT_TEST_RESULT(link_getSpace1Id(l) == NO_ID);
}

void test1_link_getSpace2Id(){
    Link *l;

    l = link_create(5);
    link_setIdSpace2(l, 5);
    PRINT_TEST_RESULT(link_getSpace2Id(l) == 5);
    link_destroy(l);
}

void test2_link_getSpace2Id(){
    Link *l = NULL;

    PRINT_TEST_RESULT(link_getSpace2Id(l) == NO_ID);
}

void test1_link_getName(){
    Link *l;

    l = link_create(5);
    link_setName(l, "link");
    PRINT_TEST_RESULT(strcmp(link_getName(l), "link") == 0);
    link_destroy(l);
}

void test1_link_getConnection(){
    Link *l;

    l = link_create(5);
    Link_setConnection(l, TRUE);
    PRINT_TEST_RESULT(link_getConnection(l) == TRUE);
    link_destroy(l);
}

void test2_link_getConnection(){
    Link *l = NULL;

    PRINT_TEST_RESULT(link_getConnection(l) == FALSE);
}
