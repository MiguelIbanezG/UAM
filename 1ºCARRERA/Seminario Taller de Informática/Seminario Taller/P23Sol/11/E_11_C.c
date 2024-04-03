#include <stdio.h>

int main() {
int N_employees,N_hours,N_days,priceperhour,salary,budget=0,i;
printf("How many employees are working?");
    scanf("%d",&N_employees);
printf("What is the salary per hour?");
    scanf("%d",&priceperhour);
for(i=0,salary=0;i<N_employees;i++){
    printf("How many days the employee %d work in a week?",i+1);
        scanf("%d",&N_days);
    printf("How many hours the employee %d work per day?",i+1);
        scanf("%d",&N_hours);
    printf("The weekly salary for %d employee is of: %d€\n",i+1,salary=N_days*N_hours*priceperhour);
    budget+=salary;
                                   }
printf("The company pays for the %d employees: %d€.",N_employees,budget);

    return 0;
}