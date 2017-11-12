
#include<stdio.h>



typedef struct node
{
 int data;
 struct node *next;
}node;




node * createlist(node *list)
{
 
 node *temp,*nn;

 nn = (node *) malloc (sizeof(node));
 nn->next=NULL;
 printf("\nEnter Data\n");
 scanf("%d",&nn->data);
 
 if(list==NULL)
 {
 list=temp=nn;
 }
 else
 {
  for(temp=list;temp->next!=NULL;temp=temp->next);
   temp->next=nn;
 }
return list;
}





void displaylist(node *list)
{
 
 node *temp;

  for(temp=list;temp!=NULL;temp=temp->next)
 {
  printf(" %d -> ",temp->data);
 }
 printf(" NULL\n");
  
}






main()
{
int n;
node *list=NULL;

do
{
printf("\n1.Add Node to list\n2.Display list\n3.Exit\n");
scanf("%d",&n);

switch(n)
{
case 1: list=createlist(list);
        system("clear");
        break;
case 2: printf("\nContents of the list are as follows:\n");
        displaylist(list);
        break;

case 3: break;  
}

}while(n!=3);
      

return 0;

}

