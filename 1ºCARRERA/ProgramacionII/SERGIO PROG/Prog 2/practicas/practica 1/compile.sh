#!/bin/dash
#.sh por Sergio Hidalgo y Miguel Ibáñez

#Con este primer comando se compila el archivo vertex.c
gcc -c -Wall -pedantic -ansi -g vertex.c

#Con este el graph.c
gcc -c -Wall -pedantic -ansi -g graph.c

#Con este el p1_e1.c 
gcc -c -Wall -pedantic -ansi -g p1_e1.c

#Con este el p1_e2.c 
gcc -c -Wall -pedantic -ansi -g p1_e2.c

#Con este el p1_e3.c
gcc -c -Wall -pedantic -ansi -g p1_e3.c

#Se enlazan ambos archivos .o y se crea el ejecutable del p1_e1
gcc -Wall -pedantic -ansi -g vertex.o p1_e1.o -o p1_e1_exe

#Se enlazan ambos archivos .o y se crea el ejecutable del p1_e2
gcc -Wall -pedantic -ansi -g vertex.o graph.o p1_e2.o -o p1_e2_exe

#Se enlazan ambos archivos .o y se crea el ejecutable del p1_e2
gcc -Wall -pedantic -ansi -g vertex.o graph.o p1_e3.o -o p1_e3_exe

#Por último se borran los archivos .o
rm -f *.o
