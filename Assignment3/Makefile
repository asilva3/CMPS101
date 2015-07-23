#
#
all : heapDriver sortPrint sortComp

sortComp : heapSort.o heap.o insertionSort.o sortComp.o
	gcc -ansi -Wall -Wextra -pedantic -o sortComp sortComp.o heapSort.o heap.o insertionSort.o

sortPrint : sortPrint.o heap.o insertionSort.o heapSort.o 
	gcc -ansi -Wall -Wextra -pedantic -o sortPrint sortPrint.o heapSort.o heap.o insertionSort.o

heapDriver : heapDriver.o heap.o 
	gcc -ansi -Wall -Wextra -pedantic -o heapDriver heapDriver.o heap.o

sortComp.o : heap.h insertionSort.h heapSort.h sortComp.c
	gcc -c -ansi -Wall -Wextra -pedantic sortComp.c

sortPrint.o : heapSort.h heap.h insertionSort.h sortPrint.c
	gcc -c -ansi -Wall -Wextra -pedantic sortPrint.c

heapDriver.o : heap.h heapDriver.c
	gcc -c -ansi -Wall -Wextra -pedantic heapDriver.c

heap.o : heap.h heap.c
	gcc -c -ansi -Wall -Wextra -pedantic heap.c

heapSort.o : heapSort.h heapSort.c
	gcc -c -ansi -Wall -Wextra -pedantic heapSort.c

insertionSort.o : insertionSort.h insertionSort.c
	gcc -c -ansi -Wall -Wextra -pedantic insertionSort.c

clean :
	rm  sortPrint.o sortComp.o heapDriver.o heap.o heapSort.o insertionSort.o heapDriver sortPrint sortComp 
