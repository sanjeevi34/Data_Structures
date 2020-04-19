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
int size_tree(struct node_tree* root)
{
	if(root == NULL)
		return 0;
	else
		return(1+size_tree(root->left)+size_tree(root->right));
}
int main()
{
	struct node_tree* root = createnode(1);
	clrscr();
	root->left = createnode(2);
	root->right = createnode(3);
	root->left->left = createnode(4);
	root->left->right = createnode(5);
	root->right->left = createnode(6);
	root->right->right = createnode(7);
	printf("\nThe size of the tree is %d",size_tree(root));
	getch();
	return 0;
}