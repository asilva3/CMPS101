/*
 * Armando Silva, asilva3@ucsc.edu
 * Brandon Gomez, brlgomez@ucsc.edu
 * CS 101 - Spring 2014 - Assignment #4
 * Kevin Thai helped with concept of using a ListHndl pointing to linked list of bookIDs
 * The hash.c file is the methods used in Hashdr and Main
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"
#include "List.h"

/*The hash struct creates a hash table with a size, and a pointer
 * to ListHndl of books.
 */
typedef struct Hashset
{
   int size;
   ListHndl* book;
}Hashset;

/*creates our hash table with book nodes to create a new Hndl each*/
HashHndl newhash(int size)
{
   int i;
   HashHndl table;
   table = malloc(sizeof (Hashset));
   assert (table != NULL); 
   table->size = size;
   table->book = malloc(table->size * sizeof(ListHndl));
   while(i < table->size)
   {
      table->book[i] = newList();
      ++i;
   } 
   return table;  
}

/*This method lookup() checks to see if there is
 * the book you want in our library
 */
ListHndl lookup(HashHndl table, char* bookname)
{
   unsigned long bookhash = hash(bookname);
   int arraycount = bookhash % table->size;
   ListHndl curr = newList();
   curr = table->book[arraycount];
   if(isEmpty(curr))
   {
      return NULL;
   }
   else{
      moveFirst(curr);
      while(!offEnd(curr))
      {
         char* compare = (char*) getCurrent(curr);
         if(strcmp(compare, bookname) == 0) 
         {
            return returnid(curr);
         }
         moveNext(curr);
      }
      return NULL;
   }
}   

/*This method insert() inserts the bookname and bookID
 * if there is not the same book, But if there is the same
 * book then just insert the bookID.
 */
void insert(HashHndl table, char *bookname, long bookID)
{
   char* book = malloc (strlen(bookname) * sizeof(char));
   unsigned long bookhash = hash(bookname);   
   int arraycount = bookhash % table->size;
   long* iddata = malloc(sizeof(long));
   *iddata = bookID;
   strcpy(book, bookname);
   ListHndl bookList = newList();
   bookList = lookup(table, book); 
   if(bookList != NULL)
   {
      insertAtBack(bookList, iddata);
   }
   else
   {
      bookList = newList();
      insertAtBack(bookList, iddata);
      strcpy(book, bookname);
      pointbook(table->book[arraycount], book, bookList);
   }
}

/*djb2 hashing function from http://www.cse.yorku.ca/~oz/hash.html*/
unsigned long hash(char *bookname)
{
   unsigned long hash = 5381;
   int c = 0;

   while(c == *bookname++)
   {
      hash = ((hash << 5) +hash) + c; 
   }
   return hash;
}
