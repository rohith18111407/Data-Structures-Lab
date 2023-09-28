#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node* push(struct node *top,int val)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=top;
	top=newnode;
	printf("\nNode pushed into stack successfully\n");
	return top;
}

void show(struct node *top)
{
	struct node *temp=top;
	printf("\nDisplaying values of stack:\n");
	if(top==NULL)
		printf("\nStack is Empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

struct node* pop(struct node *top)
{
	struct node *temp=top;
	int val=0;
	if(top==NULL)
		printf("\nStack Underflow\n");
	else
	{
		val=top->data;
		top=top->next;
		free(temp);
		printf("\nPopped value is: %d\n",val);
	}
	return top;
}

int peek(struct node *top)
{
	if(top==NULL)
		return -1;
	else
		return top->data;
}

void main()
{
	struct node *top=NULL;
	int val=0,choice=0;
	do
	{
		printf("\nChoices:\n");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit\n");
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the value you want to insert: ");
				scanf("%d",&val);
				top=push(top,val);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				val=peek(top);
				if(val==-1)
					printf("\nStack is empty\n");
				else
					printf("\nPeek value is: %d\n",val);
				break;
			case 4:
				show(top);
				break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
	}while(choice!=5);
}
