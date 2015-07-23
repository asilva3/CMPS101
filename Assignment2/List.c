/*
 * Armando Silva, asilva3@ucsc.edu
 * CS101 - Spring 2013 - Assignment #2
 * The List.c file is the methods used in Listdr 
 * as well as Store.c.
 *
 **/

#include "List.h"
#include "myinclude.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct NodeStruct* NodePtr;

/*The node struct. Has data, net pointer, and a prev pointer
 */

 typedef struct NodeStruct
 {
   long data; /*Data*/
   struct NodeStruct* next; /*pointer to next node*/
   struct NodeStruct* prev; /*pointer to prev node*/
 }NodeStruct;

/*Creates my list struct*/
typedef struct ListStruct{
   NodePtr first;
   NodePtr current;
   NodePtr last;
   int size;
}ListStruct;

/*pointers to these methods because warnings of not declaring 
 * them yet and used in methods before they are defined
 */
void makeEmpty();
void deleteFirst();

/*Creates the List  that has pointers of the first,
 * current, last nodes of the list
 */
ListHndl newList(void)
{
   ListStruct *L = malloc(sizeof(ListStruct));
   L->first = NULL;
   L->last = NULL;
   L->current = NULL;
   L->size = 0;
   return L;
}

/*This method isEmpty() checks to see if the 
 * list is empty or not.
 */
int isEmpty(ListHndl L)
{
   if(L == NULL){
      printf("Error: List has not been made.\n");
      exit(1);
   }else{
      return (L->size == 0);
   }
}

/*The method offEnd() checks to see if the current
 * pointer is NULL
 */
int offEnd(ListHndl L)
{
   if(L == NULL){
      printf("Error: List has not been made.\n");
      exit(1);
   }else{
      return (L->current == NULL);
   }
}

/*This method atFirst() sees if current is pointing to 
 * the first element on the list
 */
int atFirst(ListHndl L)
{
   if(L == NULL){
      printf("Error: List has not been made.\n");
      exit(1);
   }
   if(!offEnd(L)){
         return (L->current == L->first);
   }
    printf("Error: Current is NULL\n");
    exit(1);
}

/* The method atLast() is points current to last of the list
 */
int atLast(ListHndl L)
{
   if(L == NULL){
      printf("Error: List has not been made yet.\n");
      exit(1);
   }
   if(!offEnd(L)){
      L->current = L->last;
   }
   printf("Error: The current element is NULL.\n");
   exit(1);
}

/*This method gets the first element on the list*/
long getFirst(ListHndl L)
{
   if(L == NULL){
      printf("Error: List has not been made yet.\n");
      exit(1);
   }
   if(!isEmpty(L)){
      return L->first->data;
   }
      printf("Error: Can't obtain the first number.\n");
      exit(1);  
}

/*This method gets the last element on the list*/
long getLast(ListHndl L)
{
   if(L == NULL){
      printf("Error: List has not been made yet.\n");
      exit(1);
   }
   if(!isEmpty(L)){
      return L->last->data;
   }
   printf("Error: Can't obtain the last number.\n");
   exit(1);
}

/*This method gets the current element on the list*/
long getCurrent(ListHndl L)
{
   if(L == NULL){
      printf("Error: List has not been made yet.\n");
      exit(1);
   }
   if(!offEnd(L)){
      return L->current->data;
   }
   printf("Error: Cannot get current element.\n");
   exit(1);
}

/*Creates the new node with, data, next, prev pointers*/
NodeStruct* create(ListHndl L, long data)
{
   NodeStruct *new = malloc(sizeof(NodeStruct));
   new->data = data;
   new->next = NULL;
   new->prev = NULL;
   return new;
}

void freeNode(NodePtr* new)
{
   free(*new);
}

void freeList(ListHndl* L)
{
   makeEmpty(*L);
   free(*L);
}

void makeEmpty(ListHndl L)
{
   if(L == NULL)
   {
      printf("Error: List is already empty\n");
      exit(1);
   }
   /*While the List is not empty*/
   while(!isEmpty(L)){
      deleteFirst(L);
   }
}


