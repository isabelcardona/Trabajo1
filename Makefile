CC = gcc
CFLAGS = -O3 -c -Wall

all: obj
	$(CC) -o main.exe *.o -lpdcurses
	rm *.o
	
obj:
	$(CC) $(CFLAGS) *.c	
	
clean:
	rm main.exe	
