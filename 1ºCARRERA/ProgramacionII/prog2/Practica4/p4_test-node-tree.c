#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "types.h"
#include "tree.h"
#include "node.h"

extern int errno;

void main_free(Tree *pt, FILE *f, Node *ele);

void main(int argc, char** argv) {
    FILE *f = NULL;
    int id;
    char *name;
    Node *ele = NULL;
    Node *pn=NULL;
    Tree *pt = NULL;

    f = fopen(argv[1], "r");
    if (!f) {
        main_free(pt, f, ele);
        return;
    }

    pt = tree_ini(node_destroy, node_copy, node_print, node_cmp);
    if (!pt) {
        main_free(pt, f, ele);
        return;
    }

    while (fscanf(f, "%d %s", &id, name) == 2) {

        pn = node_ini();

        if (!pn) {

            main_free(pt, f, ele);
            return;
        }

        node_setId(pn, id);
        node_setName(pn, name);

        tree_insert(pt, pn);
        node_destroy(pn);
        pn = NULL;
    }

    printf("Número de nodos: %d.\n", tree_numNodes(pt));
    printf("Profundidad: %d.\n", tree_depth(pt));
    printf("Orden previo: ");
    tree_preOrder(stdout, pt);
    printf("\nOrden medio: ");
    tree_inOrder(stdout, pt);
    printf("\nOrden posterior: ");
    tree_postOrder(stdout, pt);

    printf("\nIntroduzca una Id: ");
    scanf("%d", &id);
    ele = node_ini();
    node_setId(ele, id);

    if (tree_find(pt, ele) == TRUE) {
        printf("El nodo de Id %d se encuentra en el árbol.\n", id);
        main_free(pt, f, ele);
        return;
    }
    printf("El nodo de Id %d no se encuentra en el árbol.\n", id);

    main_free(pt, f, ele);
    return;
}

void main_free(Tree *pt, FILE *f, Node *ele){
  tree_free(pt);
  pt = NULL;

  node_destroy(ele);
  ele = NULL;

  fclose(f);

}
