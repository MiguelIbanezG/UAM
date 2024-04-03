#!/bin/bash
MAX=6
i=0
vector[MAX]=NULL
for ((i=1; $i<=6; i++))
do
    
    read -p "Please, introuduce the element $i of the array: " vector[$i]
done

echo "The new vector is: "
for ((i=6;$i>=0;i--))
do
    echo -n "${vector[$i]}"
done

