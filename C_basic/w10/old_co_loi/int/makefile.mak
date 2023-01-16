main: sortInt.o sortInt.h main.o utils.o
	gcc -o $@ sortInt.o main.o utils.o

main.o: sortInt.h
	gcc -c -g main.c

sortInt.o: sortInt.h
	gcc -c -g sortInt.c

utils.o: utils.h
	gcc -c -g utils.c