#! /bin/bash
declare -A matrix
num_rows=4
num_columns=4

for ((i=1;i<=num_rows;i++))
do
    for ((j=1;j<=num_columns;j++))
    do
        echo "Enter matrix[$i,$j]"
        read matrix[${i},${j}]
	if ((${matrix[$i,$j]} > 9)) || ((${matrix[$i,$j]} < 0))
	   then
	      j=$j-1
	    fi
    done
done
counter=0
for ((i=1;i<=num_rows;i++)) do
    for ((j=1;j<=num_columns;j++)) do
if [ "${matrix[$i,$j]}" -eq 0 ]; 
then 
 let counter++
fi
done
done
for ((i=1;i<=num_rows;i++)) do
    for ((j=1;j<=num_columns;j++)) do
     echo -n ${matrix[$i,$j]} 
    done
    echo
done

echo "The number of 0 in the matrix is: $counter"



