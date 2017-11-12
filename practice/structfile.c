#include<stdio.h>

struct temp
{
 int data[2];
};



main()
{
 FILE *fp;
 struct temp t[2],t1[2];
 int i;
 
 t[0].data[0]=1;
 t[0].data[1]=2;
 t[1].data[0]=3;
 t[1].data[1]=4;

 fp=fopen("temp.bin","w+");
 
 fwrite(&t,sizeof(struct temp),2,fp);
 fclose(fp);
 
 fp=fopen("temp.bin","r+");
 fread(&t1,sizeof(struct temp),2,fp);

 for(i=0;i<2;i++)
  printf("\n%d\t%d",t1[i].data[0],t1[i].data[1]);

return 0;
}
