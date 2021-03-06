#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
}*tos=NULL;

void push(int n)
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

int pop()
{
	int ret_val;
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

int is_empty()
{
	if(tos == NULL)
		return 1;
	else
		return 0;
}

void display()
{
	struct node* temp = tos;
	while(temp != NULL)
	{
		printf("\n%d",temp->data);
		temp = temp->next;
	}
}
void main()
{
		clrscr();
		push(10);
		push(20);
		push(30);
		push(40);
		printf("\n%d",pop());
		printf("\n%d",is_empty());
		display();
		getch();
}