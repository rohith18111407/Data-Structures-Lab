#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* begin_insert(struct node *head,int val)
{
	struct node *newnode,*temp=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nCannot allocate new memory...\n");
	}
   	else if(head==NULL)
    {
    	newnode->data=val;
       	head=newnode;
       	newnode->next=head;
    	printf("\nNode inserted successfully...\n");
   	}
	else
	{
		newnode->data=val;
     	while(temp->next!=head)
      		temp=temp->next;
       	temp->next=newnode;
		newnode->next=head;
		head=newnode;
		printf("\nNode inserted successfully\n");
	}
	return head;
}

struct node* create(struct node *head,int num_nodes)
{
	int i=0,val=0;	
	while(i<num_nodes)
	{	
		printf("\nEnter the value to insert: ");
		scanf("%d",&val);
		head=begin_insert(head,val);
		i++;
	}
	return head;
}

struct node* pos_insert(struct node *head,int val,int pos)
{

	struct node *temp,*check=head,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	int l=0,i=0;
	while(check->next!=head)
	{
		l++;
		check=check->next;
	}	
	if(head==NULL)
	{
		printf("\nList is empty...\n");
	}
	else if(pos>l+1)
		printf("\nInvalid position...\n");
	else if(pos==0)
		head=begin_insert(head,val);
	else
	{
		temp=head;
		while(i<pos-1)
		{		
			temp=temp->next;
			i++;
		}
		newnode->next=temp->next;
		temp->next=newnode;	
		printf("\nNode inserted at the position successfully...\n");	
	}				
	return head;

}

struct node* begin_delete(struct node* head)
{
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("\nList is empty...\n");
	}
	else if(temp->next==temp)
	{
		free(temp);
		head=NULL;
		printf("\nOnly node in the list is deleted...\n");
	}
	else
	{
		while(temp->next!=head)
            	temp=temp->next;
        temp->next=head->next;
    	free(head);
       	head=temp->next;
		printf("\nNode deleted successfully...\n");
	}
	return head;
}

struct node* delete_pos(struct node *head,int pos)
{
	struct node *temp1,*temp2,*check=head;
	int l=0,i=0;
	if(head==NULL)
	{
		printf("\nNothing to delete...\n");
		return head;
	}
	while(check->next!=head)
	{
		check=check->next;
		l++;
	}
	if(pos>l)
		printf("\nInvalid position...\n");
	else if(pos==0)
		head=begin_delete(head);
	else	
	{
		temp1=head;
		while(temp1->next!=head)
		{
			temp2=temp1;
			temp1=temp1->next;
			if(i==pos-1)
				break;
			i++;
		}
		temp2->next=temp1->next;
		free(temp1);
		printf("\nNode deleted successfully...\n");
	}
    return head;
}

void display(struct node *head,int no_times)
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nNothing to print...\n");
    }
	else
	{
		printf("\nDisplaying values...");
		for(int i=0;i<no_times;i++)
		{	
			ptr=head;
			while(ptr->next!=head)
			{
				printf("\nMemory=%p\tData=%d\tNext=%p",ptr,ptr->data,ptr->next);
				ptr=ptr->next;
			}
			printf("\nMemory=%p\tData=%d\tNext=%p",ptr,ptr->data,ptr->next);
		}
		printf("\n");
	}
}	

void search(struct node *head,int val)
{
	struct node *temp=head;
    int i=0,count=0;
    if(temp==NULL)
    	printf("\nList is Empty");
	else
	{
    	if(temp->next==head)
       	{
      		if(val==temp->data)
     		{
         		count++;
        		printf("\nValue %d is found at the index %d",val,i);
        	}
       	}
        else
        {
            if(val==temp->data)
        	{
            	count++;
            	printf("\nValue %d is found at the index %d",val,i);
	     	}
			i++;
        	temp=temp->next;
        	while(temp!=head)
        	{
            	if(val==temp->data)
            	{
                	count++;
                	printf("\nValue %d is found at the position %d",val,i);
            	}
	           	i++;
               	temp=temp->next;
           	}
        }
        if(count==0)
        	printf("\nThe Value %d is not found in the List",val);
        else
          	printf("\nThe Value is found %d time(s)",count);
    }
}

void main()
{
	int choice=0,val=0,pos=0;
	struct node *head=NULL;
	do
	{
		printf("\nChoices :\n1.Create a Circularly linked list\n2.Insert at the head\n3.Insert at the specified position\n4.Delete at the head\n5.Delete at the specified position\n6.Search\n7.Display\n8.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				head=NULL;
				printf("\nEnter the no. of nodes to create: ");
				scanf("%d",&val);
				head=create(head,val);
				break;
			case 2:
				printf("\nEnter the value you want to insert at the beginning: ");
				scanf("%d",&val);
				head=begin_insert(head,val);
				break;
			case 3:
				printf("\nEnter the value you want to insert: ");
				scanf("%d",&val);
				printf("\nEnter the index at which you want to insert: ");
				scanf("%d",&pos);
				head=pos_insert(head,val,pos);
				break;
			case 4:
				head=begin_delete(head);
				break;
			case 5:
				printf("\nEnter the index you want to delete: ");
				scanf("%d",&pos);
				head=delete_pos(head,pos);
				break;
			case 6:
				printf("\nEnter the element to search: ");
				scanf("%d",&val);
				search(head,val);
				break;
			case 7:
				printf("\nEnter the no. of spin: ");
				scanf("%d",&val);
				display(head,val);
				break;
			case 8:
				exit(0);
			default:
				printf("\nInvalid choice!!!\n");
		}
	}while(choice!=8);
}


