/*
*Título: Funciones tree, práctica 4, programación 2
*Grupo: viernes 2113
*Autores: Sergio Hidalgo y Miguel Ibáñez 
*/
#include <stdlib.h>
#include <stdio.h>
#include "bstree.h"
#include "vertex.h"

/* START [_BSTNode] */
typedef struct _BSTNode
{
    void *info;
    struct _BSTNode *left;
    struct _BSTNode *right;
} BSTNode;
/* END [_BSTNode] */

/* START [_BSTree] */
struct _BSTree
{
    BSTNode *root;
    P_tree_ele_print print_ele;
    P_tree_ele_cmp cmp_ele;
};
/* END [_BSTree] */

/*** BSTNode TAD private functions ***/
BSTNode *_bst_node_new()
{
    BSTNode *pn = NULL;

    pn = malloc(sizeof(BSTNode));
    if (!pn)
    {
        return NULL;
    }

    pn->left = pn->right = NULL;
    pn->info = NULL;
    return pn;
}

void _bst_node_free(BSTNode *pn)
{
    if (!pn)
        return;

    free(pn);
}

void _bst_node_free_rec(BSTNode *pn)
{
    if (!pn)
        return;

    _bst_node_free_rec(pn->left);
    _bst_node_free_rec(pn->right);
    _bst_node_free(pn);

    return;
}

int _bst_depth_rec(BSTNode *pn)
{
    int depthR, depthL;
    if (!pn)
        return 0;

    depthL = _bst_depth_rec(pn->left);
    depthR = _bst_depth_rec(pn->right);

    if (depthR > depthL)
    {
        return depthR + 1;
    }
    else
    {
        return depthL + 1;
    }
}

int _bst_size_rec(BSTNode *pn)
{
    int count = 0;
    if (!pn)
        return count;

    count += _bst_size_rec(pn->left);
    count += _bst_size_rec(pn->right);

    return count + 1;
}

int _bst_preOrder_rec(BSTNode *pn, FILE *pf, P_tree_ele_print print_ele)
{
    int count = 0;
    if (!pn)
        return count;

    count += print_ele(pf, pn->info);
    count += _bst_preOrder_rec(pn->left, pf, print_ele);
    count += _bst_preOrder_rec(pn->right, pf, print_ele);

    return count;
}

int _bst_inOrder_rec(BSTNode *pn, FILE *pf, P_tree_ele_print print_ele)
{
    int count = 0;
    if (!pn)
        return count;

    count += _bst_inOrder_rec(pn->left, pf, print_ele);
    count += print_ele(pf, pn->info);
    count += _bst_inOrder_rec(pn->right, pf, print_ele);

    return count;
}

int _bst_postOrder_rec(BSTNode *pn, FILE *pf, P_tree_ele_print print_ele)
{
    int count = 0;
    if (!pn)
        return count;

    count += _bst_postOrder_rec(pn->left, pf, print_ele);
    count += _bst_postOrder_rec(pn->right, pf, print_ele);
    count += print_ele(pf, pn->info);

    return count;
}

void *_bst_min(BSTNode *node)
{
    if (node == NULL) /*Si el nodo es nulo devuelve null*/
    {
        return NULL;
    }

    if (node->left == NULL) /*Si el siguiente es nulo, devuelve el nodo*/
    {
        return node;
    }

    return _bst_min(node->left); /*Si el siguiente no es nulo, se llama otra vez a la función*/
}

void *_bst_max(BSTNode *node)
{
    if (node == NULL) /*Si el nodo es nulo devuelve null*/
    {
        return NULL;
    }

    if (node->right == NULL) /*Si el siguiente es nulo, devuelve el nodo*/
    {
        return node;
    }

    return _bst_min(node->right); /*Si el siguiente no es nulo, se llama otra vez a la función*/
}

Bool _bst_contains(BSTNode *node, P_tree_ele_cmp cmp_ele, const void *ele)
{
    Bool st;

    if (cmp_ele == NULL || ele == NULL || node == NULL) /*Control de errores*/
    {
        return FALSE;
    }

    if (cmp_ele(node->info, ele) == 0) /*si es igual, devuelve TRUE*/
    {
        return TRUE;
    }
    else if (cmp_ele(node->info, ele) > 0) /*si el elemento es menor*/
    {
        st = FALSE;
        st = _bst_contains(node->left, cmp_ele, ele); /*Se llama a la función por la izquierda*/
        return st;
    }
    else if (cmp_ele(node->info, ele) < 0) /*si el elemento es mayor*/
    {
        st = FALSE;
        st = _bst_contains(node->right, cmp_ele, ele); /*Se llama a la función por la derecha*/
        return st;
    }

    return FALSE;
}

