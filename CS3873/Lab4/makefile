CFLAGS = -g -Wall -Wshadow -std=c99
GCC = gcc $(CFLAGS)
SRCS = driver.c vignere.c
OBJS = driver.o vignere.o

main: $(OBJS)
		$(GCC) -o Vigenere driver.o vignere.o

driver.o: driver.c
		$(GCC) -c driver.c

vignere.o: vignere.c
		$(GCC) -c vignere.c

test1: main
	./Vigenere VigenereCipher.txt