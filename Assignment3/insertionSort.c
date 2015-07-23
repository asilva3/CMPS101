/*
 * Armando Silva, Kevin Thai asilva3@ucsc.edu kjthai@ucsc.edu
 * CS 101 - Spring 2014 - Assignment #3
 *
 * Source code (.c) file for insertionSort ADT
 *
 * This contains the implementation of the operation
 * exported by the insertionSort.h file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.h"

/*This method insertionSort takes in values
 * sorts them through the iteration of the 
 * array keys and indexs them
 */
void insertionSort(int keys[], int numKeys)
{
   int number = 0;  
   int index = 0;  
   int i;          /*use to iterate intil all numbers are inserted*/
   for(i =1; i<numKeys; ++i)
      {
         number = keys[i];
   /*While equal i and less than the last number insert at that position*/
         for(index =i; index >0 && number<keys[index-1]; --index)
         {
            keys[index] = keys[index-1];
         }
         keys[index] = number;
      }
}
