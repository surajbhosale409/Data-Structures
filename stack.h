#include"sll.h"
#define STACK_MAXSIZE 5
#define NULL 0


typedef struct stack
{
  node *top;    
 //int size=0; we can find stack size without using size variable
}stack;





void push(stack *s,int val)
{

if(!isfull(s))
 {
 
 if(s->top==NULL) 
   s->top = newnode(s->top,val);
 else
   s->top = insertfront(s->top,val);  
 
// s->size++;  if we are using size variable to store no of elements in stack
 }
else
   printf("\nFull (i.e. contains %d elements) cannot push/add %d\n",size(s),val);
}
 


int pop(stack *s)
{
 int ele;

if(!isempty(s))
 {
 ele=s->top->data;
 s->top=deletefront(s->top);
 //s->size--; if we are using size variable to store no of elements in stack
 return ele;
 }
else
  printf("\nStack is Empty cannot pop\n");
}



int size(stack *s)
{

// return s->size;
 
 //if we dont have that size variable as member of stack we can find size by traversing stack from top to bottom as follows
 return length(s->top);


}



int isempty(stack *s)
{
 if(s->top==NULL)
   return 1;
 else
   return 0;
}



int isfull(stack *s)
{
 if(size(s)<STACK_MAXSIZE)
  return 0;
 else
   return 1;
}

