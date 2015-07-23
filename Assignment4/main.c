/*
 * Armando Silva, asilva3@ucsc.edu
 * Brandon Gomez, brlgomez@ucsc.edu
 * CS101- Spring 2014 - Assignment #4
 *
 * Source code (.c) file for the ADTs in my file directory
 *
 * This contains the implemntaitons of all my operations
 * and types exported by each .h file in my directory
 *
 * The objective of this .c file is to take in a file
 * to import a bookname and bookid, store them in the hash
 * at the correct ListHndl, unsorted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "List.h"
#include "hash.h"

int main(int argc, char **argv) {
   if (argc != 3) {
      printf("Program needs main file and two files to input.\n");
      exit(1);
   }else {
      char *insertFilename = argv[1];
      char *insertInput = argv[2];
      FILE *insertfile = fopen(insertFilename, "r");
      FILE *req = fopen(insertInput, "r");

      long line = 0;
      long hashsize =0;
      long bookid =0; 
      char bookbuffer[64];
      int i = 0;
      int j=0;
      
      char *buf = fgets(bookbuffer, sizeof(bookbuffer), insertfile);
      
      sscanf(bookbuffer, "%lu %lu", &line, &hashsize);
      HashHndl table = newhash(hashsize);

      while(i<line){
         char *buf = fgets(bookbuffer, sizeof(bookbuffer), insertfile); 
         if(buf = NULL)
         {
             break;
         }
         buf = strchr(bookbuffer, '\n');   
         *buf = '\0';
         sscanf(bookbuffer, "%lu", &bookid);
         char *title = strchr(bookbuffer, ',') +2;
         insert(table, title, bookid);
         ++i;
      }

      char *bookname = fgets(bookbuffer, sizeof(bookbuffer), req);
      while(j < line){
         char *bookname = fgets(bookbuffer, sizeof(bookbuffer), req);
         bookname = strchr(bookbuffer, '\n');
         if(bookname == NULL)
         {
             break;
         }
         *bookname = '\0';
         ListHndl IDList = newList();
         IDList = lookup(table, bookbuffer);
         if(IDList == NULL)
         {
            printf("\n");
         }
         else
         {
            printIDs(IDList);
         }
         ++j;
      }
   
      fclose(insertfile);
      fclose(req);
   }
   return 0;
}
