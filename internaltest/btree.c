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


int height(TreeNode *root)
{
//maximum level in tree is the height of that tree calculate and return it
    hl=1+height(root->left_node);
    hr=1+height(root->right_node);
    return (hl>hr?hl:hr);
  
}


int get_diameter_of_tree(TreeNode* root,TreeNode* mroot) {
    // Diameter of a tree is the length of its longest path
 return 0;
}    	



int check_if_sum_balanced(TreeNode* root) {
    // Return 1 if height of left and right subtree differ not more than by 1 and 
    // the left and right subtrees are height_balanced
     return 1;
}

int check_if_height_balanced(TreeNode* root) {
    // Return 1 if height of left and right subtree differ not more than by 1 and 
    // the left and right subtrees are height_balanced
     return 1;
}

void print_level_wise_nodes(TreeNode *root)
{
// Print all the nodes of tree level wise
}

void print_paths_to_all_leaves(TreeNode* root,char str[]){
    // Print the complete paths to all the leaves of the tree


}


void print_siblings(TreeNode *root)
{
 //if nodes are at same level having same parent they are siblings, print them
}


void print_cousins(TreeNode *root)
{
 //if nodes are at same level  having different parent they are cousins, print them 
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


    return 0;
}

