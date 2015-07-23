/*
 * Driver program for the heap module
 * The purpose of this is not to do anything "interesting"
 * but test out the heap files and make sure that the heap
 * ADT implementaitons is working properly.
 */


#include "insertionSort.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   heapHndl test = newHeap(10);
   insert(test, 10); 
/*test the isEmpty function make sure it's not true*/
   if(isEmpty(test)== true)
   {
      printf("Something is wrong with my isEmpty method.\n");
      exit(1);
   }
/*Start inserting and ordering in proper order*/   
   insert(test, 2);
   insert(test, 103);
   insert(test, 11);
   insert(test, 131);
   insert(test, 101);
   insert(test, 120);
/*delete 131, highest number*/
   deleteMax(test);
/*delete 120, highest number*/
   deleteMax(test);
   if(isFull(test)== true)
   {
      printf("Something is wrong with my isFull method.\n");
      exit(1);
   }
   printf("The max value is suppose to be 103.\n");
   printf("This is the max value: %d\n", maxValue(test));  
/*free the heap*/   
   freeHeap(test);
   return 0; 
} 