Status _bst_insert(BSTNode **node, const void *elem, P_tree_ele_cmp cmp_ele, P_tree_ele_print print_elem)
{

    if (*node == NULL) /*Si el nodo está libre, se llena con el elemento*/
    {
        *node = _bst_node_new();

        if (*node == NULL)
        {
            return ERROR;
        }

        (*node)->info = (void *)elem;

        return OK;
    }

    if (cmp_ele(elem, (*node)->info) < 0) /*Si es menor el elemento*/
    {
        return _bst_insert((&(*node)->left), elem, cmp_ele, print_elem); /*Irá por la izquierda*/
    }
    else if (cmp_ele(elem, (*node)->info) > 0) /*Si es mayor*/
    {
        return _bst_insert((&(*node)->right), elem, cmp_ele, print_elem); /*Irá por la derecha*/
    }
    else /*Si es igual, devolverá OK*/
    {
        return OK;
    }
}

BSTNode *_bst_remove(BSTNode *node, const void *elem, P_tree_ele_cmp cmp_ele)
{
    BSTNode *r = NULL, *aux = NULL;

    if (node == NULL || elem == NULL || cmp_ele == NULL)
    {
        return node;
    }

    if (cmp_ele(elem, node->info) < 0) /*Si es menor el elemento*/
    {
        node->left = _bst_remove(node->left, elem, cmp_ele); /*Irá por la izquierda*/
    }
    else if (cmp_ele(elem, node->info) > 0) /*Si es mayor*/
    {
        node->right = _bst_remove(node->right, elem, cmp_ele);   /*Irá por la derecha*/
    }
    else if (cmp_ele(node->info, elem) == 0) /*Si es igual, se comprobará el estado de los nodos para liberar la memoria*/
    {
        if (node->left == NULL && node->right == NULL)
        {
            _bst_node_free(node);
            return NULL;
        }
        else if (node->left == NULL && node->right)
        {
            r = node->right;
            _bst_node_free(node);
            return r;
        }
        else if (node->left && node->right == NULL)
        {
            r = node->left;
            _bst_node_free(node);
            return r;
        }
        else if (node->left && node->right)
        {
            aux = _bst_min(node->right);
            node->right = _bst_remove(node->right, aux->info, cmp_ele);
            return node;
        }
    }
    return node;
}

/*** BSTree TAD functions ***/
BSTree *tree_init(P_tree_ele_print print_ele, P_tree_ele_cmp cmp_ele)
{
    if (!print_ele || !cmp_ele)
        return NULL;

    BSTree *tree = malloc(sizeof(BSTree));
    if (!tree)
    {
        return NULL;
    }

    tree->root = NULL;
    tree->print_ele = print_ele;
    tree->cmp_ele = cmp_ele;

    return tree;
}

void tree_destroy(BSTree *tree)
{
    if (!tree)
        return;

    _bst_node_free_rec(tree->root);

    free(tree);
    return;
}

Bool tree_isEmpty(const BSTree *tree)
{
    if (!tree || !tree->root)
        return TRUE;
    return FALSE;
}

int tree_depth(const BSTree *tree)
{
    if (!tree)
        return -1;

    return _bst_depth_rec(tree->root);
}

size_t tree_size(const BSTree *tree)
{
    if (!tree)
        return -1;

    return _bst_size_rec(tree->root);
}

int tree_preOrder(FILE *f, const BSTree *tree)
{
    if (!f || !tree)
        return -1;

    return _bst_preOrder_rec(tree->root, f, tree->print_ele) + fprintf(f, "\n");
}

int tree_inOrder(FILE *f, const BSTree *tree)
{
    if (!f || !tree)
        return -1;

    return _bst_inOrder_rec(tree->root, f, tree->print_ele) + fprintf(f, "\n");
}

int tree_postOrder(FILE *f, const BSTree *tree)
{
    if (!f || !tree)
        return -1;

    return _bst_postOrder_rec(tree->root, f, tree->print_ele) + fprintf(f, "\n");
}

/**** TODO: find_min, find_max, insert, contains, remove ****/

void *tree_find_min(BSTree *tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        return NULL;
    }

    return _bst_min(tree->root);
}

void *tree_find_max(BSTree *tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        return NULL;
    }

    return _bst_max(tree->root);
}

Status tree_insert(BSTree *tree, const void *elem)
{

    if (tree == NULL || elem == NULL)
    {
        return ERROR;
    }

    return _bst_insert(&(tree->root), elem, tree->cmp_ele, tree->print_ele);
}

Bool tree_contains(BSTree *tree, const void *elem)
{

    if (tree == NULL || elem == NULL)
    {
        return FALSE;
    }

    return _bst_contains(tree->root, tree->cmp_ele, elem);
}

Status tree_remove(BSTree *tree, const void *elem)
{
    if (tree == NULL || elem == NULL)
    {
        return ERROR;
    }

    if (!tree_contains(tree, elem))
    {
        return OK;
    }

    _bst_remove(tree->root, elem, tree->cmp_ele);

    return OK;
}