all: bstDemo

CFLAGS=-g -O3

bstDemo: bst.o bstDemo.o
	cc -o $@ $^

bst.o: bst.c bst.h 
	cc -c $(CFLAGS) bst.c

bstDemo.o: bstDemo.o bst.h
	cc -c $(CFLAGS) bstDemo.c
clean:
	rm -f *.o bstDemo

lab1: bstDemo
	echo "hello" 

