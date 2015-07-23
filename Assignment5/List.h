/*
* Header (.h) file for List ADT
* 
*
* This contains the operations and types exported
* by the module.  The module implements the ADT
* "Linked List" using dynamic memory allocation. The
* state of a link list is a (possibly empty) sequence
* of linked lists, with the front and back "null".
* 
*/

/*
 * The following defines the ListStruct type
 * User should declare (and initialize to null)
 * one variable type ListHndl for each link list
 * they want to have. The other is the NodeStruct
 * the structure of a new node. After declartion, 
 * the newList procedure must be called before any link list
 * as well as the newNode and newbook.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct* NodePtr;
typedef struct ListStruct* ListHndl;

/*
 * The procedure "newList" creates new link list object
 * This function should be used to create the newList
 * before any operations are performed on that list
 * The same goes for creating a newNode and a new
 * BookNode, these constructors create a newNode for
 * the list inside each slot of the hash table
 * and a new booknode for the bookID.
 */

/*creating*/
ListHndl newList(void);
ListHndl returnid(ListHndl L);
NodePtr newNode(int newdata);
/*NodePtr newbook(int newdata, ListHndl IDList);*/

/*
 * The function insertBook goes into the List
 * check the book name and inserts the IDlist into that
 * bookname
 */
/*void pointer(ListHndl L, char* bookname, ListHndl IDList);*/

/*
 * The function printIDs gets the ListHndl
 * and prints out the bookIds in that list handle.
 */
/*void printIDS(ListHndl L);*/

/*
 * The funciton printList goes into the ListHndl L
 * and prints out the list of link list in there
 */
void printList(ListHndl L);

void freenode(NodePtr* myNode);

void freelist(ListHndl* L);

/*
 * The access function isEmpty returns
 * true if list is empty, else return false
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
int getFirst(ListHndl L);

/*
 * The access function getLast returns
 * the last element of the list
 */
int getLast(ListHndl L);

/*
 * The access function getCurrent retuns
 * the current element of the list
*/
int getCurrent(ListHndl L);

/*
 * The function moveFirst makes the first element current
 * without changing the list order
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
 * The function movePrev makes the current mark one element
 * earlier in the list
 */
void movePrev(ListHndl L);

/*
 * The function moveNext makes the current makr to the one elmeent
 * laster in the list
 */
void moveNext(ListHndl L);

/*
 * The function insertAtFront inserts new element before
 * at the front
 */
void insertAtFront(ListHndl L, void* data);

/*
 * The function insertAtBack inserts new element after the last one
 * on the list
 */
void insertAtBack(ListHndl L, void* data);

/*
 * The function insertBeforeCurrent inserts new element
 * before the current marker
 */
void insertBeforeCurrent(ListHndl L, void* data);

/*
 * The function deleteFirst delete the first element on the 
 * list
 */
void deleteFirst(ListHndl L);

/*
 * The function deleteLast deletes the last element on the 
 * list
 */
void deleteLast(ListHndl L);

/*
 * The function deleteCurrent deletes the current element on 
 * the list
 */
void deleteCurrent(ListHndl L);

