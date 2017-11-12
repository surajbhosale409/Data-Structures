#include"bst.h"

int main()
{
 tnode *temptree,*root=NULL;
 queue *t,inordq,preordq,postordq,temp;
 inordq.top=preordq.top=postordq.top=temp.top=NULL;

 root=insert(root,10);
 root=insert(root,8);
 root=insert(root,14);
 root=insert(root,15);
 root=insert(root,12);
 root=insert(root,11);
 root=insert(root,13);
 root=insert(root,9);
 root=insert(root,6);
 root=insert(root,7);
 root=insert(root,5);
 root=insert(root,16);
   

 //printf("\n Pre-Order Traversal: ");
 //preorder(root,&preordq);
 
 printf("\nIn-Order Traversal: ");
 inorder(root,&inordq);

 //printf("\n Post-Order Traversal: ");
 //postorder(root,&postordq);

 printf("\n");
 printf("\nAfter deleting \n");
 delete_tnode(root,14,leaf(root,14));

 printf("\nIn-Order Traversal: ");
 inorder(root,&inordq);
 printf("\n");
 
 return 0;
}
