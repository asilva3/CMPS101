/*
 * Armando Silva, asilva3@ucsc.edu
 * Brandon Gomez, brlgomez@ucsc.edu
 * CS 101- Spring 2014- Assignment #4
 * The List.c file is the method used in hashdr
*/
#include "List.h"
#include "myinclude.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * The node struct has a data, next, and prev
 * pointer. Has a Listhandle for the bookIDs
 */
typedef struct NodeStruct{
  void* data;
  struct NodeStruct* next;
  struct NodeStruct* prev;
  ListHndl bookid;
}NodeStruct;

/*Creates my List struct*/
typedef struct ListStruct{
  NodePtr first;
  NodePtr current;
  NodePtr last;
  int size;
}ListStruct;

/*The method newNode() initializes and returns
* a new node "object"*/
NodePtr newNode(void* newdata)
{
  NodePtr newNode = malloc(sizeof(NodeStruct));
  newNode->data = newdata;
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->bookid = NULL;
  return newNode;
}

NodePtr newbook(void* newdata, ListHndl bookid)
{
  NodePtr newNode = malloc(sizeof(NodeStruct));
  newNode->data = newdata;
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->bookid = bookid;
  return newNode;
}

/*
 * Creates the List that has pointers of the 
 * first, current, and last nodes of the list
 */
ListHndl newList(void)
{
   ListHndl L;
   L = malloc(sizeof(ListStruct));
   L->first = NULL;
   L->current = NULL;
   L->last = NULL;
   L->size = 0;
   return L;
}

/*
 * Returns the book id
 */
ListHndl returnid(ListHndl L)
{
   if(offEnd(L))
   {
      printf("Error: At the end of the list, no ID.\n");
      exit(1);
   }
   if(isEmpty(L))
   {
      printf("Error: List is empty.\n");
      exit(1);
   }
   return L->current->bookid;
}

/*
 * THe method pointbook() returns the pointer to the book searched for
 * passing in the listhandle, bookname, and the bookid
 */
void pointbook(ListHndl L, char* bookname, ListHndl bookid)
{
  (void*) bookname;
   NodePtr book = newbook(bookname, bookid); 
   if(L->last == NULL)
   {
      L->first = book;
      L->last = book;
   }
   else if(L->last != NULL)
   {
      L->last->next = book;
      book->prev = L->last;
      L->last = book;
   }
   L->size = L->size + 1;
}

/*This method prints out the IDs of the ListHndl in the Hash.*/
void printIDs(ListHndl L)
{
   moveFirst(L);
   while(!offEnd(L))
   {
      long* bookid = L->current->data;
      printf("%lu ", *bookid);
      moveNext(L);
   }printf("\n");
}

/*This method isEmpty() checks to see if the 
 * list is empty or not
 */
int isEmpty(ListHndl L)
{
  if(L == NULL)
     {
         printf("List Handle has not been defined yet. In List.c\n");
         exit(1);
     }else{
         return (L->size==0);
      }
}

/*The method offEnd() checks to see if the current
 * pointer is NULL
 */
int offEnd(ListHndl L)
{
  if(L == NULL)
     {
        printf("Error: List has not been made.\n");
        exit(1);
     }else{
         return (L->current ==NULL); 
      }
}

/*This method atFirst() sees if current is pointing to
 * the first element on the list
 */
int atFirst(ListHndl L)
{
   if(L == NULL)
   {
      printf("Error: List has not been made.\n");
      exit(1);
   }
   if(!offEnd(L))
   {
      return(L->current == L->first);
   }
   else{
      printf("Error: Current is NULL\n");
      exit(1);
   }
}

/*The method, atLast() points current to the last of the list*/
int atLast(ListHndl L)
{
  if(L == NULL)
     {   
        printf("Error: List has not been made.\n");
        exit(1);
     }
  if(offEnd(L))
     {
        printf("Error: The current element is NULL.\n");
        exit(1);
     }
   else{
      return (L->current == L->last);
   }
}

/*The method gets the first element on the list*/
void* getFirst(ListHndl L)
{
  if(L == NULL)
     {   
        printf("Error: List has not been made yet.\n");
        exit(1);
     }
  if(isEmpty(L))
     {
        printf("Error: Can't obtain the first number.\n");
        exit(1);
     }
   else{
      return (L->first->data);
   }
}

/*The method gets the last element on the list*/
void* getLast(ListHndl L)
{
  if(L == NULL)
     {   
        printf("Error: List has not been made yet.\n");
        exit(1);
     }
  if(isEmpty(L))
     {
        printf("Error: Can't obtain the last number.\n");
        exit(1);
     }
   else{
      return (L->last->data);
   }
}  

/*The method gets the current element on the list*/
void* getCurrent(ListHndl L)
{
  if(L == NULL)
     {   
        printf("Error: List has not been made yet.\n");
        exit(1);
     }   
  if(offEnd(L))
     {   
        printf("Error: Cannot get current element.\n");
        exit(1);
     } 
   else{
      return (L->current->data); 
   }
}

/*This method deletes all the nodes from the list*/
void makeEmpty(ListHndl L)
{
  if(L == NULL)
     {
        printf("Error: List is already empty.\n");
        exit(1);
     } 
  while(!isEmpty(L))
     {   
        deleteFirst(L);
     } 
}

/*The method changes the current pointer to the first of the list*/
void moveFirst(ListHndl L)
{
  if(L == NULL)
     {
        printf("Error: List has not been created.\n");
        exit(1);
     }
  if(isEmpty(L))
     {
        printf("Error: Empty List.\n");
        exit(1);
     }
   else{
      L->current = L->first;
  }
}

