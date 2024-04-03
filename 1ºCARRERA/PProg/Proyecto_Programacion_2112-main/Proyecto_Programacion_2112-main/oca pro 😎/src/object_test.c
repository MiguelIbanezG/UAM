#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include "test.h"
#include "object_test.h"

#define MAX_TESTS 41
#define EXIT_SUCCESS 0

int main(int argc, char **argv)
{

    int test = 0;
    int all = 1;

    if (argc < 2)
    {
        printf("Running all test for module Space:\n");
    }
    else
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS)
        {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1)
        test1_object_create();
    if (all || test == 2)
        test2_object_create();
    if (all || test == 3)
        test3_object_create();
    if (all || test == 4)
        test1_object_setDescription();
    if (all || test == 5)
        test2_object_setDescription();
    if (all || test == 6)
        test3_object_setDescription();
    if (all || test == 7)
        test1_object_set_name();
    if (all || test == 8)
        test2_object_set_name();
    if (all || test == 9)
        test3_object_set_name();
    if (all || test == 10)
        test1_object_get_id();
    if (all || test == 11)
        test2_object_get_id();
    if (all || test == 12)
        test1_object_getDescription();
    if (all || test == 13)
        test2_object_getDescription();
    if (all || test == 14)
        test1_object_get_name();
    if (all || test == 15)
        test2_object_get_name();
    if (all || test == 16)
        test1_object_Idcheck();
    if (all || test == 17)
        test2_object_IdCheck();
    if (all || test == 18)
        test3_object_IdCheck();
    if (all || test == 19)
        test1_object_set_movable();
    if (all || test == 20)
        test2_object_set_movable();
    if (all || test == 21)
        test3_object_set_movable();
    if (all || test == 22)
        test1_object_get_movable();
    if (all || test == 23)
        test2_object_get_movable();
    if (all || test == 24)
        test1_object_set_dependency();
    if (all || test == 25)
        test2_object_set_dependency();
    if (all || test == 26)
        test3_object_set_dependency();
    if (all || test == 27)
        test1_object_get_dependency();
    if (all || test == 28)
        test2_object_get_dependency();
    if (all || test == 29)
        test1_object_set_open();
    if (all || test == 30)
        test2_object_set_open();
    if (all || test == 31)
        test3_object_set_open();
    if (all || test == 32)
        test1_object_get_open();
    if (all || test == 33)
        test2_object_get_open();
    if (all || test == 34)
        test1_object_set_illuminate();
    if (all || test == 35)
        test2_object_set_illuminate();
    if (all || test == 36)
        test1_object_get_illuminate();
    if (all || test == 37)
        test2_object_get_illuminate();
    if (all || test == 38)
        test1_object_set_turnedon();
    if (all || test == 39)
        test2_object_set_turnedon();
    if (all || test == 40)
        test1_object_get_turnedon();
    if (all || test == 41)
        test2_object_get_turnedon();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_object_create()
{
    Object *o;
    int result;

    o = object_create(5);
    result = o != NULL;
    PRINT_TEST_RESULT(result);
    object_destroy(o);
}

void test2_object_create()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_get_id(o) == 5);
    object_destroy(o);
}

void test3_object_create()
{

    PRINT_TEST_RESULT(object_create(NO_ID) == NULL);
}

void test1_object_setDescription()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_setDescription(o, "libro") == OK);
    object_destroy(o);
}

void test2_object_setDescription()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_setDescription(o, NULL) == ERROR);
    object_destroy(o);
}

void test3_object_setDescription()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_setDescription(o, "libro") == ERROR);
}

void test1_object_set_name()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, "libro") == OK);
    object_destroy(o);
}

void test2_object_set_name()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
    object_destroy(o);
}

void test3_object_set_name()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_set_name(o, "libro") == ERROR);
}

void test1_object_get_id()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_get_id(o) == 5);
    object_destroy(o);
}

void test2_object_get_id()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_id(o) == NO_ID);
}

void test1_object_getDescription()
{
    Object *o;

    o = object_create(5);
    object_setDescription(o, "libro");
    PRINT_TEST_RESULT(strcmp(object_getDescription(o), "libro") == 0);
    object_destroy(o);
}

void test2_object_getDescription()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_getDescription(o) == NULL);
}

void test1_object_get_name()
{
    Object *o;

    o = object_create(5);
    object_set_name(o, "libro");
    PRINT_TEST_RESULT(strcmp(object_get_name(o), "libro") == 0);
    object_destroy(o);
}

void test2_object_get_name()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_name(o) == NULL);
}

void test1_object_Idcheck()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_Idcheck(o, 5) == TRUE);
    object_destroy(o);
}

void test2_object_IdCheck()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_Idcheck(o, 1) == FALSE);
    object_destroy(o);
}

void test3_object_IdCheck()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_Idcheck(o, 5) == FALSE);
}

void test1_object_set_movable()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_movable(o, 1) == OK);
    object_destroy(o);
}

void test2_object_set_movable()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_movable(o, 2) == ERROR);
    object_destroy(o);
}

void test3_object_set_movable()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_set_movable(o, 1) == ERROR);
}

void test1_object_get_movable()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_get_movable(o) == FALSE);
    object_destroy(o);
}

void test2_object_get_movable()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_movable(o) == FALSE);
}

void test1_object_set_dependency()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_dependency(o, 5) == OK);
    object_destroy(o);
}

void test2_object_set_dependency()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_dependency(o, NO_ID) == ERROR);
    object_destroy(o);
}

void test3_object_set_dependency()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_set_dependency(o, 5) == ERROR);
}

void test1_object_get_dependency()
{
    Object *o;

    o = object_create(5);
    object_set_dependency(o, 5);
    PRINT_TEST_RESULT(object_get_dependency(o) == 5);
    object_destroy(o);
}

void test2_object_get_dependency()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_dependency(o) == NO_ID);
}

void test1_object_set_open()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_open(o, 5) == OK);
    object_destroy(o);
}

void test2_object_set_open()
{
    Object *o = NULL;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_open(o, NO_ID) == ERROR);
    object_destroy(o);
}

void test3_object_set_open()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_set_open(o, 5) == ERROR);
}

void test1_object_get_open()
{
    Object *o;

    o = object_create(5);
    object_set_open(o, 5);
    PRINT_TEST_RESULT(object_get_open(o) == 5);
    object_destroy(o);
}

void test2_object_get_open()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_open(o) == NO_ID);
}

void test1_object_set_illuminate()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_set_illuminate(o, TRUE) == OK);
    object_destroy(o);
}

void test2_object_set_illuminate()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_set_illuminate(o, TRUE) == ERROR);
}

void test1_object_get_illuminate()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_get_illuminate(o) == FALSE);
    object_destroy(o);
}

void test2_object_get_illuminate()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_illuminate(o) == FALSE);
}

void test1_object_set_turnedon()
{
    Object *o;

    o = object_create(5);
    object_set_illuminate(o, TRUE);
    PRINT_TEST_RESULT(object_set_turnedon(o, 1) == OK);
    object_destroy(o);
}

void test2_object_set_turnedon()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_set_turnedon(o, 1) == ERROR);
}

void test1_object_get_turnedon()
{
    Object *o;

    o = object_create(5);
    PRINT_TEST_RESULT(object_get_turnedon(o) == FALSE);
    object_destroy(o);
}

void test2_object_get_turnedon()
{
    Object *o = NULL;

    PRINT_TEST_RESULT(object_get_turnedon(o) == FALSE);
}