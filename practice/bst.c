#include<stdio.h>
#include<stdlib.h>


typedef struct bst
{
 int data;
 struct bst *left,*ryt;
}bst;




bst * createbst(bst *root)
{

 bst *temp,*nn;

 nn = (bst *) malloc (sizeof(bst));
 nn->left=NULL;
 nn->ryt=NULL;

 printf("\nEnter Data\n");
 scanf("%d",&nn->data);

if(root==NULL)
 {
 root=temp=nn;
 }
 
else
 {
  temp=root;
 
 outer:
 
 if(nn->data<temp->data)
  {
   if(temp->left==NULL)
    temp->left=nn;
   else
   {
   temp=temp->left; 
   goto outer;
   }
  }
  else
  {
   if(temp->ryt==NULL)
    temp->ryt=nn;
   else
   { 
    temp=temp->ryt;
    goto outer;
   }
 
  } 
 }
 
 
return root;
}





void displaybst(bst *root)
{
 bst *temp1,*temp2;


}






main()
{
int n;
bst *root=NULL;

do
{
printf("\n1.Add Node to tree\n2.Display tree\n3.Exit\n");
scanf("%d",&n);

switch(n)
{
case 1: root=createbst(root);
        system("clear");
        break;
case 2: printf("\nContents of the tree are as follows:\n");
        displaybst(root);
        break;

case 3: break;
}

}while(n!=3);


return 0;

}

               
