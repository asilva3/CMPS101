/*
 *
 * Our driver program impelments all methods, constructors and access methods
 * from our hash.c file and some from our List.c using ListHndls.
 *
 */

#include "myinclude.h"
#include "List.h"
#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
   /*Implements our HashHndl*/
   HashHndl First = NULL;
   /*Implements our new hash*/
   First = newhash(10);
   /*Implements our method insert*/
   insert(First, "dog", 11);
   insert(First, "dog", 12);
   insert(First, "cat", 1);
   insert(First, "chiwawa", 20);
   /*Implements our method lookup*/
   ListHndl L = lookup(First, "dog");
   printIDs(L);
   ListHndl I = newList();
   I = lookup(First, "cat");
   printIDs(I);
   ListHndl H = newList();
   H = lookup(First, "Error");
   if(L == NULL){
      printf("There is something wrong with our insert method.\n");
   }
   if(H == NULL){
      printf("\n");
   }
   if(H != NULL){
      printf("Something is wrong with lookup function.\n");
   }
   ListHndl J = newList();
   J = lookup(First, "chiwawa");
   printIDs(J);
   printf("\n");
   printf("The Hash Driver file should print out: \n11 12\n1\n\n20\n");
   return 0;
}
