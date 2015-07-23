/*
 *    Header (.h) file for List ADT
 *
 *    This contains the operations and types exported
 *    by the module. The module implements the ADT 
 *    "Linked List" using dynamic memory allocation. The
 *    state of a link list is a (possibly empty) sequence
 *    of linked lists, with the front and back "null".
 *
 *    USE OF THIS ADT ALSO REQUIRES THAT "myinclude.h" be 
 *    included.
 */


/*
 * The following defines the ListStruct type
 * User should declare (and initialize to null)
 * one variable type is ListHndl for each link list
 * they want to have. After declaration, the newList 
 * procedure must be called before any link list 
 * opersations can be performed.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListStruct* ListHndl;

/*
 * The procedure "newList" creates a new link list object
 * This function should be used to create the newList
 * before any operations are perfmored on that list
 * There is a precondition for freeing up the list, creating
 * the list.
 */

/*Creating*/
ListHndl newList(void);

/*Freeing List*/

void freeList(ListHndl* L);

/*
 * The access function isEmpty returns
 * true is list empty else return false
 */
int isEmpty(ListHndl L);

/*
 * The access function offEnd returns
 * true if current is equal to null
 */
int offEnd(ListHndl L);

/*
 * The access function atFirst returns 
 * true if current is equal to first
 */
int atFirst(ListHndl L);

/*
 * The access function atLast returns
 * true if current is equal to last
 */
int atLast(ListHndl L);

/*
 * The access function getFirst returns
 * the first element of the list
 */
long getFirst(ListHndl L);

/*
 * The access function getLast returns
 * the last element of the list
 */
long getLast(ListHndl L);

/*
 * The access function getCurrent returns
 * the the current element of the list
 */
long getCurrent(ListHndl L);

/*
 * The function makeEmpty deletes all the elements
 * from the list
 */
void makeEmpty(ListHndl L);

/*
 * The function moveFirst makes the first element current 
 * without changing the list order
 */
void moveFirst(ListHndl L);

/*
 * The function moveLast makes the last element current
 * without changing the list order
 */
void moveLast(ListHndl L);

/*
 * The function movePrev makes the current maker one element
 * earlier in the list
 */
void movePrev(ListHndl L);

/*
 * The function moveNext the current mark to one element later 
 * in the list
 */
void moveNext(ListHndl L);

/*
 * The function insertAtFront inserts new element before
 * at the front
 */

void insertAtFront(ListHndl L, long data);

/*
 * The function insertAtBack inserts new element after the last one
 * on the list
 */
void insertAtBack(ListHndl L, long data);

/*
 * The funciton insertbeforeCurrent inserts new element
 * before the current marker
 */
void insertBeforeCurrent(ListHndl L, long data);

/*
 * The function deleteFirst, deletes the first element on the list
 *
 */
void deleteFirst(ListHndl L);

/*
 * The funciton deleteLast, deletes the last element on the list
 */
void deleteLast(ListHndl L);

/*
 * The function deleteCurrent deletes the current element on the list
 */
void deleteCurrent(ListHndl L);

/*
 * The funtion printList prints out the list
 */
void printList(FILE* out, ListHndl L);

