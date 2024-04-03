#!/bin/bash

MAX=10
i=1
number=0
addition=0
for ((i=0; i<MAX; i++))
do
	read -p "Please, introduce a number:" number
	let addition=addition+number
       
done
	echo "The addition of all numbers is $addition"

