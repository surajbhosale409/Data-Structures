#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list_node{
    int *node_value;
    struct linked_list_node * next;
} list_node;


void print_list( list_node* list_head ) {
    if( list_head == NULL ) {
        fprintf( stderr, "\n" ); 
    } else {
        fprintf( stderr, "%d " , *(list_head -> node_value) );
        print_list(list_head -> next );
    }
}

list_node* last_node( list_node* list_head ) {
    if( list_head -> next == NULL ) {
        return list_head;
    } else {
        return last_node( list_head-> next );
    }
}

list_node* new_node(int value) {
    list_node* new_node = (list_node*)malloc(sizeof(list_node));
    new_node -> node_value = (int*)malloc(sizeof(int));
    *(new_node -> node_value) = value;
    new_node -> next = NULL;
    return new_node;
}

list_node* add_to_list( list_node* list_head , int value){
    if( list_head ==NULL ){
        return new_node(value);
    } else {    
        last_node( list_head ) -> next = new_node(value);
        return list_head;
    }
} 

int length(list_node* list_head) {
    if( list_head ) {
        return 1 + length(list_head ->next);
    }
    return 0;
}

int pow(int b,int p)
{
 if(p==1)
  return b;
 else
  return (b*pow(b,p-1));
}


int concatenated_binary(list_node* list_head,int l) { 
    //    Input : 1 -> 0 -> 0 -> 1 -> 1 
    //    Output : 19 
    int o;
    if(list_head->next!=NULL)
    {
     o= (((*(list_head->node_value)*pow(2,l)) + (concatenated_binary(list_head->next,l-1)) ));
    }
    else
    { 
     if(*(list_head->node_value)==1)
      o=1;
     else
      o=0;
    }
  return o;
}

list_node* preserve_numbers_at_even_location(list_node* list_head,int p) {
    //    Input : 1 -> 2 -> 3 -> 4 -> 5 -> 7 
    //    Output : 2 -> 4 -> 7 
    list_node *t=NULL;
    
    
    if(p>0)    
    {
     if(p%2==0)
     {
      t=add_to_list(t,*(list_head->node_value));
      t->next=preserve_numbers_at_even_location(list_head->next,p-1);
     }
    else
    {
      if(t)
        t->next=preserve_numbers_at_even_location(list_head->next,p-1);
      else
        t=preserve_numbers_at_even_location(list_head->next,p-1);
    }
   }

   else
    return t;   

}

void* create_adjescancy_list(list_node* list_head) {
    // Input : 
    //    list : 1 -> 2 -> 1 -> 3 -> 2 -> 4 -> 4 -> 5 ,
    //    The list represents a graph with edges as (1,2) (1,3) (2,4) (4,5)
    // Output : 
    //    The adjescency list representation of the resulting graph 
    if(list_head->next->next!=NULL)
     {
      
     }



    return NULL;
}

int check_if_connected_in_graph(list_node* list_head, int source, int dest) {
    // Input : 
    //    list : 1 -> 2 -> 1 -> 3 -> 2 -> 4 -> 4 -> 5 , 
    //    source : 2
    //    destin : 5
    //    The list represents a graph with edges as (1,2) (1,3) (2,4) (4,5)
    // Output : 1
    //         since 2 to 5 is connected in the resultant graph
    int s;
    
    if(list_head)
    {
    if(list_head->next!=NULL)
    {
     if(*(list_head->node_value)==source)
     {

      if(*(list_head->next->node_value)==dest)
       return 1;
      else if(check_if_connected_in_graph(list_head->next->next,*(list_head->next->node_value),dest))
       return 1;
      else 
       return 0;
     }
     else
      return (check_if_connected_in_graph(list_head->next->next,source,dest));
    }
    }
    else
     return 0;

   


}


int main() {

    list_node* linked_list = NULL;

    list_node* edges = NULL;

    linked_list = add_to_list( linked_list , 1 );
    linked_list = add_to_list( linked_list , 0 );
    linked_list = add_to_list( linked_list , 0 );
    linked_list = add_to_list( linked_list , 1 );
    linked_list = add_to_list( linked_list , 1 );
    linked_list = add_to_list( linked_list , 0 );
  // linked_list = add_to_list( linked_list , 6 );
   // linked_list = add_to_list( linked_list , 7 );
   // linked_list = add_to_list( linked_list , 8 );
   // linked_list = add_to_list( linked_list , 4 );

    print_list( linked_list );
    fprintf(stderr,"Length of list : %d \n", length(linked_list));

    fprintf(stderr,"Concatenated Binary is %d\n",concatenated_binary(linked_list,(length(linked_list)-1)));


    linked_list = preserve_numbers_at_even_location( linked_list , length(linked_list) );
    print_list( linked_list );

    edges = add_to_list( edges , 1 );
    edges = add_to_list( edges , 2 );
    edges = add_to_list( edges , 1 );
    edges = add_to_list( edges , 3 );
    edges = add_to_list( edges , 2 );
    edges = add_to_list( edges , 4 );
    edges = add_to_list( edges , 4 );
    edges = add_to_list( edges , 5 );
    
   if(check_if_connected_in_graph(edges,2,5))
    printf("2 and 5 are connected\n");
   else
    printf("2 and 5 are not connected\n");

}



