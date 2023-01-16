main: sort_t.o sort_t.h main.o data_t.o
	gcc -o $@ sort_t.o main.o data_t.o

main.o: sort_t.h
	gcc -c -g main.c

sort_t.o: sort_t.h data_t.h
	gcc -c -g sort_t.c

data_t.o: data_t.h
	gcc -c -g data_t.c