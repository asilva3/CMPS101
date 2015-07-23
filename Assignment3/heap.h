/*
 *    Header (.h) file for heap ADT
 *
 * This contains the operations and types exported 
 * byy the module. The module implements the ADT
 * heap using dynamic memory allocaiton. The state
 * of a heap is integers that are sorted using 
 * insertion or deleteing the top element of the heap
 * and freeing the heap.
 */


#include <stdbool.h>

/*
 * The following defines the heap handle type.
 * User should declare one variable of type
 * heapHndl for each heap that they want to have.
 * After declaration, the heapHndl procedures must
 * be called to insert the integers into the heap.
 */

typedef struct Heap *heapHndl;

/*
 * The procedure "newHeap creates a new heap object
 * and returns a pointer to it. This function
 * should be used to initalize each heap before
 * any other operations are performed on that heap.
 */
heapHndl newHeap(int maxSize);

/*
 * The access function isFull should be called inserting the 
 * integers into the heap making sure there is enough
 * space inside the heap. 
 * Precondition: The heap has been initialized.
 */
bool isFull(heapHndl h);

/*
 * The access function isEmpty returns true if the 
 * heap has no elements store in them.
 * Postcondition: return true if no elemements are in heap
 */
bool isEmpty(heapHndl h);

/*
 * The access function maxValue returns the integers at the
 * top of the heap.
 * Precondition: not isempt
 * Postcondition: return the integer at the top of the heap
 */
int maxValue(heapHndl h);

/*
 * The manipulation procedure deleteMax deletes the top of the 
 * heap and sorts the heap in order again deleteing the top
 * of the heap.
 * Precondition: stack is not empty
 * Postcondition: the heap is sorted 
 */
void deleteMax(heapHndl h);

/*
 * The manipulation procedure insertion inserts the integer into
 * the heap corrected by the amount of priority given
 * It has the top priority at the the beginnning of the heap.
 * Precondition: Stack is not empty
 * Postcondition: the heap is sorted
 */
void insert(heapHndl h, int priority);

/*
 * The manipulation procedure freeheap frees the heap and the data
 * inside the heap. 
 * Precondition: none
 * Postcondition: Free the heap and data
 */
void freeHeap(heapHndl h);
