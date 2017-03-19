#include "graph.h"

main()
{
 graph g;
 

 setVertices(&g,5);
 addEdge(&g,0,1);
 addEdge(&g,0,4);
 addEdge(&g,0,2);
 addEdge(&g,1,3);
 addEdge(&g,1,2);
 addEdge(&g,2,3);
 addEdge(&g,3,4);
 display(&g);


 return 0;
}


