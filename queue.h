#include"stack.h"
#define NULL 0


typedef stack queue;
//here we are using stack datastructure itself which will work as queue stack's top will be queue's last element and stack's bottom will be queue's first element 
//just we will implement it in FIFO manner instead of LIFO



void add(queue *q,int val)
{

push(q,val);

}
 

void delete(queue *q)
{
 q->top=deleteend(q->top);
}


/*
we can define delete size isempty isfull functions for queue same as stack but here no need to redefine


int size(queue *q)
{

 return length(q->top);

}



int isempty(queue *q)
{
 if(q->bottom==NULL)
   return 1;
 else
   return 0;
}



int isfull(queue *q)
{
 if(size(q)<Q_MAXSIZE)
  return 0;
 else
   return 1;
}
*/



