#include <stdio.h>
#define MAX 10

int main(){
 int number[MAX],i,sum=0;
    for(i=0;i<MAX;i++){
        printf("Please, introduce number %d: ",i+1);
            scanf("%d",&number[i]);
        sum+=number[i];
    }
 printf("The sum of the %d numbers is: %d",MAX,sum);
return 0;
}
 