#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"


int add_inicio(char *name, char *fit, databook *book, Array_indice *array){

    indexbook *book_aux = NULL;

    int i = 0, aux = 0;

      if(name == NULL || fit == NULL || array == NULL)
    {
        return -1;
    }
    
    book_aux = indexbook_init();

    i = add_search(array, book->book_id);
    if ( i == -2){
        free(book_aux);
        return -1;
    }

    if ( i != -1){
        printf( "Record with BookID=%d exist.", book->book_id);
        free(book_aux);
        return 0;
    }


        aux = book->book_id;
    
        book_aux->key = book->book_id;

        book_aux->size = book->size;
        
        book_aux->offset = add_data_file_first(name, array, book);

        if ( book_aux->offset == -2){

            free(book_aux);

            return -1;
        }
        if (insert_array(array, book_aux) == -1){

            free(book_aux);

            return -1;
        }

        printf("Record with BookID=%d has been added to the database", aux);
        free(book_aux);
        return 0;

return -1;

}

int add_data_file_first(char *name, Array_indice *array, databook *book){

    long offset = -1;
    int i=0;
    FILE *file = NULL;

    file = fopen(name, "ab");
    if(file == NULL){
        return -2;
    }
 
        for(i = 0; i<(int)array->use ; i++){
            if((long)(array->book_ind[i]->offset + array->book_ind[i]->size + 8 ) > offset){

            offset = array->book_ind[i]->offset + array->book_ind[i]->size + 8;

            }
        }

        if (offset == -1)
        {
            offset = 0;
        }
        
    
    fseek(file, offset, SEEK_SET);


    fwrite(&book->book_id, 4, 1, file);
    fwrite(book->isbn, 16, 1, file);
    fwrite(book->title, strlen(book->title), 1, file);
    fwrite(book->printedBy, strlen(book->printedBy), 1, file);


    fclose(file);

    return offset;
    
}


int add_search(Array_indice *array_indice, int book_id){

    int i = 0;
    int B = 0;
    int L = array_indice-> use - 1;

    if(L == -1){

        return -1;
    }

    if(array_indice == NULL || B > L || book_id < 0)
    {
        return -2;
    }

    while(B<=L){
        
        i = B + (L-B)/2;

        if(array_indice->book_ind[i]->key == book_id && array_indice-> book_ind[i] != NULL)
        {
            return i;
        }
         
        if(array_indice->book_ind[i] == NULL || array_indice->book_ind[i]->key < book_id)
        {
            B = i +1;
        }
        else{
            L = i -1;
        }
    }

    return -1;
}

