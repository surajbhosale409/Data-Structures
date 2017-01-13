#include"stack.h"


int main()
{
 stack s;
 s.top = s.bottom = NULL;

 printf("\nStack Using singly linked list\n");
 if(isempty(&s))
  printf("\nCurrently stack is empty\n");

 printf("\nPushing a element\n");
 push(&s,7);

 printf("\nPushing a element\n");
 push(&s,8);

 printf("\nStack contents right now: top --------> bottom\n");
 display(s.top);


 printf("\n\nCalling Pop\n");
 printf("\nPopped element is %d\n",pop(&s));

 printf("\n\nStack contents right now: top --------> bottom\n");
 display(s.top);

 printf("\n\nPushing a element\n");
 push(&s,10);

 printf("\n\nPushing a element\n");
 push(&s,20);

 printf("\n\nPushing a element\n");
 push(&s,15);

 printf("\n\nPushing a element\n");
 push(&s,18);

 printf("\n\nNo of elements in stack is %d \n",size(&s));

 printf("\n\nPushing a element\n");
 push(&s,25);

 printf("\n\nStack contents right now: top --------> bottom\n");
 display(s.top);

 printf("\n\nCalling Pop\n");
 printf("\nPopped element is %d\n",pop(&s));

 printf("\n\nPushing a element\n");
 push(&s,25);

 printf("\n\nStack contents right now: top --------> bottom\n");
 display(s.top);

 return 0;
}

