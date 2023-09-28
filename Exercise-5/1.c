#include <stdio.h>
#include <stdlib.h>
#define  N 5

int front=-1;
int rear=-1;

void enqueue(int queue[],int val)
{
    if(rear==N-1)
        printf("\nOverflow\n");
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=val;
        printf("\n%d added to Queue\n",val);
    }
    else
    {
        rear++;
        queue[rear]=val;
        printf("\n%d added to Queue\n",val);
    }
}

int dequeue(int queue[])
{
    int val;
    if(front==-1 && rear==-1)
        return -1;
    else if(rear==0)
    {
        val=queue[0];
        rear=front=-1;
        return val;
    }
    else
    {
        val=queue[0];
        for(int i=0;i<rear;i++)
            queue[i]=queue[i+1];
        rear=rear-1;
        return val;
    }
}

int peek(int queue[])
{
    if(front==-1)
        return -1;
    else
        return queue[front];
}

void display(int queue[])
{
    printf("\nDisplaying values\n");
    if(front==-1 && rear==-1)
        printf("\nQueue is Empty\n");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}

void main()
{
    int queue[N],choice=0,val=0;
    do
    {
        printf("\n---------------Menu-----------------\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data you want to insert: ");
                scanf("%d",&val);
                enqueue(queue,val);
                break;
            case 2:
                val=dequeue(queue);
                if(val==-1)
                    printf("\nUnderflow\n");
                else
                    printf("\nDequeued value is: %d\n",val);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                val=peek(queue);
                if(val==-1)
                    printf("\nQueue is Empty\n");
                else
                    printf("\nPeek value is: %d\n",val);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice!=5);
}

/*

front             rear
  0   1   2   3   4 
  10  20  30  40  50 

front - deletion
rear -  insertion

*/