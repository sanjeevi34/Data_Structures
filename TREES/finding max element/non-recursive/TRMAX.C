#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
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

void findMax(struct node_tree* root)
{
	int max = INT_MIN;
	struct node_tree* temp;
	enqueue(root);
	while(!isEmpty())
	{
		temp = dequeue();
		if(max < (temp->data))
			max = temp->data;
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
	}
	printf("\n%d",max);
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
	findMax(root);
	getch();
	return 0;
}