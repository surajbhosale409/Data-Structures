#include<stdio.h>
#include<stdlib.h>

typedef struct node
{  
	int data;
	struct node *next;
	struct node *prev;
	
}Node;


//create node

Node *create(int val)
{
	Node *temp=NULL;
	Node *nn=NULL;
	Node *head=NULL;

		nn=(Node *)malloc(sizeof(Node *));
		nn->next=NULL;
		nn->prev=NULL;
                nn->data=val;    
		/*if(head==NULL)
		{
		return head ;
		}
		else
		  {
		   for(temp=head;temp->next!=NULL;temp=temp->next)
	            {
	             temp->next=nn;
		     nn->prev=temp;
		    }
                  }
		else
		{       head=temp;
			temp=nn;
		}
	*/
	return nn;
}

/*int display(Node *head)
{
                        Node *temp;
			
			int val;
			if(head==NULL)
			{ 
                        return 0; 
			}
			else
			{
				temp=head;
				while(temp!=NULL)
				{
                                printf("%d ->",head->data);
			        head=head->next;
	                       }
			}
return 0;				
}*/

//display node

void display(Node *head)
{
	Node *temp;
	while(temp!=NULL)
	{
		printf(" %d ->",temp->data);
		temp=temp->next;
	}
	
}



//insert at first
Node *insert_first(Node *head,int val)
{
 Node *nn;
 if (head==NULL)
 {
	 head=create(val);
	 return head;
 }
 else 
 {
	nn=(Node *)malloc(sizeof(Node));
	nn->prev=NULL;
	nn->next=NULL;
	nn->data=val; 
	nn->next=head;
        head->prev=nn;
	head=nn;
      
 }
 return head;
}

//insert at last

Node *insert_last(Node *head,int val)
{
  Node *temp;
  Node *nn;

	  nn=(Node *)malloc(sizeof(Node));
	  nn->next=NULL;
	  nn->prev=NULL;
	  nn->data=val;
          for(temp=head;temp->next!=NULL;temp=temp->next);
	  temp->next=nn;
	  nn->prev=temp;
  return head;
}




























//insert at any position

/*Node * insert_position(Node *head,int val,int pos)

{      int i;
	Node *temp;
	Node *temp1;
       Node *nn;
	if(pos==1)
	{
		head=insert_first(head,val);
		//return head;
	}
	else
	{       
		nn=(Node *)malloc(sizeof(Node));
		nn->next=NULL;
		nn->prev=NULL;
		nn->data=val;
		for(i=1,temp=head;i<pos-1;i++)
              {
		       temp=temp->next;
	       }
                temp1=temp->next;
		temp->next=nn;
		nn->prev=temp;
		nn->next=temp1;
		temp1->prev=nn;
	//	nn=temp;
	}
	return head;
}*/



	       




void main()
	
{       Node *head;
	head=create(4);
//	display(head);
	printf("\n");
	head=insert_first(head,3);
        head=insert_first(head,5);	
	display(head);
	head=insert_last(head,6);
	display(head);
//	head=insert_position(head,99,2);
//	display(head);

//	head=insert_last(head,9);

//	display(head);

//	head=insert_first(head,8);
//	display(head);
	
}
	
