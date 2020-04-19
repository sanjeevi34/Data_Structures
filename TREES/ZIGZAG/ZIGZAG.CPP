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
//START OF STACK
struct node
{
	struct node_tree* data;
	struct node* next;
}*currentlevel = NULL , *nextlevel = NULL;

void push(struct node* tos,struct node_tree* n)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = n;
	newnode->next = NULL;
	if(tos == NULL)
	{
		tos = newnode;
	}
	else
	{
		newnode->next = tos;
		tos = newnode;
	}
}

struct node_tree* pop(struct node* tos)
{
	struct node_tree* ret_val;
	struct node *temp;
	if(tos == NULL)
		printf("\nSTACK UNDERFLOW");
	else
	{
		ret_val = tos->data;
		temp = tos;
		tos = tos->next;
		free(temp);
		return ret_val;
	}
return 0;
}

int is_empty(struct node* tos)
{
	if(tos == NULL)
		return 1;
	else
		return 0;
}

void display(struct node* tos)
{
	struct node* temp = tos;
	while(temp != NULL)
	{
		printf("\n%d",temp->data);
		temp = temp->next;
	}
}

//END OF STACK

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

void zigzag(struct node_tree* root)
{
	int lefttoright = 1;
	struct node_tree* temp;
	push(currentlevel,root);
	while(!is_empty(currentlevel))
	{
		temp = pop(currentlevel);
		if(temp)
		{
			printf("\n%d",temp->data);
			if(lefttoright == 1)
			{
				if(temp->left)
					push(nextlevel,temp->left)
				if(temp->right)
					push(nextlevel,temp->right)
			}
			else
			{
				if(temp->right)
					push(nextlevel,temp->right)
				if(temp->left)
					push(nextlevel,temp->left);
			}
		}
		if(is_empty(currentlevel))
		{
			lefttoright = 1-lefttoright;
			struct node* temp1;
			temp1 = currentlevel;
			currentlevel = nextlevel;
			nextlevel = temp1;
		}
	}
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
	zigzag(root);
	getch();
	return 0;
}