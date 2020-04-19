#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node* next;
}*front,*rear;

void enqueue(int n)
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
int dequeue()
{
	int n;
	struct node* temp;
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
void main()
{
	clrscr();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	display();
	dequeue();
	display();
	getch();
}