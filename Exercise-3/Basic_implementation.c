#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
};

struct node* insert_head(struct node* head,int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
    }
    printf("\nNode inserted successfully...\n");
    return head;
}

struct node* create(struct node* head,int num_nodes)
{
    int val=0;
    head=NULL;
    for(int i=0;i<num_nodes;i++)
    {
        printf("\nEnter the data: ");
        scanf("%d",&val);
        head=insert_head(head,val);
    }
    return head;
}

struct node* insert_pos(struct node *head,int val,int index)
{
    int l=0,i=0;
    struct node *newnode,*temp=head,*check=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(index==0)
        head=insert_head(head,val);
    else
    {
        while(check->next!=NULL)
        {
            check=check->next;
            l++;
        }
        if(index>(l+1))
            printf("\nInvalid position...\n");
        else if(index==(l+1))
        {
            while(temp->next!=NULL)
                temp=temp->next;
            newnode->next=NULL;
            newnode->prev=temp;
            temp->next=newnode;
            printf("\nNode inserted succcessfully...\n");
        }
        else if(index==l)
        {
            while(temp->next!=NULL)
                temp=temp->next;
            newnode->next=temp;
            temp->prev->next=newnode;
            newnode->prev=temp->prev;
            temp->prev=newnode;
            printf("\nNode inserted succcessfully...\n");
        }
        else
        {
            while(temp->next!=NULL)
            {
                if(i==index-1)
                    break;
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next->prev=newnode;
            temp->next=newnode;  
            printf("\nNode inserted succcessfully...\n");          
        }
    }  
    return head;
}

struct node* del_head(struct node* head)
{
    struct node *temp=head;
    if(head==NULL)
        printf("\nList is empty...\n");
    else if(head->next==NULL)
    {
        free(temp);
        head=NULL;
        printf("\nNode deleted successfully...\n");
    }
    else
    {
        head=temp->next;
        head->prev=NULL;
        free(temp);
        printf("\nNode deleted successfully...\n");
    }
    return head;
}

struct node* del_pos(struct node *head,int index)
{
    struct node *temp1=head,*temp2,*check=head;
    int i=0,l=0;
    if(head==NULL)
        printf("\nList is empty...\n");
    else if(index==0)
        head=del_head(head);
    else
    {
        while(check->next!=NULL)
        {
            check=check->next;
            l++;
        }
        if(index>l)
            printf("\nInvalid index...\n");
        else if(index==l)
        {
            while(temp1->next!=NULL)
                temp1=temp1->next;
            temp1->prev->next=NULL;
            free(temp1);
            printf("\nNode deleted successfully...\n");
        }
        else
        {
            while(i!=index)
            {
                temp2=temp1;
                temp1=temp1->next;
                i++;                
            }
            temp2->next=temp1->next;
            temp1->next->prev=temp2;
            free(temp1);
            printf("\nNode deleted successfully...\n");
        }
    }
    return head;
}

void search(struct node *head,int val)
{
    struct node *temp=head;
    int i=0,count=0;
    if(head==NULL)
        printf("\nList is emty...\n");
    else
    {
        while(temp!=NULL)
        {
            if(temp->data==val)
            {
                printf("\n%d found at index %d",val,i);
                count++;
            }
            temp=temp->next;
            i++;
        }
    }
    if(count==0)
        printf("\n%d found %d times\n",val,count);
    else
        printf("\n%d found %d times\n",val,count);
}

void display(struct node *head)
{
    struct node *temp=head;
    printf("\nDisplaying values...\n");
    if(head==NULL)
        printf("\nList is empty...\n");
    else if(temp->next==NULL)
    {
        printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p\n",temp,temp->prev,temp->data,temp->next);
    }
    else
    {
        while(temp!=NULL)
        {
            printf("\nMemory=%p\tPrev=%p\tData=%d\tNext=%p\n",temp,temp->prev,temp->data,temp->next);
            temp=temp->next;
        }
    }
    printf("\n");
}

void main()
{
    struct node *head=NULL;
    int choice=0,val=0,index=0,num_nodes=0;
    do
    {
        printf("\nChoices:\n");
        printf("\n1.Create\n2.Insert at head\n3.Insert at the position\n4.Delete at the head\n5.Delete at the position\n6.Search\n7.Display\n8.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the number of nodes: ");
                scanf("%d",&num_nodes);
                head=create(head,num_nodes);
                break;
            case 2:
                printf("\nEnter the data: ");
                scanf("%d",&val);
                head=insert_head(head,val);
                break;
            case 3:
                printf("\nEnter the index to insert: ");
                scanf("%d",&index);
                printf("\nEnter the data: ");
                scanf("%d",&val);
                head=insert_pos(head,val,index);
                break;
            case 4:
                head=del_head(head);
                break;
            case 5:
                printf("\nEnter the index to delete: ");
                scanf("%d",&index);
                head=del_pos(head,index);
                break;
            case 6:
                printf("\nEnter the value to be searched: ");
                scanf("%d",&val);
                search(head,val);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice...\n");
        }
    } while (choice!=8);
}