void moveFirst(ListHndl L)
{
   if(!isEmpty(L)){
      L->current = L->first;
      }else{
         printf("Empty List.\n");
         exit(1);
   }
}

void moveLast(ListHndl L){
   if(!isEmpty(L)){
      L->current= L->last;
   }
}

void movePrev(ListHndl L){
   if(!offEnd(L)){
      L->current = L->current->prev;
   }
}

void moveNext(ListHndl L){
   if(!offEnd(L)){
      L->current = L->current->next;
   }
}

/*Inserts the new node in front of the list, points
 * the List's first to the new node
 */
void insertAtFront(ListHndl L, long data)
{
   NodeStruct* new = create(L, data);

   /*If the size of the list is null, set
    *node to first on the list*/
   if(isEmpty(L)){
      L->first = new;
      L->current = new;
      L->last = new;
   }else{
   /*set the new next pointer to the first node's prev */
      new->next = L->first;
     
    
   /*List's first points to new*/
      L->first->prev = new;
      L->first = new;
      
   }
   L->size++;  
}  

 
void insertAtBack(ListHndl L, long data)
{
   NodeStruct *new = create(L,data);
   /*if the size is 0*/
   if(isEmpty(L)){
   /*the first of the list since there is nothing on list*/
      L->last = new;
   }else{
   /*The next and prev pointers to the current*/
      new->prev = L->last;
      L->last->next = new;
      L->last = new;
   }
   L->size++;
} 


void insertBeforeCurrent(ListHndl L, long data)
{
      NodeStruct* new = create(L,data);
      if(!offEnd(L)){
         L->current->prev->next = new;
         new->prev = L->current->prev;
         new->next = L->current;
         L->current->prev = new;
   } 
}

void deleteFirst(ListHndl L)
{
   if(isEmpty(L)){
      printf("Can't delete, nothing in the list");
   }
   if(L->size == 1){
      L->first = NULL;
   }else if(!isEmpty(L)){ 
      NodePtr tmp = L->first;
      L->first = L->first->next;
      L->last->prev = NULL;
   }
   L->size--;
}

void deleteLast(ListHndl L)
{
   /*if List is empty, can't delete anything*/
   if(isEmpty(L)){
      printf("Can't delete, nothing contained in the list.");
   }
   /*if List has only one item, list is null*/
   if(L->size == 1){
      L->first = NULL;
   }
   /*removing is gone, and second last pointed at prev*/
   else if(!isEmpty(L)){
      
      NodePtr tmp = L->last;
      L->last= L->last->prev;
      L->last->next = NULL;
   }
   L->size--;
}

void deleteCurrent(ListHndl L)
{
   /*Checking for errors first*/
   if(isEmpty(L)){
      printf("Error: No size in the list.");
      exit(1);
   }
   NodeStruct* temp = NULL;
   temp = L->current;
   if(L == NULL){
      printf("Error: List has not been made yet.\n");
      exit(1);
   }
   if(isEmpty(L)){
      printf("Error: List is empty.\n");
      exit(1);
   }
   if(offEnd(L)){
      printf("Error: Can't delete at the end.\n");
      exit(1);
   }

   if(L->size > 1){
   /*if current is not at the end of the list or first*/
      if(L->current->prev != NULL && L->current->next != NULL){
         L->current->next->prev = L->current->prev;
         L->current->prev->next = L->current->next;
         L->current->next = NULL;
         L->current = NULL;
      }
   /*if current is at the beginning of the list*/
      else if(L->current->prev == NULL){
         L->first = L->current->next;
         L->current->next = NULL;
      }
   /*if current is at the end of the list*/
      else if(L->current->next == NULL){
         L->last = L->current->prev;
         L->current->prev =NULL;
      }L->current = NULL;
   }
   else{
      L->first = NULL;
      L->last = NULL;
      L->current = NULL;
   }
   /*decrement the size becuase of deletion*/
   L->size--;
   free(temp);
}

void printList(FILE* out, ListHndl L)
{
   
   /*Node current is pointing to the first element*/
   NodePtr printing = L->first;
   /*contiunes through the list printing out the number*/

   while(printing != NULL){
      fprintf(out, "%8ld ", printing->data); 
      printing = printing->next;
   }
}
