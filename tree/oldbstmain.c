#include"bst.h"

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

