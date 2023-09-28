#include <stdio.h>
#include  <stdlib.h>

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
	}
	else
	{
		newnode->data=val;
    	while(temp->next!=head)
        	temp=temp->next;
    	temp->next=newnode;
		newnode->next=head;
		head=newnode;
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
		// printf("\nNode deleted successfully...\n");
        printf("\nSpinning wheel starts at data %d\n",head->data);
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
        head=temp1->next;
		free(temp1);
        printf("\nSpinnning wheel starts from data %d\n",head->data);
	}
    return head;
}

void display(struct node *head)
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nNothing to print...\n");
    }
	else
	{
		ptr=head;
		while(ptr->next!=head)
		{
			printf("\nData=%d",ptr->data);
			ptr=ptr->next;
		}
        printf("\nData=%d",ptr->data);
		printf("\n");
	}
}	

void main()
{
    struct node *head=NULL;
    int num,index;
    printf("\nEnter the number of nodes you want to insert: ");
    scanf("%d",&num);
    head=create(head,num);
    printf("\n*** AT THE BEGINNING ***\n");
    printf("Spinning wheel data :");
    display(head);
    while(num>1)
    {
        printf("\n************************************\n");
        printf("\nSpinning the wheel...\n");
        if(num==1)
            break;
        index=rand()%(num-1);
        printf("\nThe wheel stopped at index %d\n",index);
        head=delete_pos(head,index);
        printf("\nSpinning wheel data :\n");
        display(head);
        num--;
        printf("\n************************************\n");
    }
    printf("\n*** AT THE END ***\n");
    printf("Spinning wheel data :");
    display(head);
    printf("\n");
}