#! /bin/bash
declare -A matrix
declare -A matrix2
declare -A matrix3
echo Enter number of rows
read num_rows
echo Enter number of columns
read num_columns

for ((i=1;i<=num_rows;i++)) do
    for ((j=1;j<=num_columns;j++)) do
        echo "Enter matrix1[$i,$j]"
        read matrix1[${i},${j}]
    done
done
for ((i=1;i<=num_rows;i++)) do
    for ((j=1;j<=num_columns;j++)) do
        echo "Enter matrix2[$i,$j]"
        read matrix2[${i},${j}]
    done
done
echo The sum of the matrix is: 
for ((i=1;i<=num_rows;i++)) do
    for ((j=1;j<=num_columns;j++)) do
        let matrix3[$i,$j]=${matrix1[$i,$j]}+${matrix2[$i,$j]}
     echo -n "${matrix3[$i,$j]} "
    done
    echo
done

