#include<stdio.h>
#include<stdlib.h>




typedef struct node 
{
int data;
struct node *next;
}node;

node * createlinklist(node * start);
void display(node * start);




void main()
{
node *start=NULL;
start=createlinklist(start);
display(start);
}

node * createlinklist(node *start)
{
node *nn,*temp=NULL;
int x,i;
printf("how many nodes you want:");
scanf("%da",&x);
for(i=0;i<x;i++)
{
nn=(node *)malloc(sizeof(node));
nn->next=NULL;
printf("enter val:\n");
scanf("%d",&nn->data);

if(start==NULL)
{
start=temp=nn;
}
else
temp->next=nn;
temp=nn;
}
return start;
}


void display(node *start)
{
while(start!=NULL)
{
printf("%d -> ",start->data);
start=start->next;
}
printf(" NULL ");
}


struct node * insertatend(node *start)
{

return start;
}

