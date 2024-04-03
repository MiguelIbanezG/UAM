#include <stdio.h>
#include<string.h>
#define MAX 6

int main(){
 int i;
 char vector[MAX];
 printf("Please, introduce the vector of %d elements: ",MAX);
    scanf("%s",vector); 
 printf("The new vector is:");
    for(i=strlen(vector)-1;i>=0;i--){
        printf("%c",vector[i]);
    } 
return 0;
}