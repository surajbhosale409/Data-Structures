#define NULL 0
#include"queue.h"

typedef struct tnode
{ 
 int val;
 struct tnode *left,*ryt;
}tnode;

tnode * newtnode(int val)
{
 tnode *nn=(tnode *) malloc (sizeof(tnode));
 nn->ryt=NULL;
 nn->left=NULL;
 nn->val=val;
 return nn;
}


tnode * insert(tnode * root,int val)
{
 if(root)
 {
   if(val<root->val)
    root->left=insert(root->left,val);
   else 
    root->ryt=insert(root->ryt,val);
   
   return root;
 }
 else
   return newtnode(val);
}

/* preorder customized do not use 
void display(tnode *root,char *status)
{
 if(root)
 {
  printf(" %d [%s] \n",root->val,status);
  display(root->left,"LEFT");
  display(root->ryt,"RYT");
 }
 else
   return ;
}
*/


tnode * mirror(tnode *root)
{
 tnode *temp;

 if(root)
 {
   temp=root->left;
   root->left=mirror(root->ryt);
   root->ryt=mirror(temp);
   return root;
 }
 else
   return NULL;

}



int isBST(tnode *root)
{
  if(root&&root->left&&root->ryt)
  {
   return (((root->left->val<root->val)&&(root->ryt->val>root->val)) && (isBST(root->left) && isBST(root->ryt) ));
  }
  else
   return 1;
}







int search(tnode *root,int val)
{

 if(root)
 {
  if(val==root->val)
    return 1;
  else if(val<root->val)
    return search(root->left,val);
  else 
   return search(root->ryt,val);
 }
 else
  return 0;
}


 

int sum(tnode *root)
{
 if(root)
  return (root->val+sum(root->left)+sum(root->ryt));
 else
  return 0;
}


int maxsumsubstrand(tnode *root)
{
 if(root)
 {
  if((root->val+maxsumsubstrand(root->left))>(root->val+maxsumsubstrand(root->ryt)))
    return (root->val+maxsumsubstrand(root->left));
  else
  return (root->val+maxsumsubstrand(root->ryt));
 }
 else
   return 0;
}



int max(tnode *root)
{
 if(root->ryt)
  return max(root->ryt);
 else
  return root->val;
}

int min(tnode *root)
{
 if(root->left)
   return min(root->left);
 else
   return root->val;
}


tnode * gettnodeparent(tnode *root,int val)
{

 if(root)
 {
  if(root->left->val==val||root->ryt->val==val)
   return root;
  else if(val<root->val)
    return gettnodeparent(root->left,val);
  else
    return gettnodeparent(root->ryt,val);
 }
}

tnode * gettnode(tnode *root,int val)
{

 if(root)
 {
  if(root->val==val)
   return root;
  else if(val<root->val)
    return gettnode(root->left,val);
  else
    return gettnode(root->ryt,val);
 }
}

void inorder(tnode *root,queue *q)
{
 if(root)
 {
 inorder(root->left,q);
 add(q,root->val);
 printf("\t%d",root->val);
 inorder(root->ryt,q);
 }
}




void preorder(tnode *root,queue *q)
{
 if(root)
 {
 add(q,root->val);
 printf(" %d [",root->val);
 preorder(root->left,q);
 preorder(root->ryt,q);
 printf(" ] ");
 }
}

void postorder(tnode *root,queue *q)
{
 if(root)
 {
 postorder(root->left,q);
 postorder(root->ryt,q);
 add(q,root->val);
 printf("\t%d",root->val);
 }
}


int leaf(tnode *root,int val)
{
 if(root)
 {
  if(root->val==val && root->left==NULL && root->ryt==NULL)
   return 1;
  else if(val<root->val)
   return leaf(root->left,val);
  else
   return leaf(root->ryt,val);
 }
else
  return 0;
}


tnode *delete_leaf(tnode *root,int val)
{
 if(root)
 {
  if(root->left->val==val)
  {
   free(root->left);
   root->left=NULL;
  }
  else if(root->ryt->val==val)
  {
   free(root->ryt);
   root->ryt=NULL;
  }
  else if(val<root->val)
   delete_leaf(root->left,val);
  else if(val>root->val)
   delete_leaf(root->ryt,val);
 }

}



void delete_tnode(tnode *root,int val,int leafflag)
{
 int replaceval;
 tnode *dparent,*dnode;
if(root)
{  

 if(leafflag)
  delete_leaf(root,val);

 else if(root->val==val)
  {
   
   if(root->left)
    {
     replaceval=max(root->left);
     dnode=gettnode(root,replaceval);
     dparent=gettnodeparent(root,replaceval);
     if(dparent==root)
      dparent->left=dnode->left;
     else
      dparent->ryt=dnode->left;
     
     free(dnode);
     root->val=replaceval;
    }  
  
   else if(root->ryt)
    {
     replaceval=min(root->ryt);
     dnode=gettnode(root,replaceval);
     dparent=gettnodeparent(root,replaceval);
      if(dparent==root)
      dparent->ryt=dnode->ryt;
     else
      dparent->left=dnode->ryt;

     free(dnode);
     root->val=replaceval;
    }
  }

  else if(val<root->val)
   delete_tnode(root->left,val,leafflag);

  else
   delete_tnode(root->ryt,val,leafflag);
 }
}
