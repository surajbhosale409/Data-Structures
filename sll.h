
#define NULL 0


typedef struct node
{
 int data;
 struct node *ltree,*rtree;
}node;




//for allocating memory to new node
node * newnode(node *l,int val)
{

 l=(node *) malloc (sizeof(node));
 l->data=val;
 l->ltree=NULL;
 l->rtree=NULL;
 return l;
}


//for inserting new node at end
node * insert(node *l,int val)
{
 if(l==NULL)
   return newnode(l,val);
 else
 {
  if(!l->ltree)
   l->ltree=insert(l->ltree,val);
  else if(!l->rtree)
   l->rtree=insert(l->rtree,val);
  else if(l->ltree)
    return l->ltree;
  else if(l->rtree)
    return l->rtree;
  else 
  {
   l->ltree->ltree=insert(l->ltree,val);
   l->ltree->rtree=insert(l->ltree,val);
  }
  return l;
 } 
}

/*

//for deleting node from end
node * deleteend(node *l)
{
 if(l->next==NULL)
  {
   free(l); 
   return NULL;
  }  
 else
  {
   l->next=deleteend(l->next);
   return l;
  }
}


//for deleting node from front
node * deletefront(node *l)
{
  node *temp=l->next;
  free(l);
  return temp;
}




//returns no of nodes in list
int length(node *l)
{
 if(l==NULL)
   return 0;
 else 
    return (1+length(l->next));
}

*/


void display(node *l)
{
  if(l==NULL)
    return ;
  else
  {
   printf("%d\t",l->data);
   display(l->next);
  }
}


//creates first node i.e. root of tree i.e. creating list
node * createtree(node *l,int val)
{
 return insertend(l,val);
}


