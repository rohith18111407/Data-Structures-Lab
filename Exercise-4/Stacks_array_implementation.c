#include <stdio.h>
#include <stdlib.h>

int IsFull(int *top,int n)
{
	if(*top==n)
		return 1;
	else
		return 0;
}

int IsEmpty(int *top)
{
	if(*top==0)
		return 1;
	else
		return 0;
}

void push(int *stack,int *top,int val,int n)
{
	if(IsFull(top,n)==1)
		printf("\nStack overflow...\n");
	else
	{
		stack[*top]=val;
		printf("\n%d pushed at position %d\n",val,*top);
		(*top)++;
	}
}

int pop(int *stack,int *top)
{
	int val;
	if(IsEmpty(top)==1)
		return -1;
	else
	{
		val=stack[--(*top)];
		return val;
	}
}		 

void show(int *stack,int *top)
{
	printf("\nDisplaying values in the stack...\n");
	for(int i=(*top)-1;i>=0;i--)
		printf("\n%d found at index %d",stack[i],i);
	if(*top==0)
		printf("\nStack is Empty\n");
	printf("\n");
}

int peek(int *top,int *stack)
{
	int val;
	if(IsEmpty(top)==1)
		return -1;
	else
	{
		val=stack[--(*top)];
		return val;
	}
}	

void main()
{
	int val=0,choice=0,stack[5],n=5;
	int *top=(int *)malloc(sizeof(int));
	*top=0;
	do
	{
		printf("\nChoices:\n");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.IsFull\n6.Show\n7.Exit\n");
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the data you want to push: ");
				scanf("%d",&val);
				push(stack,top,val,n);
				break;
			case 2:
				val=pop(stack,top);
				if(val==-1)
					printf("\nStack Underflow...\n");
				else
					printf("\nPopped value is %d\n",val);
				break;
			case 3:
				val=peek(top,stack);
				if(val==-1)
					printf("\nStack is Empty\n");
				else
					printf("\nPeek value is: %d\n",val);
				break;
			case 4:
				if(IsEmpty(top)==1)
					printf("\nStack is Empty\n");
				else
					printf("\nStack is not empty\n");
				break;
			case 5:
				if(IsFull(top,n)==1)
					printf("\nStack is Full\n");
				else
					printf("\nStack is not full\n");
				break;
			case 6:
				show(stack,top);
				break;
			case 7:
				exit(0);
			default:
				printf("\nInvalid choice...\n");
		}
	}while(choice!=7);
}					
