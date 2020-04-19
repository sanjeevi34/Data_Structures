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
int findMax(struct node_tree* root)
{
	int left,right,max = INT_MIN,root_value;
	if(root)
	{
		root_value = root->data;
		left = findMax(root->left);
		right = findMax(root->right);

		if(left>right)
			max = left;
		else
			max = right;
		if(root_value>max)
			max = root_value;
	}
	return max;
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
	printf("%d",findMax(root));
	getch();
	return 0;
}