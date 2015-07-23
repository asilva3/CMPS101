/*    
 *    Some of this code comes from David Helmold and his psuedo code
 *    credit to David Helmold
 *
 *    Armando Silva, Kevin Thai asilva3@ucsc.edu kjthai@ucsc.edu
 *    CS101 - Spring 2014 - Assignment #3
 *
 *    Source code (.c) file for heapSort ADT
 *
 *    This contains the implementation of the operation
 *    by heapSort.h file.
 */

#include <stdlib.h>
#include <stdio.h>
#include "heap.h"  /*This allows me to use my procedure*/

void heapSort(int keys[], int numKeys)
{
   int element; /*the iteration of element for the first loop*/
   int i;       /*The second iteration to the second loop*/

   heapHndl h; /*create the heap*/
   h = NULL; 
   h = newHeap(numKeys);
   numKeys--;

/*iterate through the heap starting at the first index to the max 
 * and insert the elements
 */
   for(element = 1; element <= numKeys; ++element)
   {
      insert(h, keys[element]); 
   }

/*start plugging in the values into array and deleting them one 
 * by one by deleting the max 
 */
   for(i = numKeys; i >= 1; --i)
   {
      keys[i] = maxValue(h);
      deleteMax(h);
   }
/*free the old heap*/
   freeHeap(h);
}
