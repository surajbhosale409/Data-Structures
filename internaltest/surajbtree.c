#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
 int data,level;
 struct node *next;
}node;

typedef struct tree_node_struct {
    int node_data;
    struct tree_node_struct* left_node;
    struct tree_node_struct* right_node;
} TreeNode;

TreeNode* create_node( int value ) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node -> node_data = value;
    new_node -> left_node = NULL;
    new_node -> right_node = NULL;
}


void postorder( TreeNode *root ) {

    if( root == NULL ) {
        fprintf(stderr,"[ ] ");
        return;
    }
   fprintf(stderr,"[ ");
   fprintf(stderr,"%d ",root->node_data);
   postorder( root -> left_node );
   postorder( root -> right_node );
   fprintf(stderr,"] ");

}

int sum(TreeNode *root)
{
 if(root)
  return (root->node_data + sum(root->left_node) + sum(root->right_node));
 else
  return 0;
}

int height(TreeNode *root)
{
//maximum level in tree is the height of that tree calculate and return it
    if(root)
    {
     int hl=1+height(root->left_node);
     int hr=1+height(root->right_node);
     return (hl>hr?hl:hr);
    }
    else
     return 0;
}


int get_diameter_of_tree(TreeNode* root,TreeNode* mroot) {
    // Diameter of a tree is the length of its longest path
      

 return 0;
}    	



int check_if_sum_balanced(TreeNode* root) {
    // Return 1 if height of left and right subtree differ not more than by 1 and 
    // the left and right subtrees are height_balanced
   int sl,sr;
   if(root)
   {
    sl=sum(root->left_node);
    sr=sum(root->right_node);
    if(sl-sr==0)
     return (check_if_sum_balanced(root->left_node) && check_if_sum_balanced(root->right_node));
    else
     return 0;
   }
   else
    return 1;
}



int check_if_height_balanced(TreeNode* root) {
    // Return 1 if height of left and right subtree differ not more than by 1 and 
    // the left and right subtrees are height_balanced
   int hl,hr;
   if(root)
   {
    hl=height(root->left_node);
    hr=height(root->right_node);
    if((hl-hr)>=-1 && (hl-hr)<=1)
     return (check_if_height_balanced(root->left_node) && check_if_height_balanced(root->right_node));
    else
     return 0;
   } 
   else
    return 1;
}


node * insertfront(node *list,int data,int l)
{
 node *nn=(node *)malloc(sizeof(node));
 nn->data=data;
 nn->level=l;
 nn->next=list;
 return nn;
}


void display_tlist(node *list)
{
 if(list)
 {
  printf(" (%d,%d) -> ",list->data,list->level);
  display_tlist(list->next);
 }
}


node * treetolist(TreeNode *root,node *list,int l)
{
if(root)
{
 list=insertfront(list,root->node_data,l);
 list=treetolist(root->left_node,list,l+1);
 list=treetolist(root->right_node,list,l+1);
 return list;
}
else
 return list;

}


void print_level_wise_nodes(TreeNode *root)
{
// Print all the nodes of tree level wise
 node *treelist=treetolist(root,NULL,1);
// display_tlist(treelist);
 node *temp;
 int l;

 l=1;
 
 while(l<=height(root))
 {
  temp=treelist;
  printf(" [ ");
  while(temp!=NULL)
  {
   if(temp->level == l)
    printf(" %d ", temp->data);
   temp=temp->next;
  }
  printf(" ] \t\t at level %d\n",l);
  l++;
 }

}



void print_paths_to_all_leaves(TreeNode* root,char str[]){
    // Print the complete paths to all the leaves of the tree


}


TreeNode * gettnodeparent(TreeNode *root,int val)
{
 if(root)
  {
   if(root->left_node)
   if(root->left_node->node_data==val)
     return root;

   if(root->right_node)
   if(root->right_node->node_data==val)
     return root;
   
   else
    {
     gettnodeparent(root->left_node,val);
     gettnodeparent(root->right_node,val);
    }

  }
}


void print_siblings(TreeNode *root)
{
 //if nodes are at same level having same parent they are siblings, print them
 node *temp,*temp1,*treelist=treetolist(root,NULL,1);
 int l,d1,d2;
 TreeNode *p1,*p2;

 
 l=2;
 while(l<=height(root))
 {
 temp=treelist;
 while(temp!=NULL)
 {
  if(temp->level==l)
  {
   d1=temp->data;
   temp1=temp->next;
   while(temp1!=NULL)
   {
    if(temp1->level==l)
    {
     d2=temp1->data;
     p1=gettnodeparent(root,d1);
     p2=gettnodeparent(root,d2);
     if(p1==p2)
      printf(" [%d,%d] are siblings\n",d1,d2);
    }
     temp1=temp1->next;
   }
  }
  temp=temp->next;
 }
 l++;
 }
}


void print_cousins(TreeNode *root)
{
 //if nodes are at same level  having different parent they are cousins, print them 
 node *temp,*temp1,*treelist=treetolist(root,NULL,1);
 int l,d1,d2;
 TreeNode *p1,*p2;

 
 l=2;
 while(l<=height(root))
 {
 temp=treelist;
 while(temp!=NULL)
 {
  if(temp->level==l)
  {
   d1=temp->data;
   temp1=temp->next;
   while(temp1!=NULL)
   {
    if(temp1->level==l)
    {
     d2=temp1->data;
     p1=gettnodeparent(root,d1);
     p2=gettnodeparent(root,d2);
     if(p1!=p2)
      printf(" [%d,%d] are cousins\n",d1,d2);
    }
     temp1=temp1->next;
   }
  }
  temp=temp->next;
 }
 l++;
 }


}


int main() {
    int ishb;
    TreeNode* root = create_node( 1 );
    
    TreeNode* node_1 = create_node( 2 );
    TreeNode* node_2 = create_node( 3 );
    TreeNode* node_3 = create_node( 4 );
    TreeNode* node_4 = create_node( 5 );
    TreeNode* node_5 = create_node( 6 );
    TreeNode* node_6 = create_node( 7 );
    TreeNode* node_7 = create_node( 10 );
    TreeNode* node_8 = create_node( 8 );
    TreeNode* node_9 = create_node( 9 );

    root -> left_node = node_1;
    root -> right_node = node_2;

    node_1 -> left_node = node_3;
    node_1 -> right_node = node_4;

    node_2 -> left_node = node_5;
    node_2 -> right_node = node_6;

    node_6 -> right_node = node_7;
    node_7 -> right_node = node_8;
    node_8 -> right_node = node_9;

    postorder(root);
    printf("\n");
    
    if(check_if_height_balanced(root))
     printf("\nTree is height balanced");
    else 
     printf("\nTree is not height balanced");
    
    if(check_if_sum_balanced(root))
     printf("\nTree is sum balanced");
    else 
     printf("\nTree is not sum balanced");

    printf("\n\n");
    print_level_wise_nodes(root);
    printf("\n\n");


    printf("\n\n");
    print_siblings(root);
    printf("\n\n");


    printf("\n\n");
    print_cousins(root);
    printf("\n\n");



    return 0;
}

