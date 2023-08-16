CC = gcc
ICS = ..
CFLAGS =  -Og 

PROGS = sumvec \
    sumarrayrows\
	sumarraycols\
	sumarray3d\
	sumrecur

all: $(PROGS) timing.h

clean:
	rm -f $(PROGS) *.o *~


