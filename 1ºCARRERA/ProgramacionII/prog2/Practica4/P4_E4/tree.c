#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "tree.h"

extern int errno;

#define info(pnodo) ((pnodo)->info)
#define right(pnodo) ((pnodo)->right)
#define left(pnodo) ((pnodo)->left)
#define root(pt) ((pt)->root)

typedef struct _NodeBT {
    void* info;
    struct _NodeBT* left;
    struct _NodeBT* right;
} NodeBT;

struct _Tree {
    NodeBT *root;

    destroy_elementtree_function_type destroy_element_function;
    copy_elementtree_function_type copy_element_function;
    print_elementtree_function_type print_element_function;
    cmp_elementtree_function_type cmp_element_function;
};

NodeBT *nodeBT_ini();
void nodeBT_free(NodeBT *pn, Tree *T);
void tree_free_rec(NodeBT *pn, Tree* T);
Status tree_insertar_rec(NodeBT **ppn, const void *pe, Tree* t);
int num_nodes_rec(NodeBT *pn);
int tree_depht_rec(NodeBT *pn);
Bool tree_find_rec(Tree* pa, NodeBT *pn, const void* pe);
Bool Node_esHoja(NodeBT *pn);

NodeBT *nodeBT_ini() {
    NodeBT *pn = NULL;

    pn = (NodeBT *) malloc(sizeof (NodeBT));
    if (!pn) return NULL;

    info(pn) = NULL;
    right(pn) = NULL;
    left(pn) = NULL;

    return pn;
}

void nodeBT_free(NodeBT *pn, Tree* T) {
    if (pn) {
        T->destroy_element_function(info(pn));
        free(pn);
    }
}

Tree* tree_ini(destroy_elementtree_function_type f1, copy_elementtree_function_type f2, print_elementtree_function_type f3, cmp_elementtree_function_type f4) {

    Tree *pa = NULL;

    pa = (Tree *) malloc(sizeof (Tree));
    if (!pa) return NULL;

    root(pa) = NULL;

    pa->destroy_element_function = f1;
    pa->copy_element_function = f2;
    pa->print_element_function = f3;
    pa->cmp_element_function = f4;


    return pa;


}

Bool tree_isEmpty(const Tree *pa) {

    if (!pa) {
        return TRUE;
    }

    if (!root(pa)) {
        return TRUE;
    }
    return FALSE;

}

void tree_free(Tree *pa) {
    if (!pa) return;

    tree_free_rec(root(pa), pa);

    free(pa);
}

void tree_free_rec(NodeBT *pn, Tree *T) {

    if (!pn) return;

    if (left(pn)) {
        tree_free_rec(left(pn), T);
    }
    if (right(pn)) {
        tree_free_rec(right(pn), T);
    }
    nodeBT_free(pn, T);
	return;
}

Status tree_insert(Tree *pa, const void *po) {
    NodeBT* pnaux;
    if (!pa || !po) return ERROR;

    if (root(pa) == NULL) {
        pnaux = nodeBT_ini();
        info(pnaux) = pa->copy_element_function(po);
        root(pa) = pnaux;
        return OK;
    }
    return tree_insertar_rec(&root(pa), po, pa);

}

Status tree_insertar_rec(NodeBT **ppn, const void *pe, Tree* t) {
    int cmp;

    if (*ppn == NULL) {
        *ppn = nodeBT_ini();
        if (*ppn == NULL) return ERROR;
        (*ppn)->info = t->copy_element_function(pe);
        if ((*ppn)->info == NULL) {
            nodeBT_free(*ppn, t);
            return ERROR;
        }
        return OK;
    }

    cmp = t->cmp_element_function(pe, info(*ppn));
    if (cmp < 0)
        return tree_insertar_rec(&left(*ppn), pe, t);
    if (cmp > 0)
        return tree_insertar_rec(&right(*ppn), pe, t);
    return OK;
}

int tree_depth(const Tree *pa) {
    if (!pa)return -1;

    return tree_depht_rec(root(pa)) - 1;

}

int tree_depht_rec(NodeBT *pn) {
    int a, b;
    if (!pn) return 0;
    if (Node_esHoja(pn) == TRUE)
        return 1;
    else {
        a = tree_depht_rec(left(pn));
        b = tree_depht_rec(right(pn));
        if (a < b) return b + 1;
        else return a + 1;

    }
}

int tree_numNodes(const Tree * pa) {

    if (!pa)return 0;

    return num_nodes_rec(root(pa));


}

int num_nodes_rec(NodeBT * pn) {
    int a, b;
    if (!pn) {
        return 0;
    }


    a = num_nodes_rec(left(pn));
    b = num_nodes_rec(right(pn));
    return (1 + a + b);
}

Bool tree_find(Tree* pa, const void* pe) {

    if (!pa || tree_numNodes(pa) == 0)return FALSE;

    return tree_find_rec(pa, root(pa), pe);


}

Bool tree_find_rec(Tree* pa, NodeBT *pn, const void* pe) {

    if (!pn)return FALSE;
    if (pa->cmp_element_function(info(pn), pe) == 0) return TRUE;
    else if (pa->cmp_element_function(info(pn), pe) > 0) return tree_find_rec(pa, left(pn), pe);
    else return tree_find_rec(pa, right(pn), pe);


}

Bool Node_esHoja(NodeBT *pn) {
    if (!pn)return FALSE;
    if (right(pn) == NULL && left(pn) == NULL)return TRUE;
    return FALSE;
}


Status tree_preOrder_rec(FILE *f, const Tree *pa, NodeBT *pn);

Status tree_preOrder(FILE *f, const Tree *pa) {
    if (f == NULL) return ERROR;

    return tree_preOrder_rec(f, pa, root(pa));
}

Status tree_preOrder_rec(FILE *f, const Tree *pa, NodeBT *pn) {
    if (!pn) return OK;
    pa->print_element_function(f, info(pn));

    tree_preOrder_rec(f, pa, left(pn));

    tree_preOrder_rec(f, pa, right(pn));


    return OK;
}


Status tree_postOrder_rec(FILE *f, const Tree *pa, NodeBT *pn);

Status tree_postOrder(FILE *f, const Tree *pa) {
    if (f == NULL) return ERROR;

    return tree_postOrder_rec(f, pa, root(pa));

}

Status tree_postOrder_rec(FILE *f, const Tree *pa, NodeBT *pn) {
    if (!pn) return OK;

    if (left(pn)) {
        tree_postOrder_rec(f, pa, left(pn));
    }
    if (right(pn)) {
        tree_postOrder_rec(f, pa, right(pn));
    }
    pa->print_element_function(f, info(pn));

    return OK;
}

Status tree_inOrder_rec(FILE *f, const Tree *pa, NodeBT *pn);

Status tree_inOrder(FILE *f, const Tree *pa) {
    if (f == NULL) return ERROR;

    return tree_inOrder_rec(f, pa, root(pa));

}

Status tree_inOrder_rec(FILE *f, const Tree *pa, NodeBT *pn) {
    if (!pn) return OK;


    if (left(pn)) {
        tree_inOrder_rec(f, pa, left(pn));
    }
    pa->print_element_function(f, info(pn));
    if (right(pn)) {
        tree_inOrder_rec(f, pa, right(pn));
    }


    return OK;
}
