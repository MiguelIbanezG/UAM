#!/bin/bash

N_employees=0
N_hours=0
N_days=0
priceperhour=0
salary=0
budget=0
i=0

read -p "How many employees are working: " N_employees
read -p "What is the salary per hour: " priceperhour
for ((i=0,salary=0; i<N_employees; i++))
do
	read -p  "How many days the employee work in a week?" N_hours
	read -p  "How many hours the employee work per day?" N_days
	let salary=N_days*N_hours*priceperhour
	let budget=budget+salary
done
	echo "The company pays for the $N_employees employees: $budget."
