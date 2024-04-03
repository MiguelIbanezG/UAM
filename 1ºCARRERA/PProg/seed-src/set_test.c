/** 
 * @brief Define los jugadores
 * del juego
 * 
 * 
 * @file player.h
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 25-02-2021
 * Editado y comentado por: Miguel Ibáñez 
 */
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

/*Test de los sets*/
int main()
{

    Set *set1, *set2;

    Id id1 = 1, id2 = 2, id3 = 3;

    set1 = set_create();

    set2 = set_create();

    set_add_id(set1, id1);
    set_add_id(set1, id2);
    set_add_id(set1, id3);

    set_add_id(set2, id1);
    set_add_id(set2, id2);
    
    set_del_id(set1, id1);
    set_del_id(set2, id2);


    printf ("El set1 tiene el id %ld en la posición %d\n", set_findId(set1, set_getnIds (set1)-1), set_getnIds (set1)-1);
    printf ("El set1 tiene el id %ld en la posición %d\n", set_findId(set2, set_getnIds (set2)-1), set_getnIds (set2)-1);

    
    
    if (set_Idcheck(set1, id3) == TRUE)
    {
       printf("El id3 está en el set1\n");
    }
    else
    {
        printf("El id3 no está en el set1\n");

    }
    
    
    if (set_Idcheck(set2, id3) == TRUE)
    {
       printf("El id3 está en el set2\n");
    }
    else
    {
        printf("El id3 no está en el set2\n");

    }
       

    printf("Set1");
    set_print(set1);

    printf("Set2");
    set_print(set2);


    set_destroy(set1);
    set_destroy(set2);

    return 0;
}