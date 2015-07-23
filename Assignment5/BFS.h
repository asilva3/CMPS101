/*
 *    Header (.h) file for the BFS ADT
 *
 *    THis contains the operations and types exported
 *    by the module. The module implements the ADT
 *    "Breath First Search" using dynamic memory allocations.
 *    The state of a Breath First Search is a list handle 
 *    array that has linked lists with the List ADT.
 *
 */

/* The following defines the List methods 
 * this includes methods that printList, insert and have 
 * a the ListHndl
 */
#include "List.h"

/*
 * The following deinfes the GraphStruct type
 * User should declare( and initalize to null)
 * one variable type is Graph to handle the vertices in that graph
 */
typedef struct GraphStruct *Graph;

/* 
 * creates a new graph with n vertices numbered 0 to n and no edges
 * returns a handle to it.
 */
Graph newGraph(int n);

/*
 * adds the edges(from, to ) to the graph
 */
void addEdge(Graph G, int from, int to);

/*
 * performs BFS and updates teh graph's parent
 * and distance array. This will erase the results of any previous BFS.
 */
void doBFS(Graph G, int source);

/*
 * returns the number of edges in the shortest path from the last
 * BFS source to the destination. You can return 0 if there is no
 * path from the source destination.
 */
int getDistance(Graph G, int destination);

/*
 * Returns a List containing the path from the last
 * doBFS source to the destination or a null pointer if there
 * does not exist such path
 */
ListHndl getPathTo(Graph G, int source, int destination);


