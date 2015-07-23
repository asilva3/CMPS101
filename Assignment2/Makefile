#
#
all: Listdr  store

store : store.o  List.o
	gcc -ansi -Wall -Wextra -pedantic -g -o store store.o List.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -g -o Listdr Listdr.o List.o

List.o : List.h List.c
	gcc -ansi -Wall -Wextra -pedantic -g -c List.c

Listdr.o : List.h Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic -g -c Listdr.c

store.o : List.h store.c
	gcc -c -ansi -Wall -Wextra -pedantic -g -c store.c
clean :
	rm Listdr Listdr.o List.o store.o store
