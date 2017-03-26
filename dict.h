#define NULL 0

char *alpha="abcdefghijklmnopqrstuvwxyz\0";

typedef struct dict
{
 int index;
 struct words *next[27];
}dict;


int getCharIndex(char ch)
{
 int i;
 for( i=0;i<27;i++)
 {
  if(ch==alpha[i])
   return i;
 }
 return -1;
}
 
dict *addNextChars(dict *d,char ch)
{
 int i;
 dict *n;
 //printf("%d",getCharIndex(ch));
 if(getCharIndex(ch)!=26)
 {
  n=(dict *)malloc(sizeof(dict)); 
  for(i=0;i<27;i++)
    n->next[i]=NULL;
  return d->next[getCharIndex(ch)]=n;
 }
 else
   return (d->next[getCharIndex(ch)]=NULL);
}

void insert(dict *d,char *w)
{
 int i=0;
 char ch;
 for(ch=w[i];ch!='\0';i++,ch=w[i])
 {
  
  //printf("\n%d\n%c",getCharIndex(ch),ch);
  d=addNextChars(d,ch);
  d->index=getCharIndex(ch);
 }
  d=addNextChars(d,ch);
  //printf("\n%d\n%c",getCharIndex(ch),ch);
} 


 
void search(dict *d,char *w)
{
 search_abst(d->next[getCharIndex(w[0])],w,' ',0);
}


void search_abst(dict *d,char *w,char ch,int i)
{
 ch=w[i];
 if((d)&&(i<strlen(w)))
 {
  if(ch==alpha[d->index])
  {
    printf("%c",alpha[d->index]);
    search_abst(d->next[getCharIndex(w[i+1])],w,ch,i+1);
  }
 }
 else if(i<strlen(w))
   printf("%s Not Found",w);
}

 
