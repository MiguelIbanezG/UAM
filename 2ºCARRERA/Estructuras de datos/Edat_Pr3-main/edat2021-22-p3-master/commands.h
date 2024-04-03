#include <stdio.h>
#include <stdlib.h>


#define TAMAN 128
#define PK_SIZE 100
#define BESTFIT 0
#define WORSTFIT 1
#define FIRSTFIT 2


typedef struct {
    int book_id; 
    char *title; 
    char *isbn; 
    char *printedBy;
    size_t size; 
}databook;

typedef struct {
    int key; /*book isbn */
    long int offset; /*book i s stored in disk at t h i s po si tio n */
    size_t size; /*book record s i z e . This i s a redundant field that helps in the implementation */
}indexbook;

typedef struct {
    size_t offset; 
    size_t register_size; 
}indexdeletedbook;

typedef struct {
    indexdeletedbook **book_del;
    size_t use; 
    size_t size; 
}Array_del;

typedef struct {
    indexbook **book_ind; 
    size_t use; 
    size_t size;
}Array_indice;



char *find_inicio(Array_indice *array_indice, char *name, int id);
int find_read(char *tok);

int add_inicio(char *name, char *fit, databook *book, Array_indice *array);
int add_data_file_first(char *name, Array_indice *array, databook *book);
int add_search(Array_indice *array_indice, int book_id);


indexbook *indexbook_init();
databook *databook_init();
indexdeletedbook *del_indexbook_init();
Array_del *init_array_delete(size_t size);
Array_indice *init_array_indice();


int insert_del_array (Array_del *array, indexdeletedbook *book);
int insert_array (Array_indice *array, indexbook *book);
void free_array(Array_indice *array_indice);
void databook_free(databook *book);

int print_ind(Array_indice *array);
int printRec(char *name, Array_indice *array);




      






                       

