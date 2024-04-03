#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"


int print_ind(Array_indice *array){

    int i;

    if(array==NULL){
        return -1;
    }

    for(i=0;i<(int)array->use;i++){

        printf("Entry #%d\n    key: #%d\n    offset: #%ld\n    size: #%ld\n", i, array->book_ind[i]->key, array->book_ind[i]->offset, array->book_ind[i]->size);

    }

    return 0;
}

int printRec(char *name, Array_indice *array){

    FILE *file;
    databook *book_aux;
    int i,j,w;
    char cad[TAMAN]= "\0";
    size_t size;


    if(array==NULL|| name == NULL){
        return -1;
    }

    file = fopen(name, "rb");
    if(file == NULL){
        file = fopen(name, "wb");
        fclose(file);

        return 0;
    }

    book_aux = databook_init();

    for(i=0;i<(int)array->use;i++){
        size =0;
        fseek(file,array->book_ind[i]->offset, SEEK_SET);
        fread(&book_aux->size,8, 1, file);
        size = sizeof(book_aux->size);
        fread(&book_aux->book_id,4, 1, file);
        size += sizeof(book_aux->book_id);
        fread(&book_aux->isbn,16, 1, file);
        size += sizeof(book_aux->isbn);
        fread(cad,array->book_ind[i]->size, 1, file);



        for (j = 0; cad[j] != '|'; j++)
        {
            book_aux->title[j] = cad[j];
        }

        size += strlen(book_aux->title);


        for(w=0; (w + size) < array->book_ind[i]->size ;j++, w++){

            book_aux->printedBy[w] = cad[j];

        }

        printf("%d|%s|%s%s", book_aux->book_id, book_aux->isbn, book_aux->title, book_aux->printedBy);

    }

    free(book_aux);
    fclose(file);

    return 0;
}

