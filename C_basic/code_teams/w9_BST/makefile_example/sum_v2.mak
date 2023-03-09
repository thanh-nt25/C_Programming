sum_v2: main.o sum.o
	gcc -o $@ $*.o

main.o sum.o: sum.h
	gcc -c $*.c