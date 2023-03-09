main: sortChar.o sortChar.h main.o
	gcc -o $@ sortChar.o main.o

main.o: sortChar.h
	gcc -c -g main.c

sortChar.o: sortChar.h
	gcc -c -g sortChar.c