/*The method changes current pointer to the end of the list*/
void moveLast(ListHndl L)
{
  if(L == NULL)
     {   
        printf("Error: List has not been created.\n");
        exit(1);
     }   
  if(isEmpty(L))
     {   
        printf("Error: List Empty.\n");
        exit(1);
     }
   else{
      L->current = L->last;   
   }
}

/*The method changes current pointer to the prev node of the
 * list
 */
void movePrev(ListHndl L)
{
  if(L == NULL)
     {   
        printf("Error: List has not been created.\n");
        exit(1);
     }   
  if(isEmpty(L))
     {   
        printf("Error: Current is already in use.\n");
        exit(1);
     }
  if(offEnd(L))
     {
        printf("Error: List is empty.\n");
        exit(1);
     }
   else{
      L->current = L->current->prev;
   }
}

/*The method changes pointer to the next node of the list*/
void moveNext(ListHndl L)
{
  if(L == NULL)
     {   
        printf("Error: List has not been created.\n");
        exit(1);
     }  
  if(isEmpty(L))
     {   
        printf("Error: List is Empty.\n");
        exit(1);
     }
  if(offEnd(L))
     {
        printf("Error: Pointing to nothing.\n");
        exit(1);
     }
   else{
      L->current = L->current->next;
   }
}

/*Inserts the new node in the front of the list, points 
 * the List's first to the new node
 */
void insertAtFront(ListHndl L, void* data)
{
  NodePtr node = NULL;
  if(L == NULL)
     {   
        printf("Error: List has not been created.\n");
        exit(1);
     }   
  node = newNode(data);
  if(L->first != NULL)
     {
        L->first->prev = node;
        node->next = L->first;
        L->first = node;
     }
  else
     {
        L->first = node;
        L->last = node;
     }
  L->size++;
  
}

/*The method the new node at the end of the list,
 * points the list's last to the new node
 */
void insertAtBack(ListHndl L, void* data)
{
  NodePtr node = NULL;
  if(L == NULL)
     {
        printf("Error: List has not been created.\n");
        exit(1);
     }
  node = newNode(data);
  if(L->last != NULL)
     {
        L->last->next = node;
        node->prev = L->last;
        L->last = node;
     }
  else
     {
        L->first = node;
        L->last = node;
     }
  L->size++;
}

/*Inserts new node before the current pointer 
 * points the new nodes pointer to the previous 
 * next node
 */
void insertBeforeCurrent(ListHndl L, void* data)
{
  NodePtr node = NULL;
  if(L == NULL)
     {
        printf("Error: List has not been created.\n");
        exit(1);
     }
  if(offEnd(L))
     {
        printf("Error: The current is off the end of the list.\n");
        exit(1);
     }
  node = newNode(data);
  if(L->current->prev != NULL)
     {
        
        node->prev = L->current->prev;
        L->current->prev->next = node;
        node->next = L->current;
        L->current->prev = node;
     }
  else
     {
        node->prev = NULL;
        node->next = L->current;
        L->current->prev = node;
        L->first = node;
         
     }
  L->size++;
}

/*The method deltes the first node of the list
 * and sets al pointers to the next and/or prev nodes
 * if last one on the list, set all the pointers to null
 */
void deleteFirst(ListHndl L)
{
  if(L == NULL)
     {
        printf("Error: List has not been created.\n");
        exit(1);
     }
  if(isEmpty(L))
     {
        printf("Error: Can't delete, nothing on the list.\n");
        exit(1);
     }
  if(L->size > 1)
     {
        L->first = L->first->next;
        L->first->prev = NULL;
  }
  else
     {
        L->first = NULL;
        L->current = NULL;
        L->last = NULL;  
     }
  L->size--;
}

/*The method deletes the last node of the list
 * and sets the prev pointer to null, if the last on the list
 * and the set every pointer to null
 */
void deleteLast(ListHndl L)
{
   if(L == NULL)
     {
        printf("Error: List has not been created.\n");
        exit(1);
     }
  if(isEmpty(L))
     {
        printf("Error: Can't delete nothing contained in the list.\n");
        exit(1);
     }
  if(L->size >1)
     {
        L->last = L->last->prev;
        L->last->next = NULL;
     }
  else
     {
        L->first = NULL;
        L->current = NULL;
        L->last = NULL;
     }
  L->size--;
}

/*The method deletes the current node of the list
 * sets the pointer to the prev and next node
 * links them together. If current is the first on the list
 * just set the pointers of the next to the next node.
 * If current is the last on the list, just set the 
 * pointers to the prev node
 */
void deleteCurrent(ListHndl L)
{
  if(L == NULL)
     {
        printf("Error: List has not been made yet.\n");
        exit(1);
     }
  if(isEmpty(L))
     {
        printf("Error: No size in the list.\n");
        exit(1);
     }  
  if(offEnd(L))
     {
        printf("Error: Can't delete at the end.\n");
        exit(1);
     }
  if(L->size > 1)
     {
        if(L->current->prev != NULL && L->current->next != NULL)
           {
              L->current->next->prev = L->current->prev;
              L->current->prev->next = L->current->next;
              L->current->next = NULL;
              L->current->prev = NULL;
              L->current = NULL;
           }
        else if(L->current->prev == NULL)
           {
              L->first = L->current->next;
              L->current->next = NULL;
           }
        else if(L->current->next == NULL)
           {
              L->last = L->current->prev;
              L->current->prev = NULL;
           }
        L->current = NULL;
     }
  else
     {
        L->first = NULL;
        L->last = NULL;
        L->current = NULL;   
     }
  L->size--;
}

