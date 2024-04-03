#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "tree.h"
#include "int.h"


void main_clean(Tree *pa, FILE *f);

void main(int argc, char **argv) {
    FILE *f;
    int num;
    Tree * pa = NULL;


    f = fopen(argv[1], "r");
    if (!f) {
        main_clean(pa, f);
        return;
    }

    pa = tree_ini(int_destroy, int_copy, int_print, int_cmp);

    if (pa == NULL) {
        main_clean(pa, f);
        return;
    }

    while (fscanf(f, "%d", &num) == 1) {
        tree_insert(pa, &num);
    }
    fprintf(stdout, "Número de nodos: %d.\n", tree_numNodes(pa));
    fprintf(stdout, "Profundidad: %d\n", tree_depth(pa));

    printf("\nOrden previo: ");
    tree_preOrder(stdout, pa);

    printf("\nOrden medio: ");
    tree_inOrder(stdout, pa);

    printf("\nOrden posterior: ");
    tree_postOrder(stdout, pa);

    fprintf(stdout, "\nIntroduzca un número: ");
    scanf("%d", &num);
    fprintf(stdout, "Número introducido: %d.\n", num);

    if (tree_find(pa, &num) == TRUE) {
        printf("El dato %d se encuentra dentro del árbol.", num);
    } else
        printf("El dato %d no se encuentra dentro del árbol.", num);

    main_clean(pa, f);
    return;
}

void main_clean(Tree *pa, FILE *f) {
    tree_free(pa);
    fclose(f);
    return;
}
