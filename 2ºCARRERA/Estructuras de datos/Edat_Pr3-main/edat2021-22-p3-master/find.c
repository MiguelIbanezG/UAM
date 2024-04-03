#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"


char *find_inicio(Array_indice *array_indice, char *name, int id){

    char *cad, cad1[TAMAN];
    int i=0, j=0,w=0;
    FILE *file = NULL;
    databook *book_aux = NULL;
    size_t size = 0;

    if(array_indice == NULL || name == NULL)
    {
        return NULL;
    }

    cad = (char *)calloc(TAMAN, sizeof(char));
    if(cad == NULL)
    {
        return NULL;
    }

    i =  add_search(array_indice,id);
    if(i == -1)
    {
        return NULL;
    }

    file = fopen(name, "rb");
    if(file == NULL)
    {
        file =  fopen(name, "wb");
        fclose(file);
        return NULL;
    }

    book_aux = databook_init();
     if(book_aux == NULL)
    {
        free(book_aux);
        fclose(file);
        return NULL;
    }

     if(i != -2)
    {
        size = 0;
        
        fseek(file,array_indice->book_ind[i]->offset, SEEK_SET);
        fread(&book_aux->size,8, 1, file);

        size = sizeof(book_aux->size);

        fread(&book_aux->book_id,4, 1, file);

        size += sizeof(book_aux->book_id);

        fread(&book_aux->isbn,16, 1, file);

        size += sizeof(book_aux->isbn);

        fread(cad,array_indice->book_ind[i]->size, 1, file);

        for(j=0; cad1[j] != '|'; j++){

             book_aux->title[j] = cad1[j];

        }

        book_aux->title[j] = '\0';
        size += strlen(book_aux->title);

       for(w=0; (w + size) < array_indice->book_ind[i]->size ;j++, w++){

            book_aux->printedBy[w] = cad1[j];

        }
      
        sprintf(cad, "\n%d|%s|%s|%s\n", book_aux->book_id, book_aux->isbn,book_aux->title, book_aux->printedBy);

        databook_free(book_aux);
        fclose(file);

        return cad;
    }

    free(book_aux);
    fclose(file);

    printf("Record with BookID=%d does not exists" , id);

    return cad;

}

int find_read(char *tok){

    if(tok == NULL )
    {
        return -1;
    }
    
    tok = strtok(NULL, " ");

    return atol(tok);
}