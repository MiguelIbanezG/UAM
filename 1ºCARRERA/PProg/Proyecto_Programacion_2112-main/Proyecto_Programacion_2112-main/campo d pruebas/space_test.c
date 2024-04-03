/** 
 * @brief It tests space module
 * 
 * @file space_test_en.c
 * @author Profesores Pprog
 * @version 3.0 
 * @date 16-01-2015
 * @updated 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "space.h"
#include "space_test.h"
#include "test.h"
#include "set.h"
#include "link.h"

#define MAX_TESTS 28

/** 
 * @brief Main function for SPACE unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
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


  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test1_space_set_name();
  if (all || test == 4) test2_space_set_name();
  if (all || test == 5) test3_space_set_name();
  if (all || test == 6) test1_space_set_north();
  if (all || test == 7) test2_space_set_north();
  if (all || test == 8) test1_space_set_south();
  if (all || test == 9) test2_space_set_south();
  if (all || test == 10) test1_space_set_east();
  if (all || test == 11) test2_space_set_east();
  if (all || test == 12) test1_space_set_west();
  if (all || test == 13) test2_space_set_west();
  if (all || test == 14) test1_space_get_name();
  if (all || test == 15) test2_space_get_name();
  if (all || test == 16) test1_space_get_object();
  if (all || test == 17) test2_space_get_object();
  if (all || test == 18) test3_space_get_object();
  if (all || test == 19) test1_space_get_north();
  if (all || test == 20) test2_space_get_north();
  if (all || test == 21) test1_space_get_south();
  if (all || test == 22) test2_space_get_south();
  if (all || test == 23) test1_space_get_east();
  if (all || test == 24) test2_space_get_east();
  if (all || test == 25) test1_space_get_west();
  if (all || test == 26) test2_space_get_west();
  if (all || test == 27) test1_space_get_id();
  if (all || test == 28) test2_space_get_id();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_space_create() {
  int result;
  Space *s;
  s = space_create(5);
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_set_north() {
  Space *s;
  Link* link = link_create (0);
  s = space_create(5);
  

  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2(link, 4);

  PRINT_TEST_RESULT(space_set_north(s, link) == OK);
  
  space_destroy(s);
}

void test2_space_set_north() {
  Space *s = NULL;
  Link* link = link_create (0);
  

  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 4);

  PRINT_TEST_RESULT(space_set_north(s, link) == ERROR);
  link_destroy(link);
}

void test1_space_set_south() {
  Space *s;
  Link* link = link_create (0);
  s = space_create(5);
  

  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 4);

  PRINT_TEST_RESULT(space_set_south(s, link) == OK);
  link_destroy(link);
  space_destroy(s);
}

void test2_space_set_south() {
  Space *s = NULL;
  Link* link = link_create (0);


  link_setIdSpace1(link, space_get_id (s));
  link_setIdSpace2 (link, 4);

  PRINT_TEST_RESULT(space_set_south(s, link) == ERROR);
  link_destroy(link);
}

void test1_space_set_east() {
  Space *s;
  Link* link = link_create (0);
  s = space_create(5);
  

  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 4);

  PRINT_TEST_RESULT(space_set_east(s, link) == OK);
  link_destroy(link);
  space_destroy(s);

}

void test2_space_set_east() {
  Space *s = NULL;
  Link* link = link_create (0);


  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 4);

  PRINT_TEST_RESULT(space_set_east(s, link) == ERROR);
  link_destroy(link);
}

void test1_space_set_west() {
  Space *s;
  Link* link = link_create (0);
  s = space_create(5);


  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 4);

  PRINT_TEST_RESULT(space_set_west(s, link) == OK);
  space_destroy(s);
}

void test2_space_set_west() {
  Space *s = NULL;
  Link* link = link_create (0);


  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 4);

  PRINT_TEST_RESULT(space_set_west(s, link) == ERROR);
  link_destroy(link);

}

void test1_space_setAdd_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_setAdd_object(s,TRUE) == OK);
  space_destroy(s);
}

void test2_space_setAdd_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_setAdd_object(s,TRUE) == ERROR);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_get_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(*space_get_object(s) == NO_ID);
  space_destroy(s);
}

void test2_space_get_object() {
  Space *s;
  Id id = 5;
  s = space_create(1);
  space_setAdd_object(s,id);
  PRINT_TEST_RESULT(*space_get_object(s) != NO_ID);
  space_destroy(s);  
}

void test3_space_get_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_object(s) == NULL);
}

void test1_space_get_north() {
  Space *s;
  Link* link = link_create (0);
  
  s = space_create(5);


  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 4);


  space_set_north(s, link);
  PRINT_TEST_RESULT(space_get_north(s) == 4);
  space_destroy(s);
}

void test2_space_get_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT( space_get_north(s) == NO_ID);
}

void test1_space_get_south() {
  Space *s;
  Link* link = link_create (0);
  
  s = space_create(5);


  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 2);
  space_set_south(s, link);
  PRINT_TEST_RESULT(space_get_south(s) == 2);
  link_destroy(link);
  space_destroy(s);
}

void test2_space_get_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

void test1_space_get_east() {
  Space *s;
  Link* link = link_create (0);
  
  s = space_create(5);


  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 1);
  space_set_east(s, link);
  PRINT_TEST_RESULT(space_get_east(s) == 1);
  link_destroy(link);
  space_destroy(s);
}

void test2_space_get_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

void test1_space_get_west() {
  Space *s;
  Link* link = link_create (0);
  
  s = space_create(5);


  link_setIdSpace1 (link, space_get_id (s));
  link_setIdSpace2 (link, 6);
  space_set_west(s, link);
  PRINT_TEST_RESULT(space_get_west(s) == 6);
  space_destroy(s);
}

void test2_space_get_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}
