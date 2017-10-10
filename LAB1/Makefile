all: bst

CFLAGS=-g -O3

bst: bst.o
	cc -o $@ $^

bst.o: bst.h
	cc -c $(CFLAGS) bst.c
clean:
	rm -f *.o bst

lab1: bst
	echo "hello" 

