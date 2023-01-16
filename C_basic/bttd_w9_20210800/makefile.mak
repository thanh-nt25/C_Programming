wordcount: wordcount_bst.o
	gcc -o $@ wordcount_bst.o
wordcount_bst.o: wordcount_bst.c
	gcc -c -g $*.c