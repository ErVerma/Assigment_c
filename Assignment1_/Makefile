CC=gcc
CFLAGS= -c 
compile: all

all: main.o list.o 
	$(CC) b2h.o list.o  -o final.exe

main.o: b2h.c
	$(CC) $(CFLAGS) b2h.c

list.o: list.c
	$(CC) $(CFLAGS) list.c



clean:
	rm -rf *.o final.exe
