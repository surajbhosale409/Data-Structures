#include "dict.h"

main()
{
 int i;
 dict d;

 for(i=0;i<27;i++)
  d.next[i]=NULL;

 system("clear");

 insert(&d,"suraj");

 search(&d,"suraj");
 printf("\n");

 search(&d,"max");
 printf("\n");

 insert(&d,"softinfi");
 
 search(&d,"softinfi");
 printf("\n");



 return 0;
}
