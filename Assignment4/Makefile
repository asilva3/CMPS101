#
#
all : hashdr main

main : main.o hash.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o main main.o hash.o List.o

hashdr : hashdr.o hash.o List.o
	gcc -ansi -Wall -Wextra -pedantic -g -o hashdr hashdr.o hash.o List.o

main.o : main.o hash.h List.h
	gcc -c -ansi -Wall -Wextra -pedantic -g -c main.c

hashdr.o : hashdr.c hash.h hash.c
	gcc -c -ansi -Wall -Wextra -pedantic -g -c hashdr.c

hash.o : hash.h hash.c List.h
	gcc -c -ansi -Wall -Wextra -pedantic -g -c hash.c 

List.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic -g -c List.c

clean : 
	rm List.o hash.o hashdr.o hashdr main.o
