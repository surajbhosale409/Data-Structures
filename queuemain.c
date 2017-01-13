#include"queue.h"


int main()
{
 queue q;
 q.top = q.bottom = NULL;

 printf("\nQueue Using (stack) singly linked list\n");
 if(isempty(&q))
  printf("\n\nCurrently queue is empty\n");

 printf("\n\nAdding a element\n");
 add(&q,1);

 printf("\n\nAdding a element\n");
 add(&q,2);

 printf("\n\nQueue contents right now: last --------> first\n");
 display(q.top);


 printf("\n\nDeleting a element\n");
 delete(&q);

 printf("\n\nQueue contents right now: last --------> first\n");
 display(q.top);

 printf("\n\nAdding a element\n");
 add(&q,3);

 printf("\n\nAdding a element\n");
 add(&q,4);

 printf("\n\nAdding a element\n");
 add(&q,5);

 printf("\n\nAdding a element\n");
 add(&q,6);

 printf("\n\nNo of elements in queue is %d \n",size(&q));

 printf("\n\nQueue contents right now: last --------> first\n");
 display(q.top);


 printf("\n\nAdding a element\n");
 add(&q,7);

 printf("\n\nQueue contents right now: last --------> first\n");
 display(q.top);

 printf("\n\nDeleting a element\n");
 delete(&q);

 printf("\n\nAdding a element\n");
 add(&q,7);

 printf("\n\nQueue contents right now: last --------> first\n");
 display(q.top);

 return 0;
}

