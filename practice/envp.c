#include<stdio.h>

main(int argc, char **argv,char **envp)
{

int i=0;

for(i=0;i<20;i++)
 printf("\n%s",envp[i]);

return 0;


}
