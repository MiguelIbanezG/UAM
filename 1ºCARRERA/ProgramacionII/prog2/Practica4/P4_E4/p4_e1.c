#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "tree.h"
#include "char.h"

#define MAX_NAME 350

void main_clean(Tree *pa, FILE *f);

void main(int argc, char **argv) {
    FILE *f;
    char name[MAX_NAME];
    Tree * pa = NULL;


    f = fopen(argv[1], "r");
    if (!f) {
        main_clean(pa, f);
        return;
    }

    pa = tree_ini(char_destroy, char_copy, char_print, char_cmp);

    if (pa == NULL) {
        main_clean(pa, f);
        return;
    }

    while (fscanf(f, "%s", name) == 1) {
        tree_insert(pa, &name);
    }
    fprintf(stdout, "Número de nodos: %d.\n", tree_numNodes(pa));
    fprintf(stdout, "Profundidad: %d\n", tree_depth(pa));

    printf("\nOrden previo: ");
    tree_preOrder(stdout, pa);

    printf("\nOrden medio: ");
    tree_inOrder(stdout, pa);

    printf("\nOrden posterior: ");
    tree_postOrder(stdout, pa);

    fprintf(stdout, "\nIntroduce una cadena para buscar en el árbol (siguiendo el mismo formato que en el fichero de entrada): ");
    scanf("%s", name);
    fprintf(stdout, "\nCadena introducida: %s.\n", name);

    if (tree_find(pa, name) == TRUE) {
        printf("%s se encuentra dentro del árbol.", name);
    } else
        printf("%s no se encuentra dentro del árbol.", name);

    main_clean(pa, f);
    return;
}

void main_clean(Tree *pa, FILE *f) {
    tree_free(pa);
    fclose(f);
    return;
}
