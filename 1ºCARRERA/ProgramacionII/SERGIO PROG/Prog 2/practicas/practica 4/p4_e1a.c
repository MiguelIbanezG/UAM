#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "types.h"
#include "bstree.h"

int print_ele (FILE *pf, const void* ele)
{
    fprintf (stdout, "\n%d\n", *(int*)ele);

    return 0;
}

int cmp_ele (const void *ele1, const void *ele2)
{
    if (ele1 == ele2)
    {
        return 0;
    }
    else if (ele1 > ele2)
    {
        return 1;
    }
    else if (ele1 < ele2)
    {
        return -1;
    }

    return -1;
}

int main ()
{
    BSTree *pa = NULL;

    void *ele1 = (void*)1, *ele2 = (void*)2, *ele3 = (void*)3, *ele4 = (void*)4, *ele5 = (void*)5;

    pa = tree_init(print_ele, cmp_ele);


    if (tree_insert (pa, ele5) == ERROR)
    {
        return -1;
    }
    if (tree_insert (pa, ele3) == ERROR)
    {
        return -1;
    }
    if (tree_insert (pa, ele1) == ERROR)
    {
        return -1;
    }
    if (tree_insert (pa, ele4) == ERROR)
    {
        return -1;
    }
    if (tree_insert (pa, ele2) == ERROR)
    {
        return -1;
    }

    if (tree_contains (pa, ele1))
    {
        printf ("\nContiene 1\n");
    }
    else
    {
        printf ("\nNo contiene 1\n");

    }

    if (tree_contains (pa, ele2))
    {
        printf ("\nContiene 2\n");
    }
    else
    {
        printf ("\nNo contiene 2\n");

    }
 
    if (tree_contains (pa, ele3))
    {
        printf ("\nContiene 3\n");
    }
    else
    {
        printf ("\nNo contiene 3\n");

    }

    if (tree_contains (pa, ele4))
    {
        printf ("\nContiene 4\n");
    }
    else
    {
        printf ("\nNo contiene 4\n");

    }

    if (tree_contains (pa, ele5))
    {
        printf ("\nContiene 5\n");
    }
    else
    {
        printf ("\nNo contiene 5\n");

    }

    printf ("\nMin: ");

    print_ele (stdout, tree_find_min (pa));

    printf ("\nMax: ");

    print_ele (stdout, tree_find_max (pa));


    tree_destroy (pa);

    return 0;
}