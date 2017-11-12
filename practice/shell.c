#include<stdio.h>
#include<unistd.h>



int getcmdcode(char cmd[])
{
  if(strcmp(cmd,"cat"))
     return 1;
     
  if(strcmp(cmd,"echo"))
     return 2;
  
  if(strcmp(cmd,"clear"))
     return 3;
  
}


main()
{
  int n,i,c;
  char ch,cmd1[500],cmd[200],op1[200],op2[200];
  FILE *fp;
  
  strcpy(cmd,"temp");
  
  do
    {
      printf("\nsuraj~$ ");
      gets(cmd1);
      printf("%s\n",cmd1);
      sscanf(cmd1,"%s%s",cmd,op1);
      printf("%s\n%s",cmd,op1);
       
      c=getcmdcode(cmd);

      switch(c)
	{
	case 1:  fp=fopen(op1,"r");
                 while(!feof(fp))
                 {
                  ch=fgetc(fp);
                  putchar(ch);
                 } 

	         break;
		 
	case 2:  
                 printf("%s",op1);
	         break;
		 
	case 3:  system("clear");
                 break;
		 
	default: break;
	}

    }while(strcmp(cmd,"exit")!=0);

  return 0;
}


      
