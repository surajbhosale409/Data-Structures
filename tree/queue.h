#include"stack.h"
#define NULL 0


typedef stack queue;
//here we are using stack datastructure itself which will work as queue stack's top will be queue's last element and stack's bottom will be queue's first element 
//just we will implement it in FIFO manner instead of LIFO



void add(queue *q,int val)
{

push(q,val);

}
 

int getfirst(node *list)
{
 if(list->next==NULL)
   return list->data;
 else
    getfirst(list->next);
}

int delete(queue *q)
{
 int val=getfirst(q->top);
 q->top=deleteend(q->top);
 return val;
}


