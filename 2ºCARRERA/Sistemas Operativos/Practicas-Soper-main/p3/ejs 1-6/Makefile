C= gcc
CFLAGS = -Wall -ansi -pedantic -pthread -g 
LIBF = -lrt


all: file_truncate file_mmap shm_reader shm_writer mq_send_receive mq_sender mq_receptor clean_objs


file_truncate: file_truncate.o
	$(C) $(CFLAGS) -o file_truncate file_truncate.o $(LIBF)

file_truncate.o: file_truncate.c
	$(C) $(CFLAGS) -c file_truncate.c


file_mmap: file_mmap.o
	$(C) $(CFLAGS) -o file_mmap file_mmap.o $(LIBF)

file_mmap.o: file_mmap.c
	$(C) $(CFLAGS) -c file_mmap.c


shm_reader: shm_reader.o shm_rdwr.h
	$(C) $(CFLAGS) -o shm_reader shm_reader.o $(LIBF)

shm_reader.o: shm_reader.c shm_rdwr.h
	$(C) $(CFLAGS) -c shm_reader.c

shm_writer: shm_writer.o shm_rdwr.h
	$(C) $(CFLAGS) -o shm_writer shm_writer.o $(LIBF)

shm_writer.o: shm_writer.c shm_rdwr.h
	$(C) $(CFLAGS) -c shm_writer.c


mq_send_receive: mq_send_receive.o 
	$(C) $(CFLAGS) -o mq_send_receive mq_send_receive.o $(LIBF)

mq_send_receive.o: mq_send_receive.c 
	$(C) $(CFLAGS) -c mq_send_receive.c



mq_sender: mq_sender.o mq_sd_rc.h
	$(C) $(CFLAGS) -o mq_sender mq_sender.o $(LIBF)

mq_sender.o: mq_sender.c mq_sd_rc.h
	$(C) $(CFLAGS) -c mq_sender.c

mq_receptor: mq_receptor.o mq_sd_rc.h
	$(C) $(CFLAGS) -o mq_receptor mq_receptor.o $(LIBF)

mq_receptor.o: mq_receptor.c mq_sd_rc.h
	$(C) $(CFLAGS) -c mq_receptor.c


clean: clean_programs clean_objs

clean_objs:
	rm *.o

clean_programs:
	rm file_truncate | rm file_mmap | rm shm_reader | rm shm_writer | rm mq_send_receive | rm mq_sender | rm mq_receptor


