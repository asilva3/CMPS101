/*
 *    Header (.h) file for Hash ADT
 *
 *    This contains the operations and types exported
 *    by the module. The module implements the ADT
 *    "Hash Table" using dynamic memory allocation. The 
 *    state of the hash table is (possibl empty) sequance
 *    of HashHndl with first, current, last and pointer to
 *    ListHndl. 
 */

/*
 * The following defines the HashStruct type 
 * User should declare (and initialize to null)
 * one variable type is HashHndl for each Hashset
 * craeted. After declaration, the newhash
 * procedure must be called before any hash 
 * operations can be performed.
 */
#include <stdbool.h>
#include "List.h"

typedef struct Hashset* HashHndl;

/*
 * The procedure "newhash" creates a new hash object
 * This function should be used to create a new hash
 * before any operations are performed on that hash.
 */
HashHndl newhash(int size);

/* The method lookup returns the ListHndl of the book
 * searched for in the hash table
 */
ListHndl lookup(HashHndl table, char* bookname);

/* The method insert goes inside the correct slot in the 
 * hash table, searches up if there is a book
 * if not insert it in the ListHndl with the bookHndl as well
 * if there is already a book in there, go inside the 
 * ListHndl and insert the bookID inside the bookname's BookHndl.
 */
void insert(HashHndl table, char *bookname, long bookID);

/*
 * This method returns the integer of the bookstring so we know
 * where in the hash table to store the bookname in.
 * Credit to David Helmbod for giving us this method.
 */
unsigned long hash(char *bookname);
