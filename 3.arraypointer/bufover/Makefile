CC = gcc
CFLAG = -g -z execstack

all: bufover
bufover: main.o read.o
    $(CC) $(CFLAG) -o bufover main.o read.o
main.o: main.c
    $(CC) $(CFLAG) -c main.c
read.o: read.c
    $(CC) $(CFLAG) -c read.c
clean:
    rm *.o bufover
