
/*Author: Armando Silva, asilva3@ucsc.edu */
/****************************
 * The program inputs an integer from user
 * divides the number by two, if the remainder is 1 it's odd
 * pushes 1 on to stack. Pop off all numbers after done and print
 ****************************/
#include "myinclude.h"
#include "intstack.h"

int main()
{
   int number; 
   int temp;
   /* Initalizes a new stack */                           
   StackHndl StartingStack;               
   StartingStack = NULL;
   StartingStack = NewStack();

   printf("Input a positive decimal integer to conver to binary:\n");
   int input = scanf("%d", &number);
   temp = number;
   printf("Decimal %d is: ", temp);
   
   /*If the number is negative, catch and make invalid*/
   if(number <0)
      {
         printf("Invalid, Please choose positive value.");
      } 
   else
      {
         /* If number is 0, push 0 and finish */
         if(number == 0) 
            {                       
               Push(StartingStack, 0);
            }
         /*If number is grearter check to see if it is odd or even
          *Divide by two and check remainder to see odd or even
          *push 0 if even, 1 if odd
         */         
         while(number > 0){                
            if(number%2 == 1)
               {                   
                  Push(StartingStack, 1);  
               }  
            else 
               {
                  Push(StartingStack, 0);
               }
            number = number/2;
         }
         /*While the stack is not empty start popping off and printing*/
         while(!IsEmpty(StartingStack))
            {        
               printf("%d", Top(StartingStack));  
               Pop(StartingStack);
            }            
         printf(" in binary.\n");
   }
   /*Free the stack after finishing to ensure no memory leaks*/
   FreeStack(&StartingStack);
}
