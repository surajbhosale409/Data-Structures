#include "graph.h"

main()
{
 graph g;
 stack s;
 queue q,q1,q2;
 
 s.top=NULL;
 q.top=NULL;
 q1.top=NULL;
 q2.top=NULL;


 system("clear");

 setVertices(&g,9);
 addEdge(&g,0,1);
 addEdge(&g,0,8);
 addEdge(&g,8,2);
 addEdge(&g,8,2);
 addEdge(&g,2,4);
 addEdge(&g,2,3);
 addEdge(&g,2,5);
 addEdge(&g,5,6);
 addEdge(&g,6,7);
 addEdge(&g,4,7);
 displayGraph(&g);
 
 printf("\n\nBFS Traversal for above graph is\n\n");

 bfs(&g,&q1,&q2,0);

 printf("\n\nDFS Traversal for above graph is\n\n");

 dfs(&g,&s,&q,0);

 printf("\n\n");
 return 0;
}


