cc=gcc
CFlAGS = -o3 - C -wall
 
all:	obj

	$(cc) -o main *.0

obj:
	$(cc) $(CFlAGS) *.c

Clean:
	rm main.exe