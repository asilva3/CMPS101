/*    
 *    Armando Silva, Kevin Thai, asilva3@ucsc.edu, kjthai@ucsc.edu
 *    CS101 - Spring 2014 - Assignment #3
 *
 *    Source code (.c) file for heap ADT
 *
 *    This contains the implementations of the operations
 *    and types exported by the heap.h file.
 */

#include <stdio.h>     
#include <stdlib.h>
#include <stdbool.h>

/*
 * The file heap.h contains the following:
 *
 * typdedef struct Heap *heapHndl;
 * heapHndl newHeap(int maxSize);
 * bool isEmpty(heapHndl h);
 * int maxValue(heapHndl h);
 * void deleteMax(heapHndl h);
 * void insert(heapHndl h, int priority);
 * void freeHeap(heapHndl h);
 */ 

typedef struct Heap *heapHndl;

struct Heap
{
   int maxSize;         /* This is the max Value in the heap*/
   int currentSize;     /* This is the size of the heap*/
   int *array;          /* The array of the heap*/
}Heap;

/*resizing the new heap and setting sizes to heap's
 * characteristics
 */
heapHndl newHeap(int maxSize)
{
   heapHndl h = malloc(sizeof(struct Heap));
   h->array = malloc(sizeof(int)*(maxSize+1));
   h->maxSize = maxSize;
   h->currentSize = 0;
   return h;
}

/*this method freeHeap() frees the heap*/
void freeHeap(heapHndl h)
{
   free(h->array);
   free(h);
}

/*This method checks to see if the heap is full*/
bool isFull(heapHndl h)
{
   if(h->currentSize == h->maxSize)
   {
      return true;
   }else
      return false;
}

/*This method checks to see if the heap is empty*/
bool isEmpty(heapHndl h)
{
   if(h->currentSize == 0)
   {
      return true;
   }else 
      return false;
}

/*this method returns the max value of the heap*/
int maxValue(heapHndl h)
{
   if(isEmpty(h))
   {
      return 0;
   }
   else
      return h->array[1];
}

/*this method swaps the parent and child*/
void swap(heapHndl h, int a, int b)
{
   int temp = h->array[a];
   h->array[a] = h->array[b];
   h->array[b] = temp;
}

/*
 * This function deleteMax takes the top number
 * of the heap, swaps with the bottom number of heap
 * deletes that number, therefore deleting the max number
 * of the heap
 */
void deleteMax(heapHndl h)
{
   if(isEmpty(h) == true)
   {
      printf("Error: Heap is Empty\n");
      exit(1);
   }

/*swap top value with the last on the heap*/
   swap(h, 1, h->currentSize);
   h->array[h->currentSize] = 0;
   int parent = 1;
 
/*iterate through the binary tree until the end unless break*/
   while(parent < h->currentSize)
   {
      int rchild = 2*parent+1;
      int lchild = 2*parent;
      if(lchild > h->currentSize)
      {
         break;
      }
/*the case if there is a left leave but not a right, compare left with parent*/
      else if(lchild <= h->currentSize && rchild > h->currentSize)
      {
         if(h->array[lchild] >= h->array[parent])
         {
            swap(h, lchild, parent);  
            parent = lchild;
            continue;
         }else
             break; 
       }
/*if right child is greater than left, check if it's greater than parent*/
      else if(h->array[lchild] <= h->array[rchild] && h->array[rchild] >= h->array[parent])
      {
         swap(h, rchild, parent);
         parent = rchild;
      } 
/*if left child is greater than right, check if it's greater than parent*/
      else if(h->array[lchild] >= h->array[rchild] && h->array[lchild] >= h->array[parent])
      {
            swap(h, lchild, parent);
            parent = lchild;
      }else break;
   }
}

/*This function inserts the priority at 
 * the correct position of the heap
 */
void insert(heapHndl h, int priority)
{
 
   if(isFull(h) == true)
   {
      printf("Error: Heap is full.\n");
      exit(1);
   }

   h->currentSize++;                      /*Increase the size of the heap*/
   h->array[h->currentSize] = priority;   /*the new number = last number*/
   int child = h->currentSize;
/*iterate through until find the position where priority needs to be*/
   while(child > 1)
   {
      int parent = child/2;
      if(h->array[child] > h->array[parent])
      {
         swap(h, child, parent);
         child = child/2;
      }else
         break;
   }
}


