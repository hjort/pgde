CC = gcc
CFLAGS = -Wall -g

LDFLAGS = -lcrypto

all: sha1

sha1:
	gcc -Wall -g sha1.c -o sha1 -lcrypto

clean:
	rm -f sha1

test: all
	echo -n "Hello, World" | openssl sha1 ;\
	./sha1 "Hello, World"
