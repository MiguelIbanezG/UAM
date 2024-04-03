Cflag = -pthread -ansi -Wall -pedantic -g


all: file clock thread_example proc_example proc_malloc proc_exec file_descriptors file_buffer pipe_example

file: file.o
	gcc $(Cflag) -o file file.o	

file.o: file.c
	gcc $(Cflag) -c file.c


clock: clock.o
	gcc $(Cflag) -o clock clock.o	

clock.o: clock.c
	gcc $(Cflag) -c clock.c


thread_example: thread_example.o
	gcc $(Cflag) -o thread_example thread_example.o	

thread_example.o: thread_example.c
	gcc $(Cflag) -c thread_example.c


proc_example: proc_example.o
	gcc $(Cflag) -o proc_example proc_example.o	

proc_example.o: proc_example.c
	gcc $(Cflag) -c proc_example.c


proc_malloc: proc_malloc.o
	gcc $(Cflag) -o proc_malloc proc_malloc.o	

proc_malloc.o: proc_malloc.c
	gcc $(Cflag) -c proc_malloc.c


proc_exec: proc_exec.o
	gcc $(Cflag) -o proc_exec proc_exec.o	

proc_exec.o: proc_exec.c
	gcc $(Cflag) -c proc_exec.c


file_descriptors: file_descriptors.o
	gcc $(Cflag) -o file_descriptors file_descriptors.o	

file_descriptors.o: file_descriptors.c
	gcc $(Cflag) -c file_descriptors.c


file_buffer: file_buffer.o
	gcc $(Cflag) -o file_buffer file_buffer.o	

file_buffer.o: file_buffer.c
	gcc $(Cflag) -c file_buffer.c


pipe_example: pipe_example.o
	gcc $(Cflag) -o pipe_example pipe_example.o	

pipe_example.o: pipe_example.c
	gcc $(Cflag) -c pipe_example.c

clean_objets:
	rm *.o

clean_programm:
	rm thread_example | rm file | rm proc_example | rm proc_malloc | rm clock | rm proc_exec | rm file_descriptors | rm file_buffer | rm pipe_example 

clean: clean_objets clean_programm
	