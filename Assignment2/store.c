/*Author: Armando Silva, asilva3@ucsc.edu */
/*****************************
 * The program reads in the customerID number, 
 * indexs that number to the array
 * inputs the customer's bookID into that array
 * prints out the whole list
 *****************************/

#include "List.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
/*if the program doesn't take two parameters throw error*/ 
   if(argc != 3)
      {
         printf("Error: The program takes in two files.\n");
         return 1;
      }
   
   long totalcustomers = 0;
   long totalpurchases = 0;
   
   /*read and write the files*/
   FILE *file = fopen(argv[1], "r");
   FILE *out =  fopen(argv[2], "w");

   /*scans the number of total customers*/
   fscanf(file, "%ld", &totalcustomers);
   /*scans the number of total purchases*/
   fscanf(file, "%ld", &totalpurchases);

   fprintf(out, "The number of total customers are: %ld\n"
         "The number of total purchases were: %ld\n"  
           ,totalcustomers, totalpurchases);

   ListHndl* Array;
   Array = malloc(sizeof(ListHndl)* totalcustomers);

   int i=0;
   /*creates a list within that array index*/
   while(i<totalcustomers)
      {
         Array[i]= newList();
         ++i;
      }
   fprintf(out, "Customer #:            books purchased\n");

/*iterate through the file and record the customerID
 * store it inside the array index
 */
   for(;;){
      long bookID =0;
      long customerID = 0;
      /*scans the customerID number*/
      int rc = fscanf(file,"%ld", &customerID);
      /*scans the bookID number*/
      int cd = fscanf(file,"%ld", &bookID);
      if(rc == EOF)
         { 
            break;
         }else if(rc == 1){   
   /*I want to use custer ID to point to the array I want to use
    *And store the bookID in that array index 
     */
            insertAtFront(Array[customerID-1], bookID);
         }
   /*If the program reads bad input, throw error.*/
      else{
         printf("The file you inported has a bad input!");
         return 1;
      }
   }

/*prints out the array of the link list by calling the method
 * printList in my c file
 * then starts printing out the next array index
 */
   int j=0;
   while(j<totalcustomers)
   {
      fprintf(out, "%d    ", j+1);
      printList(out, Array[j]);
      fprintf(out, "\n");
      ++j;
   }
/*SUCCESS*/
 return 0;
} 
 

 

  

 
   

   
