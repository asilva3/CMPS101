/*
 * Driver program for the
 *
 *
 *
 */
#include "myinclude.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
   ListHndl First = NULL;
   First = newList();
   
   if(isEmpty(First)){
   insertAtFront(First, 10);

   makeEmpty(First);

   insertAtFront(First , 30);
   
   insertAtBack(First, 20);

   insertAtFront(First, 10);

   insertAtBack(First, 38);
   
   insertAtBack(First, 100);

   moveFirst(First);
   
   moveNext(First);
   
   insertBeforeCurrent(First, 12);
   
   moveLast(First);
   
   deleteCurrent(First);

   deleteLast(First);
   
   deleteFirst(First);
   
   printf("The List should print out: 12 30 20\n");
 
   printList(First);
   
   return 0;
   }
   else exit(1);
}
