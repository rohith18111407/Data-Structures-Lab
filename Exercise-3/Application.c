#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next,*prev;
};

struct node* last_insert(struct node *head,char val)
{
    struct node *temp=head,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else if(temp->next==NULL)
    {
        newnode->prev=temp;
        newnode->next=NULL;
        temp->next=newnode;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next=NULL;
    }
    // printf("\nNode inserted at the last successfully...\n");
    return head;
}

struct node* last_delete(struct node *head)
{
    struct node *temp1,*temp2;
    if(head==NULL)
        printf("\nList is empty\n");
    else if(temp1->next==NULL)
    {
        free(head);
        head=NULL;
        // printf("\nNode deleted successfully...\n");
    }
    else
    {
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        free(temp1);
        temp2->next=NULL;
        // printf("\nNode deleted successfully...\n");
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp=head;
    printf("\nDisplaying values...\n");
    if(head==NULL)
        printf("\nNothing to print...\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%c ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void main()
{
    struct node *head=NULL;
    char input[50];
    printf("\nEnter the input: ");
    gets(input);

    for(int i=0;i<strlen(input);i++)
    {
        if(input[i]=='$')
            head=last_delete(head);
        else
            head=last_insert(head,input[i]);
    }
    display(head);
}