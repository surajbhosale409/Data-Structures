#define NULL 0

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


void inorder(tnode *root)
{
 inorder(root->left);
 printf("%d\t",root->val);
 inorder(root->ryt);
}


int main()
{
 tnode *root=NULL;
 root=insert(root,5);
 root=insert(root,4);
 root=insert(root,6);
 root=insert(root,9);
 root=insert(root,7);
 display(root,"ROOT");

 printf("\n");

 if(isBST(root))
  printf("\nBST");
 else
  printf("\nNOT BST");



 
 root=mirror(root);

 printf("\n");
 printf("\n");

 display(root,"ROOT");
 
 printf("\n");

 if(isBST(root))
  printf("\nBST");
 else
  printf("\nNOT BST");

 root=mirror(root);

 printf("\n");

 if(search(root,4))
  printf("\n4 FOUND");
 else
  printf("\n4 NOT FOUND");

 printf("\n");

 if(search(root,10))
  printf("\n10 FOUND");
 else
  printf("\n10 NOT FOUND");

 printf("\nSum of tree elements is %d\n",sum(root));
 
 printf("\nSubstrand having maximum sum in tree is %d\n",maxsumsubstrand(root));


 root=insert(root,20);
 printf("\n\n");

 display(root,"ROOT");

 printf("\n"); 
 printf("\nMax element in tree is %d\n",max(root));


return 0;
}

