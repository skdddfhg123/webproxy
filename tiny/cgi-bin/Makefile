CC = gcc
CFLAGS = -O2 -Wall -I ..

all: adder

adder: adder.o
	$(CC) $(CFLAGS) -o adder adder.o

adder.o: adder.c
	$(CC) $(CFLAGS) -c adder.c

clean:
	rm -f *.o *~

fclean:
	$(MAKE) clean
	rm -f adder

re:
	$(MAKE) fclean
	$(MAKE) all

