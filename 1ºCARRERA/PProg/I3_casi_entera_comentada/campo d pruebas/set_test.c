/** 
 * @brief Testea la funcionalidad de
 * set.c
 * 
 * 
 * @file set_test.c
 * @author Ignacio González
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Ignacio González 
 */
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/*Test de los sets*/
int main()
{

    Set *s;

    s = set_create();

    if (!s){
        printf ("La función set_create falla.\n");
    }
    else if (set_getnIds(s) == 0){
        printf ("La función set_create es funciona correctamente.\n");
    }

    if (set_add_id(s, 1) == ERROR){
        printf ("La función set_add_id falla.\n");
    }
    else if (set_findId(s, set_getnIds(s)) == 1 && set_Idcheck(s, 1) == TRUE){
        printf ("La función set_add_id funciona correctamente.\n");
    }

    if (set_del_id(s, 1) == ERROR && set_Idcheck(s, 1) == TRUE){
        printf ("La función set_del_id falla.\n");
    }
    else if(set_Idcheck(s, 1) == FALSE && set_findId(s, 1) == NO_ID){
        printf ("La función set_del_id funciona correctamente.\n");
    }

    printf ("Expected print:--> Set (nIds: %d ids: %ln).\n", set_getnIds(s), set_getArrayIds(s));

    printf ("Output print");

    set_print(s);

    if (set_destroy(s) == ERROR){
        printf ("La función set_destroy falla.\n");
    }
    else{
        printf ("La función set_destoy funciona correctamente.\n");
    }

    return 0;
}