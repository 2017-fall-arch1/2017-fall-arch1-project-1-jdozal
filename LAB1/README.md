# Project 1: Personnel Management System

This directory contains:
* code that implements a binary search tree with a list of names 
* a demo program that uses it

The demo program reads lines from stdin, and from a file to keep the list everytime the user runs the program.
When an employee is added to the system, it is added into a binary search tree and also it is appended to the file. 

This demo contains the following files:
 bst.h: header file of llist structure & "public" interface functions
 bst.c: implementation of personnel management system
 bstDemo.c: a demonstration of the personel management system
 

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ make demo
~~~

To delete binaries:
~~~
$ make clean
~~~
