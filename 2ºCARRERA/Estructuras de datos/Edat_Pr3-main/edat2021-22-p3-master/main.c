#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

int main(int argc, char **argv)
{
  Array_indice *array_indice = NULL;
  databook *book_aux = NULL;
  char ind[TAMAN], lst[TAMAN], db[TAMAN], name[TAMAN], fit[TAMAN], comm[TAMAN];
  char *tok = NULL, *comm3 = NULL, *comm1 = NULL;

  if (argc != 3)
  {
    printf("\nMissing argument");
    return 0;
  }

  strcpy(fit, argv[1]);
  strcpy(name, argv[2]);

  if (strcmp(fit, "first_fit") != 0 && strcmp(fit, "best_fit") != 0 && strcmp(fit, "worst_fit") != 0)
  {
    printf("\nUnknown search strategy unknown_search_strategy");
    return 0;
  }

  comm1 = (char *)calloc(11, sizeof(char));
  if (comm1 == NULL)
  {
    printf("\nError\n");
    return 0;
  }

  book_aux = databook_init();
  if (book_aux == NULL)
  {

    printf("\nError with databook");
    return 0;
  }

  array_indice = init_array_indice();

  if (array_indice == NULL)
  {

    printf("\nError with indexbook");
    return 0;
  }

  strcpy(db, name);
  strcat(db, ".db");

  strcpy(ind, name);
  strcat(ind, ".ind");

  strcpy(lst, name);
  strcat(lst, ".lst");


  printf("\nType command and argument/s.");

  while (strcmp(comm1, "exit\n") != 0)
  {

    printf("\nexit\n");
    fgets(comm, TAMAN, stdin);

    if (strcmp(comm, "exit\n") == 0)
    {

      printf("all done\n");
      break;
    }

    tok = strtok(comm, " ");

    strcpy(comm1, tok);

    if (strcmp(comm1, "add") == 0)
    {

      tok = strtok(NULL, "|");

      book_aux->book_id = atol(tok);
      tok = strtok(NULL, "|");
      strcpy(book_aux->isbn, tok);
      strcat(book_aux->isbn, "\0");

      tok = strtok(NULL, "|");

      strcpy(book_aux->title, tok);
      strcat(book_aux->title, "|");

      tok = strtok(NULL, "\n");
      strcpy(book_aux->printedBy, tok);
      strcat(book_aux->printedBy, "\0");

      book_aux->size = sizeof(book_aux->book_id) + strlen(book_aux->isbn) + strlen(book_aux->title) + strlen(book_aux->printedBy);

      if (add_inicio(db, fit, book_aux, array_indice) == -1)
      {
        printf("\nError command add");
        break;
      }
    }

    if (strcmp(comm1, "find") == 0)
    {
      comm3 = find_inicio(array_indice, ind, find_read(tok));

      if (comm3 == NULL)
      {
        printf("\nError command find");
        break;
      }

      printf("\n%s\n", comm3);
      free(comm3);
    }

    if (strcmp(comm1, "printRec\n") == 0)
    {
      tok = strtok(NULL, "\n");

      if (printRec(db, array_indice) == -1)
      {
        printf("\nError command printRec");
        break;
      }

      printf("\n");
    }

    else if (strcmp(comm1, "printInd\n") == 0)
    {
      tok = strtok(NULL, "\n");

      if (print_ind(array_indice) == -1)
      {
        printf("\nError command printInd");
        break;
      }

      printf("\n");
    }
  }

  databook_free(book_aux);

  free_array(array_indice);

  free(comm1);

  return 0;
}

databook *databook_init()
{
  databook *book_dat = NULL;

  book_dat = (databook *)malloc(sizeof(databook));

  if (book_dat == NULL)
  {

    return NULL;
  }

  book_dat->size = 0;
  book_dat->book_id = 0;
  book_dat->isbn = (char *)calloc(17, sizeof(char));
  book_dat->printedBy = (char *)calloc(TAMAN, sizeof(char));
  book_dat->title = (char *)calloc(TAMAN, sizeof(char));

  return book_dat;
}

indexbook *indexbook_init()
{

  indexbook *book_indice = NULL;

  book_indice = (indexbook *)malloc(sizeof(indexbook));

  if (book_indice == NULL)
  {

    return NULL;
  }

  book_indice->size = 0;
  book_indice->key = 0;
  book_indice->offset = -1;

  return book_indice;
}

indexdeletedbook *del_indexbook_init()
{

  indexdeletedbook *indice_del = NULL;

  indice_del = (indexdeletedbook *)malloc(sizeof(indexdeletedbook));

  if (indice_del == NULL)
  {

    return NULL;
  }

  indice_del->register_size = 0;
  indice_del->offset = -1;

  return indice_del;
}
