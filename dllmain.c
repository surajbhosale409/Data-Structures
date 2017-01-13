#include"dll.h"

int main()
{
 node *l=NULL;

    printf("\nDoubly Linked List\n\nCalling createlist\n");
    l = createlist(l,10);
    display(l);
    printf("\nLength is : %d\n\n",length(l));


    printf("\nCalling insertend\n");
    l = insertend(l,20);
    display(l);
    printf("\nLength is : %d\n\n",length(l));

    printf("\nCalling insertfront\n");
    l = insertfront(l,30);
    display(l);
    printf("\nLength is : %d\n\n",length(l));

    printf("\nCalling deleteend\n");
    l = deleteend(l);
    display(l);
    printf("\nLength is : %d\n",length(l));

    printf("\nCalling deletefront\n");
    l = deletefront(l);
    display(l);
    printf("\nLength is : %d\n\n",length(l));

 return 0;
}

