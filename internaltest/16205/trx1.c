#include <stdio.h>
#include <stdlib.h>

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


int get_diameter_of_tree(TreeNode* root,TreeNode* mroot) {
    // Diameter of a tree is the length of its longest path
    int hl=0,hr=0;
    

    if(root)
     {
      
      hl=1+get_diameter_of_tree(root->left_node,mroot);
      hr=1+get_diameter_of_tree(root->right_node,mroot);
      if(root==mroot)
       return hl+hr;
      else if(hl>hr)
       return hl;
      else
       return hr;
     }
    else
     return 0;

}    	


int height(TreeNode *root)
{

int hl,hr;
    

    if(root)
     {
      
      hl=1+height(root->left_node);
      hr=1+height(root->right_node);
      if(hl>hr)
       return hl;
      else
       return hr;
     }
    else
     return 0;
}


int check_if_height_balanced(TreeNode* root) {
    // Return 1 if height of left and right subtree differ not more than by 1 and 
    // the left and right subtrees are height_balanced
  
   int l,r; 

    if(root)
     {
      
      l=height(root->left_node);
      r=height(root->right_node);
      if(l-r<2&&l-r>-2)
        return (check_if_height_balanced(root->left_node)&& check_if_height_balanced(root->right_node));
      else
       return 0;
     }
    else
     return 1;



}

void print_paths_to_all_leaves(TreeNode* root){
    // Print the complete paths to all the leaves of the tree
}

int main() {

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

   // printf("Diameter of the given Tree is %d\n",get_diameter_of_tree(root,root));

    if(check_if_height_balanced(root))
     printf("Tree is height balanced\n");
    else
     printf("Tree is not height balanced\n");

   
}

