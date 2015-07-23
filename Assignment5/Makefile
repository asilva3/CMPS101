#
#

all : Listdr BFSdr main

BFSdr : BFSdr.o BFS.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o BFSdr BFSdr.o BFS.o List.o

main : main.o List.o BFS.o
	gcc -ansi -Wall -Wextra -pedantic -o main main.o List.o BFS.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o Listdr Listdr.o List.o 

BFSdr.o : BFSdr.c BFS.h List.h
	gcc -c -ansi -Wall -Wextra -pedantic -g -c BFSdr.c

BFS.o : BFS.c BFS.h
	gcc -c -ansi -Wall -Wextra -pedantic -g -c BFS.c

main.o : main.c List.h BFS.h
	gcc -c -ansi -Wall -Wextra -pedantic -g -c main.c

List.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic -g -c List.c

Listdr.o : List.h Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic -g -c Listdr.c

clean :
	rm List.o Listdr.o main.o BFS.o BFSdr.o Listdr BFSdr main
