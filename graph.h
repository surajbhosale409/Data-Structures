#include "queue.h"



typedef struct graph
{
 int vertex_count;
 int **edges;
}graph;


void setVertices(graph *g,int count)
{
 int i,j;
 g->vertex_count=count;
 g->edges=(int **)malloc(sizeof(int *)*count);
  for(i=0;i<count;i++)
      g->edges[i]=(int *)calloc(count,sizeof(int));

}

void addEdge(graph *g,int v1,int v2)
{
 g->edges[v1][v2]=1;
 g->edges[v2][v1]=1;
}

void addWeightedEdge(graph *g,int v1,int v2, int w)
{
 g->edges[v1][v2]=w;
 g->edges[v2][v1]=w;
}


void deleteEdge(graph *g,int v1,int v2)
{
 g->edges[v1][v2]=0;
 g->edges[v2][v1]=0;
}

void displayGraph(graph * g)
{
 int i,j;

 printf("Given graph (Adj. Matrix)\n\nv     ");
 for(i=0;i<g->vertex_count;i++)
   printf("%d  ",i);

 for(i=0;i<g->vertex_count;i++)
  {
   printf("\n%d => ",i);
   for(j=0;j<g->vertex_count;j++)
    { 
     printf(" %d ",g->edges[i][j]);
    }
  }
}


void bfs(graph *g,queue *q1,queue *q2,int v)
{

int i,j;

for(i=0;i<g->vertex_count;i++)
{
if(g->edges[v][i]==1)
 if((!ispresent(q1->top,i))&&(!ispresent(q2->top,i)))  
   add(q1,i);
}

printf("%d -> ",v);

add(q2,v);

//printf("\n%d",v);
//printf("\n");
//display(q1->top);
//printf("\n");
//display(q2->top);
if(!(length(q2->top)==g->vertex_count))
bfs(g,q1,q2,delete(q1));



}

 
void dfs(graph *g,stack *s,queue *q,int v)
{

int i;

push(s,v);
printf("%d => ",v);
add(q,v);


for(i=0;i<g->vertex_count;i++)
 if(g->edges[v][i]==1)
  if((!ispresent(s->top,i))&&(!ispresent(q->top,i)))
    dfs(g,s,q,i);
 
}

   
