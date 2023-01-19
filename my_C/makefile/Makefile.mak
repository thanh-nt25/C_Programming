sum: main.o sum.o
	gcc -o $@ main.o sum.o
main.o: main.c sum.h
	gcc -c -g $*.c
sum.o: sum.c sum.h
	gcc -c -g $*.c