/*
 * Author: Armando Silva, asilva3@ucsc.edu
 *
 * The program inputs vertices into a graph with
 * paths to certain vertices from certain vertices
 * and we try to find out the shortest path to get 
 * from one vertex to another vertex
 */

#include <stdio.h>
#include <string.h>
#include "BFS.h"
#include "List.h"


int main(int argc, char** argv)
{
   FILE* file;
   Graph G;
   int numVerts;
   int numQueries;
   int vert;
   int source;
   int destination;
   int i = 0;
   int j = 0;
   int count = 1024;
   char numEdges[1024];

   if(argc != 2)
   {
      printf("To run program: main [file input].\n");
      exit(1);
   }
   file = fopen(argv[1], "r");
   if(file == NULL)
   {
      printf("File %s is invalid.\n", argv[1]);
      exit(1);
   }
/*The first integer is the number of Vertices, Second is numver of paths quries in the file*/
   fscanf(file, "%d", &numVerts);
   fscanf(file, "%d", &numQueries);
   G = newGraph(numVerts);
/*Reading in the file, converting the characters into integers*/ 
   while(i<numVerts)
   {
      fscanf(file, "%d", &vert);
      fgets(numEdges, count, file);
      char* edge = strtok(numEdges, " \n");
      while(edge != NULL)
      {
         addEdge(G, vert, atoi(edge));
         edge = strtok(NULL, " \n");
      }
      ++i;
   }
/*Doing the methods from BFS.c, where we find the shortest path*/
   while(j<numQueries)
   {
      fscanf(file, "%d", &source);
      fscanf(file, "%d", &destination);
      doBFS(G, source);
      int distance = getDistance(G, destination);
      if(distance != 0)
      {
         ListHndl path = getPathTo(G, source,  destination);
         printList(path);
      }
      else
      {
         printf("No path from %d to %d. \n", source ,destination);
      }
      ++j;
   }
   fclose(file);
   return 0;
}




