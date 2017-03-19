#include "graph.h"

main()
{
 graph g;
 queue q1,q2;
 q1.top=NULL;
 q2.top=NULL;
 setVertices(&g,5);
 addEdge(&g,0,1);
 addEdge(&g,0,4);
 addEdge(&g,0,2);
 addEdge(&g,1,3);
 addEdge(&g,1,2);
 addEdge(&g,0,3);
 addEdge(&g,3,4);
 addEdge(&g,2,4);
 displayGraph(&g);
 
 printf("\nBFS Traversal for above graph is\n\n");

 bfs(&g,&q1,&q2,0);

 return 0;
}


