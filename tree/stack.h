#include"sll.h"
#define STACK_MAXSIZE 50
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
   s->top = insertfront(s->top,val);  
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
 return ele;
 }
else
  printf("\nStack is Empty cannot pop\n");
}



int size(stack *s)
{
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

