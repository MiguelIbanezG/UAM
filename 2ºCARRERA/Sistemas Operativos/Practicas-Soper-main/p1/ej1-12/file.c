#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *f = NULL;

    if (argc != 2)
    {
        perror("Input/output error");
        exit(EXIT_FAILURE);   
    }
    
    f = fopen (argv[1], "r");
    if (f == NULL)
    {
        perror("fopen");
        exit(EXIT_SUCCESS);   
    }
    
    fclose(f);

    exit(EXIT_SUCCESS);   
}