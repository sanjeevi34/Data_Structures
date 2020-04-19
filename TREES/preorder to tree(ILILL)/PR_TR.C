#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node_tree
{
	int data;
	struct node_tree* left;
	struct node_tree* right;
};

struct node_tree *createnode(int n)
{
	struct node_tree* newnode = (struct node_tree*)malloc(sizeof(struct node_tree));
	newnode->data = n;
	newnode->left = NULL;
	newnode->right = NULL;
	return(newnode);
}
//start of queue
struct node
{
	struct node_tree* data;
	struct node* next;
}*front,*rear;

void enqueue(struct node_tree* n)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = n;
	newnode->next = NULL;
	if(front == NULL)
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}
struct node_tree* dequeue()
{
	struct node* temp;
	struct node_tree* n;
	if(front == NULL)
	{
		printf("\nQUEUE UNDERFLOW");
	}
	else
	{
		n = front->data;
		temp = front;
		front = front->next;
		free(temp);

	}
	return n;
}
void display()
{
	struct node* temp;
	temp = front;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp = temp->next;
	}
}
int isEmpty()
{
	if(front == NULL)
	{
		return 1;
	}
	return 0;
}
//end of queue
void preOrder(struct node_tree* root)
{
	if(root)
	{
		printf("\n%d",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct node_tree* root)
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("\n%d",root->data);
	}
}
void inOrder(struct node_tree* root)
{
	if(root)
	{
		inOrder(root->left);
		printf("\n%d",root->data);
		inOrder(root->right);
	}
}
void levelOrder(struct node_tree* root)
{
	struct node_tree* temp;
	enqueue(root);
	while(!isEmpty())
	{
		temp = dequeue();
		printf("\n%d",temp->data);
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
	}
}

struct node_tree* treefrompreorder(char *A, int *i)
{
	struct node_tree* newnode = (struct node_tree*)malloc(sizeof(struct node_tree));
	newnode->data = A[*i];
	newnode->left = newnode->right = NULL;
	
	if(A[*i] == 'L')
		return newnode;
	*i = *i +1;
	newnode->left = treefrompreorder(A,i);
	*i = *i+1;
	newnode->right = treefrompreorder(A,i);
	return newnode;
}
int main()
{
	char A[]={"ILILL"};
	struct node_tree* root = treefrompreorder(A,0);
	clrscr();
	levelOrder(root);
	getch();
	return 0;
}