CC = gcc
CFLAGS = -O2 -Wall -I .

# This flag includes the Pthreads library on a Linux box.
# Others systems will probably require something different.
LIB = -lpthread

all: tiny cgi

tiny: tiny.c csapp.o
	$(CC) $(CFLAGS) -o tiny tiny.c csapp.o $(LIB)

csapp.o: csapp.c
	$(CC) $(CFLAGS) -c csapp.c

cgi:
	(cd cgi-bin; make)

clean:
	rm -f *.o *~
	(cd cgi-bin; make clean)

fclean:
	$(MAKE) clean
	(cd cgi-bin; make fclean)
	rm -f tiny

re:
	$(MAKE) fclean
	$(MAKE) all
	(cd cgi-bin; make re)
