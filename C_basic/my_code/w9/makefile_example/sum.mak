sum: main.o sum.o
	gcc -o sum main.o sum.o

main.o: main.c sum.h
	gcc -c -g main.c

sum.o: sum.c sum.h
	gcc -c -g sum.c