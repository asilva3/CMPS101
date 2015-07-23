/*
 * Armando Silva, Kevin Thai asilva3@ucsc.edu, kthai@ucsc.edu
 * CS 101 - Spring 2014 - Assignment #3
 *
 * Source code (.c) file for the ADTs in my file
 *
 * This contains the implementation of all my operations
 * and types expoerted by each .h file in my directory
 *
 * The objective of this .c file is to print out the 
 * correct sorted integers for each the heap function
 * and the insertion function
 */

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"          /*This allows to use ADT file*/
#include "heapSort.h"      /* "  "*/
#include "insertionSort.h" /* "  "*/

void printSort(int* arrayheap, int* arrayIn, int number)
{
   int i;
   int j;
 /*printing out insertion array*/
   printf("InsertionSort:     ");
   printf("HeapSort:     \n");
   for(i = 0; i< number ; ++i)
   {
   /*
    * This if statement makes sure that the arrayInsertion is always equal
    * *to arrayHeap to ensure no jumping in the array or else break
    *
    */
      if( arrayIn[i] != arrayheap[i+1])
      {
         printf("Error : Not sorted, %d and %d\n", arrayIn[i], arrayheap[i]);
         exit(1);
      }
   /*
    * This does the actual printing of each the array Insertion
    * and the array heap.
    */
      printf("%d                       %d\n", arrayIn[i], arrayheap[i+1]);
   }
   printf("\n");

}


int main(int argc, char** argv)
{
   int rn = 0;
   int i = 0;
   int max = 0;

/*Make sure the program only takes in one file*/
   if(argc != 2)
   {
      printf("Error: The program takes in a file.\n");
      exit(1);
   }

   FILE *file = fopen(argv[1], "r");
   if(file == NULL)
   {
      printf("File is invalid.\n");
      exit(1);
   }
   
   printf("The file went through, success.\n");

/*The first integer of the file is the amount of space in the array*/
   fscanf(file, "%d",&max);
   printf("The array size is: %d\n", max);
/*Set the amount to the first integer of the file*/
   int arrayIn[max];
   int arrayheap[max+1];
 
/*inserting the integers in the file to the array*/
   for(i = 0; i<max; ++i)
   {
    fscanf(file, "%d", &rn);
    arrayIn[i] = rn;
    arrayheap[i+1] = rn;
   }
   printf("\n");
   
   insertionSort(arrayIn, max);
   heapSort(arrayheap, max+1);
/*call the method printSort passing in the sorted insert Array and heap
 * array and the max amount 
 */
   printSort(arrayheap, arrayIn, max);
   printf("Left list is insertionSort, Right list is heapSort.\n");
   fclose(file);
}

