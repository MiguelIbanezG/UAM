#!/bin/bash
declare -A arraya
declare -A arrayb
declare -A arrayc
read -p "Introduce the number of rows: " row
read -p "Introduce the number of columns: " column
echo "The sum of this two matrix "
for ((i=0; i<row; i++))
do 
	for ((j=0; j<column; j++))
	do 
	arraya[$i,$j]=$(($RANDOM%100)) 
	echo -n "${arraya[$i,$j]} "
	done
echo
done
echo 
for ((i=0; i<row; i++))
do 
	for ((j=0; j<column; j++))
	do 
	arrayb[$i,$j]=$(($RANDOM%100)) 
	echo -n "${arrayb[$i,$j]} "
	done
	echo
done
echo
echo " is "
echo
for ((i=0; i<row; i++))
do 
	for ((j=0; j<column; j++))
	do 
	arrayc[$i,$j]=$((${arraya[$i,$j]} + ${arrayb[$i,$j]}))
	echo -n "${arrayc[$i,$j]}  "
	done
echo
done
