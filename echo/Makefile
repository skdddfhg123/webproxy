CC = gcc
CFLAGS = -O2 -Wall -I .

LIB = -lpthread

all: server client

client: client.o csapp.o
	$(CC) $(CFLAGS) -o client client.o csapp.o $(LIB)

server: server.o csapp.o
	$(CC) $(CFLAGS) -o server server.o csapp.o $(LIB)

csapp.o: csapp.c
	$(CC) $(CFLAGS) -c csapp.c

server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

clean:
	rm -f *.o *~

fclean:
	rm -f *.o server client *~

re:
	$(MAKE) fclean
	$(MAKE) all
