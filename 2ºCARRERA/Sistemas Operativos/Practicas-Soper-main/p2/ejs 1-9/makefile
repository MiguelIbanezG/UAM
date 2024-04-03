C= gcc
CFLAGS = -Wall -ansi -pedantic -pthread


all: sig_kill sig_capture sig_capture_improved sig_sigset sig_alarm sem_create sem_signal conc_alternate clean_objs
 
sig_kill: sig_kill.o
	$(C) $(CFLAGS) -o sig_kill sig_kill.o

sig_kill.o: sig_kill.c
	$(C) $(CFLAGS) -c sig_kill.c

 
sig_capture: sig_capture.o
	$(C) $(CFLAGS) -o sig_capture sig_capture.o

sig_capture.o: sig_capture.c
	$(C) $(CFLAGS) -c sig_capture.c


sig_capture_improved: sig_capture_improved.o
	$(C) $(CFLAGS) -o sig_capture_improved sig_capture_improved.o

sig_capture_improved.o: sig_capture_improved.c
	$(C) $(CFLAGS) -c sig_capture_improved.c


sig_sigset: sig_sigset.o
	$(C) $(CFLAGS) -o sig_sigset sig_sigset.o

sig_sigset.o: sig_sigset.c
	$(C) $(CFLAGS) -c sig_sigset.c


sig_alarm: sig_alarm.o
	$(C) $(CFLAGS) -o sig_alarm sig_alarm.o

sig_alarm.o: sig_alarm.c
	$(C) $(CFLAGS) -c sig_alarm.c


sem_create: sem_create.o
	$(C) $(CFLAGS) -o sem_create sem_create.o

sem_create.o: sem_create.c
	$(C) $(CFLAGS) -c sem_create.c


sem_signal: sem_signal.o
	$(C) $(CFLAGS) -o sem_signal sem_signal.o

sem_signal.o: sem_signal.c
	$(C) $(CFLAGS) -c sem_signal.c


conc_alternate: conc_alternate.o
	$(C) $(CFLAGS) -o conc_alternate conc_alternate.o

conc_alternate.o: conc_alternate.c
	$(C) $(CFLAGS) -c conc_alternate.c


clean: clean_programs clean_objs

clean_objs:
	rm *.o

clean_programs:
	rm sig_kill | rm sig_capture | rm sig_capture_improved | rm sig_sigset | rm sig_alarm | rm sem_create | rm sem_signal | rm conc_alternate