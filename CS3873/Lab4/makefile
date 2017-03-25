CFLAGS = -g -Wall -Wshadow -std=c99
GCC = gcc $(CFLAGS)
SRCS = driver.c vignere.c
OBJS = driver.o vignere.o

main: $(OBJS)
		$(GCC) -o Vignere driver.o vignere.o

driver.o: driver.c
		$(GCC) -c driver.c

vignere.o: vignere.c
		$(GCC) -c vignere.c

test1: main
	./Vignere Dv mbh ni ozafx, syo iry sklzzy ji mmmcy fgrr

test2: main
	./Vignere Io ioe ye ututv, bvv amn oujesu wf xisws teao
