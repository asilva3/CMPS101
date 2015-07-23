/*
 * Armando Silva, asilva3@ucsc.edu
 * CS101 - Spring 2014, Assignment #5
 * The List.c is the methods used in the List.h
 * This file is used in BFSdr.c and main.c
 */

#include "List.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * These are the variables used to describe a vertex in our
 * graph, the colors to determined if the vertex had been
 * visted
 */
int parent = -1;
int white = 0;
int grey = 1;
int black = 2;
int nopath = 0;


typedef struct GraphStruct
{
   ListHndl* vertices;
   int* color;
   int* parent;
   int* distance;
   int numVertices;
   int numEdges;
}*Graph;

/*
 * The method newGraph() initializes and returns
 * a new "graph".
 * THE DISTANCE IF NO PATH WILL BE 0. 
 */
Graph newGraph(int n)
{
   int i = 0;
   Graph G = malloc(sizeof(struct GraphStruct));
   G->vertices = calloc(n, sizeof(ListHndl));
   G->color = calloc(n, sizeof(int));
   G->parent = calloc(n , sizeof(ListHndl));
   G->distance = calloc(n, sizeof(int));
   G->numVertices = 0;
   G->numEdges = 0;
   while(i < n)
   {
      G->vertices[i] = newList();
      G->color[i] = white;
      G->parent[i] = parent;
      G->distance[i] = nopath;
      G->numVertices = G->numVertices + 1;
      ++i;
   }
   return G;
}

/*
 * The method addEdge(), inserts a vertex
 * on the graph at the back using a List method
 * and adds the number of vertices in a graph
 */
void addEdge(Graph G, int from, int to)
{
  insertAtBack(G->vertices[from], to);
  G->numEdges = G->numEdges +1; 
}

/*
 * The method doBFS() creates a ListHndl
 * with however many vertices there are and starts
 * inserting them. Then when inserting the color changes
 * after being visited and while not empty
 * create another list and update the parents and colors of that
 * list
 */
void doBFS(Graph G, int source)
{
   ListHndl L = newList();
   int i = 0;
   while(i < G->numVertices)
   {
      G->color[i] = white;
      G->distance[i] = 0;
      G->parent[i] = parent;
      ++i;
   }
   insertAtBack(L, source);
   G->color[source] = grey;
   G->distance[source] = 0;
   while(!isEmpty(L))
   {
      int current = getFirst(L);
      ListHndl eList = G->vertices[current];
      moveFirst(eList);
      while(!offEnd(eList))
      {
         int edge = getCurrent(eList);
         if(G->color[edge] == white)
         {
            G->distance[edge] = G->distance[current]+1; 
            G->color[edge] = grey;
            G->parent[edge] = current;
            insertAtBack(L, edge);
         }
         moveNext(eList);
      }
   deleteFirst(L);
   G->color[current] = black;
   }
}

/*
 * The method getDistance() returns an 
 * integer of the smallest path to that destination
 */
int getDistance(Graph G, int destination)
{
   return G->distance[destination];
}

/*
 * The method getPathTo returns  a ListHndl
 * that gets the shortest path from the soruce ot the 
 * destination
 */
ListHndl getPathTo(Graph G, int source, int destination)
{
   ListHndl path = newList();
   int nextUp = destination;
   if(nextUp == nopath)
   {
      printf("No path from %d to %d exists.\n", source,  nextUp);
      return path;
   }
   printf("The shortest path from %d to %d: \n", source, nextUp);
   while(nextUp != parent)
   {
      insertAtFront(path , nextUp);
      nextUp = G->parent[nextUp];
   }
   return path;
}

