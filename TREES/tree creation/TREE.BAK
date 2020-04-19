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
	printf("\nPreorder traversal:");
	preOrder(root);
	printf("\nPost Order Traversal:");
	postOrder(root);
	printf("\nInorder Traversal");
	inOrder(root);
	getch();
	return 0;
}