#include<sys/socket.h>

main()
{
 char *p;
 p=(char *) malloc (sizeof(char)*20);
 gets(p); 
 void *ptr;
 ptr=p;
 printf("%s",((char *)ptr));
return 0;


}

