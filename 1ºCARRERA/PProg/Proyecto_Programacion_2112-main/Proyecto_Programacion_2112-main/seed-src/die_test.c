/** 
 * @brief Testea el funcionamiento del dado
 * 
 * @file die_test.c
 * @author Miguel Ibáñez
 * @version 1.0 
 * @date 20-03-2021 
 * Editado y comentado por: Miguel Ibáñez
 */
#include <stdio.h>
#include "die.h"

 int main(){
    Die *die;

    die = die_create(1, 1, 6);

    if (die && die_get_id(die) == 1 && die_get_min(die) == 1 && die_get_max(die) == 6){
        printf ("La función die_create es correcta.\n");
    }
    else {
        printf("La función die_create falla.\n");
    }

    if (die_roll(die)==-1 || die_roll(die)<1 || die_roll(die)>6){
        printf ("La funcion die_roll falla.\n");
    }
    else{
        printf ("La función die_roll es correcta. %d.\n", die_roll(die));
    }

    if (die_print(die) == -1){
        printf ("La función die_print falla.\n");
    }
    else{
        printf("La función die_print es correcta.\n");
    }

    if (die_destroy(die) == ERROR){
        printf ("La funcion die_destroy falla.\n");
    }
    else{
        printf("La función die_destroy es correcta.\n");
    }

    return 0;
 }