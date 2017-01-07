#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


#define INT 1
#define CHAR 2
#define STRING 3
#define FLOAT 4
#define NODE 5

typedef struct node
{
 struct content *var;
 struct node *next;
}node;

struct content
{
 void *data;
 int type;
};

node * createnode(node *l);

void acceptdata(node *l)
{
 int t,*i;
 float *f;
 char *c,*str;
 node *n=NULL;
 
 printf("\n1.Integer data:\n2.Char data:\n3.String data:\n4.Float data:\n5.List as Data\nEnter your choice: ");
 scanf("%d",&t);
  
switch(t)
{
 case 1:i = (int *) malloc (sizeof(int));
        l->var->data=i;
        scanf("%d",i);
        l->var->type=INT;
        break;        
 case 2:scanf(" %c",c);
        l->var->data=c;
        l->var->type=CHAR;
        break;
 case 3:str = (char *) malloc (sizeof(char)*20);
        scanf(" %s",str);
        l->var->data=str;
        l->var->type=STRING;
        break;
 case 4:f = (float *) malloc (sizeof(float));
        l->var->data=f;
        scanf("%f",f);
        l->var->type=FLOAT;
        break;
 case 5:
        while(t!=2)
        {
         printf("\n1.Add Node to sublist.\n2.Done adding nodes to sublist\n");
         scanf("%d",&t);
         switch(t)
         {
          case 1: n = createnode(n);
                  break;
          case 2: l->var->data=n;
                  l->var->type=NODE;
                  break;
         }
        }
        break;
}

}



node * createnode(node *l)
{
 node *temp,*list; 
 list=l;

 if(l==NULL)
 {
  l=(node *) malloc (sizeof(node));
  l->var=(struct content *) malloc(sizeof(struct content));
  l->next=NULL;
  acceptdata(l);
  return l;
 }
 else if(l->next==NULL)
 {
  l->next=(node *) malloc (sizeof(node));
  l->next->var=(struct content *) malloc(sizeof(struct content));
  l->next->next=NULL;
  acceptdata(l->next);
 }
 else 
  temp=createnode(l->next);     
 
 return list;
}  



void display(node *l)
{
 if(l==NULL)
   return;
 else
 {
  switch(l->var->type)
  {
   case 1:printf(" %d ,",*((int *)l->var->data));
          break;
   case 2:printf(" %c ,",*((char *)l->var->data));
          break;
   case 3:printf(" %s ,",((char *)l->var->data));
          break;
   case 4:printf(" %f ,",*((float *)l->var->data));
          break;
   case 5:printf(" [ ");
          display((node *)l->var->data);
          printf(" NULL ] , ");
           break;
  }
  display(l->next);
 }
}

int main()
{
 node *list=NULL;
 int i;
 char *c;

 while(1)
{
 printf("\n1.Add Node to list:\n2.Display Contents of List:\n3.Exit\nEnter your Choice: ");
 scanf("%d",&i);

 switch(i)
 {
  case 1:system("clear");
         list=createnode(list);
         break;
  case 2:system("clear");
         printf(" [ ");
         display(list);
         printf(" NULL ]\n");
         printf("\n\nPress a key to continue: \n");
         scanf(" %c",c);
         break;
  case 3:exit(0);
         break;
 }
system("clear");
}
 
return 0;
}
