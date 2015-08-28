cc=gcc
CFlAGS = -O3 - c -Wall
 
all:	object

	$(cc) -o main *.0

object:
	$(cc) $(CFlAGS) *.c

Clean:
	rm main.exe