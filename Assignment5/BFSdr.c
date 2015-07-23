#include "BFS.h"
#include "List.h"

int main()
{
   Graph G = newGraph(6);
   addEdge(G, 5, 2);
   addEdge(G, 0, 1);
   addEdge(G, 0, 2);
   addEdge(G, 1, 1);
   addEdge(G, 2,  3);
   addEdge(G, 2, 4);
   addEdge(G, 3, 4);
   addEdge(G, 4, 3);
   addEdge(G, 4, 2);
   
   doBFS(G, 0);

   ListHndl L = getPathTo(G, 0, 4);
   printList(L);
   doBFS(G, 4);
   ListHndl W = getPathTo(G, 4, 0);
   printList(W);
}
