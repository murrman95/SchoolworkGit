CFLAGS= -std=c99 -Wall

main: as3.o module.o
	gcc -o Program as3.o module.o

as3.o: as3.c
	gcc -c as3.c $(CFLAGS)

module.o: module.c
	gcc -c module.c $(CFLAGS)


Res: As3 Module
	gcc -o Res As3 Module
As3: as3.c
	gcc -o As3 as3.c -Wall
Module: module.c
	gcc -o Module module.c -Wall
