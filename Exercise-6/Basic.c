#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;                         //node will store some data
  struct node *right_child;        // right child
  struct node *left_child;        // left child
};

//function to create a node
struct node* new_node(int x) 
{
  struct node *temp;
  temp=malloc(sizeof(struct node));
  temp->data=x;
  temp->left_child=NULL;
  temp->right_child=NULL;
  return temp;
}

// searching operation
struct node* search(struct node * root, int x) 
{
  if(root==NULL||root->data==x)     //if root->data is x then the element is found
    return root;
  else if (x>root->data)             // x is greater, so we will search the right subtree
    return search(root->right_child,x);
  else                               //x is smaller than the data, so we will search the left subtree
    return search(root->left_child,x);
}

// A sample C function to check if a given node exists in a binary search tree or not
int searchelement(struct node* root, int value) 
{ 
    // while is used to traverse till the end of tree
    while (root != NULL){

        // checking condition and passing right subtree & recusing 
        if (value > root->data) 
            root = root->right_child; 

        // checking condition and passing left subtree & recusing 
        else if (value < root->data) 
            root = root->left_child; 
        else
            return 1; // if the value is found return 1 
    } 
    return 0; 
}

// insertion
struct node* insert(struct node *root,int x) 
{
  //searching for the place to insert
  if(root==NULL)
    return new_node(x);
  else if(x>root->data)           // x is greater. Should be inserted to the right
    root->right_child=insert(root->right_child,x);
  else                          // x is smaller and should be inserted to left
    root->left_child=insert(root->left_child,x);
  return root;
}

//function to find the minimum value in a node
struct node* find_minimum(struct node *root) 
{
  if (root==NULL)
    return NULL;
  else if (root->left_child!=NULL)          // node with minimum value will have no left child
    return find_minimum(root->left_child); // left most element will be minimum
  return root;
}

struct node* find_maximum(struct node *root)
{
	if(root==NULL)
		return NULL;
	else if(root->right_child!=NULL)
		return find_maximum(root->right_child);
	return root;
}

// deletion
struct node* delete(struct node *root,int x) 
{
  //searching for the item to be deleted
  if(root==NULL)
    return NULL;
  if(x>root->data)
    root->right_child=delete(root->right_child,x);
  else if(x<root->data)
    root->left_child=delete(root->left_child,x);
  else 
  {
    //No Child node
    if(root->left_child==NULL && root->right_child==NULL) 
    {
      free(root);
      return NULL;
    }

    //One Child node
    else if(root->left_child==NULL || root->right_child==NULL) 
    {
      struct node *temp;
      if(root->left_child==NULL)
        temp=root->right_child;
      else
        temp=root->left_child;
      free(root);
      return temp;
    }

    //Two Children
    else 
    {
      struct node *temp=find_minimum(root->right_child);
      root->data=temp->data;
      root->right_child=delete(root->right_child,temp->data);
    }
  }
  return root;
}

// Inorder Traversal
void inorder(struct node *root) 
{
  if (root != NULL) // checking if the root is not null
  {
    inorder(root->left_child); // traversing left child
    printf("%d ",root->data); // printing data at root
    inorder(root->right_child); // traversing right child
  }
}

void postorder(struct node *root)
{
    if(root==0)
        return;
    postorder(root->left_child);
    postorder(root->right_child);
    printf("%d ",root->data);
}

void preorder(struct node *root)
{
    if(root==0)
        return;
    printf("%d ",root->data);
    preorder(root->left_child);
    preorder(root->right_child);
}

int main() 
{
  struct node *root=NULL,*inorder_successor=NULL,*inorder_predecessor=NULL;
  int choice=0,x=0,height=0,n=0;
  do
  {
    printf("\n-----------------Menu----------------\n");
    printf("\n1.Creation of a BST with ‘n’ number of nodes and implement 3 traversals \n2.Searching of a node\n3.Printing the inorder successor and inorder predecessor\n4.Delete of a node from BST has 1 child\n5.Deletion of a leaf node from BST\n6.Exit\n");
    printf("\nEnter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      	printf("\nEnter the number of nodes you want to create: ");
      	scanf("%d",&n);
      	if(n==0)
      		printf("\nInvalid number\n");
      	else if(n==1)
      	{
        	printf("\nEnter the value of root node: ");
        	scanf("%d",&x);
        	root=new_node(x);
        }
        else
        {
        	while(n>0)
        	{
        		printf("\nEnter the value to insert: ");
        		scanf("%d",&x);
       		 	root=insert(root,x);
       		 	n--;
       		 }	
       	}        	
       	printf("\nPreorder traversal:\n");
        preorder(root);
        printf("\n");
        printf("\nInorder traversal:\n");
        inorder(root);
        printf("\n");	
        printf("\nPostorder traversal:\n");
        postorder(root);
        printf("\n");
        break;
      case 2:
        printf("\nEnter the element to search: ");
        scanf("%d",&x);
        n=searchelement(root,x);
        if(n==1)
          printf("\n%d found in the Binary Search Tree\n",x);
        else
          printf("\n%d found in the Binary Search Tree\n",x);
        break;
      case 3:
        inorder_predecessor=find_maximum(root->left_child);
        inorder_successor=find_minimum(root->right_child);
        printf("\nInorder successor = %d",inorder_successor->data);
        printf("\nInorder predecessor = %d\n",inorder_predecessor->data);
        break;
      case 4:
        printf("\nEnter the value to delete: ");
        scanf("%d",&x);
        root=delete(root,x);
        printf("\nInorder traversal:\n");
        inorder(root);
        printf("\n");
        break;
      case 5:
        printf("\nPreorder traversal:\n");
        printf("\nEnter the value to delete: ");
        scanf("%d",&x);
        root=delete(root,x);
        printf("\nInorder traversal:\n");
        inorder(root);
        printf("\n");
        break;
      case 6:
        exit(0);
      default:
        printf("\nInvalid choice\n");
    }    
  } while (choice!=6);
  return 0;
}
