#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

Array_indice *init_array_indice()
{

    Array_indice *array_indice;
    int i;

    array_indice = (Array_indice *)malloc(sizeof(Array_indice));

    if (array_indice == NULL)
    {

        return NULL;
    }

    array_indice->book_ind = (indexbook **)calloc(1, sizeof(indexbook *));

    if (array_indice->book_ind == NULL)
    {

        return NULL;
    }

    for (i = 0; i < 1; i++)
    {

        array_indice->book_ind[i] = NULL;
    }

    array_indice->use = 0;
    array_indice->size = 1;

    return array_indice;
}

Array_del *init_array_delete(size_t size)
{

    int i = 0;
    Array_del *array_del;

    array_del = (Array_del *)malloc(sizeof(array_del));

    if (array_del == NULL)
    {

        return NULL;
    }

    array_del->book_del = (indexdeletedbook **)calloc(size, sizeof(indexdeletedbook));

    if (array_del->book_del == NULL)
    {

        return NULL;
    }

    for (i = 0; i < (int)size; i++)
    {

        array_del->book_del[i] = NULL;
    }

    array_del->use = 0;
    array_del->size = size;

    return array_del;
}

int insert_array(Array_indice *array, indexbook *book)
{

    int i = 0;
    indexbook *book_aux;

    book_aux = indexbook_init();

    if (array == NULL || book == NULL)
        return -1;

    if (array->use == array->size)
    {

        array->size = array->size;
        array->book_ind = (indexbook **)realloc(array->book_ind, array->size * sizeof(indexbook *));
    }

    for (i = 0; i < (int)array->use; i++)
    {

        if ((array->book_ind[i]->key) > (book->key))
        {

            memmove(book_aux, array->book_ind[i], sizeof(indexbook));
            memmove(array->book_ind[i], book, sizeof(indexbook));
            memmove(book, book_aux, sizeof(indexbook));
        }
    }

    array->book_ind[array->use] = indexbook_init();
    array->book_ind[array->use]->key = book->key;
    array->book_ind[array->use]->size = book->size;
    array->book_ind[array->use]->offset = book->offset;
    array->use++;

    free(book_aux);

    return 0;
}

int insert_del_array(Array_del *array, indexdeletedbook *book)
{

    if (array == NULL || book == NULL)
        return -1;

    if (array->use == array->size)
    {
        array->size = array->size * 2;
        array->book_del = (indexdeletedbook **)realloc(array->book_del, array->size * sizeof(indexdeletedbook *));
    }

    array->book_del[array->use] = del_indexbook_init();
    array->book_del[array->use]->register_size = book->register_size;
    array->book_del[array->use]->offset = book->offset;
    array->use++;

    return 0;
}

void databook_free(databook *book)
{
    free(book->isbn);
    free(book->title);
    free(book->printedBy);

    free(book);
}

void free_array(Array_indice *array_indice)
{
    int i = 0;

    if (array_indice == NULL)
    {
        return;
    }

    for (i = 0; i < (int)array_indice->use; i++)
    {

        free(array_indice->book_ind[i]);
    }

    free(array_indice->book_ind);

    array_indice->book_ind = NULL;

    free(array_indice);
}
