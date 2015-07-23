/* Credit to David Helmbold for some code about the startTime
 * functions and the clock. printing out the time.
 * Credit to Helmbold.
 *
 * Armando Silva, Kevin Thai asilva3@ucsc.edu, kthai@ucsc.edu
 * CS 101 - Spring 2014 - Assignment #3
 *
 * Source code(.c) file for the main file
 *
 * This contains the implementations of all header files in my files
 * 
 * This file is meant to print out the running time of two implemented
 * functions, insertion sorting and heap sorting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"
#include "heapSort.h"
#include "insertionSort.h"


int main(int argc, char** argv)
{
   int rn = 0;
   int i = 0;
   int max = 0;
   FILE *file = fopen(argv[1], "r");
   
   clock_t startTime, duration;
   startTime = clock();

/*The main file takes in the prgrogram and a file*/
   if(argc != 2)
   {
      printf("Error: The program takes in a file.\n");
      exit(1);
   }
/*Make sure file is not null, or bad file*/   
   if(file == NULL){
      printf("No File: Invalid.\n");
      exit(1);
   }
/*Give the user the heads up that the file went through*/
   printf("The file went through, success.\n");
/*The first integer is the size of the array*/
   fscanf(file, "%d", &max);
/*Store the first integer to create the size of both arrays*/
   int arrayIn[max];
   int arrayheap[max+1];

/*Iterate to take in numbers and store them into the index*/
   for(i=0; i<max; ++i)
   {
      fscanf(file, "%d", &rn);   
      arrayIn[i] = rn;
      arrayheap[i+1] = rn;
   }
   startTime = clock();

/*call insertionSort funtion to sort them and print time out*/
   insertionSort(arrayIn, max);
   duration = clock() - startTime;
    printf("Insertion Sort took %f seconds.\n", ((float) duration/
CLOCKS_PER_SEC));

   startTime = clock();  
/*Call heapSort function to sort them in a heap and print time out*/
   heapSort(arrayheap, max+1);
   duration = clock() - startTime;
   printf("Heap Sort took %f seconds. \n", ((float) duration/ 
CLOCKS_PER_SEC));
   printf("The program has finished.\n");
   fclose(file);
}
