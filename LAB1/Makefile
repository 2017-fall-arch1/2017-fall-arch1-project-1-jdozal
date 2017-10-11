all: bstDemo

CFLAGS=-g -O3

bstDemo: bst.o bstDemo.o
	cc -o $@ $^

bst.o: bst.c bst.h 
	cc -c $(CFLAGS) bst.c

bstDemo.o: bstDemo.c bst.h
	cc -c $(CFLAGS) bstDemo.c
clean:
	rm -f *.o bstDemo

demo: bstDemo
	./bstDemo
	#(echo b; echo a; echo c; echo h; echo d) | ./bstDemo
	#echo hello;

