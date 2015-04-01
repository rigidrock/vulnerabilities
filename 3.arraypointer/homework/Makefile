CC = gcc
CFLAG = -g -z execstack

all: intbufover
intbufover: intbufover.o connect.o
    $(CC) $(CFLAG) -o intbufover intbufover.o connect.o
intbufover.o: intbufover.c connect.h
    $(CC) $(CFLAG) -c intbufover.c
connect.o: connect.c
    $(CC) $(CFLAG) -c connect.c
clean:
    rm *.o intbufover
