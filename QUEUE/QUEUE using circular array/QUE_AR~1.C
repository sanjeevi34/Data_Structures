#include<stdio.h>
#include<conio.h>
#define len 5
int a[len];
int front=-1, rear=-1;
void enqueue(int n)
{
	if(front==-1 && rear==-1)
	{
		front = 0;
		rear = 0;
		a[rear] = n;
	}
	else if((rear+1)%len == front)
	{
		printf("\nQueue Overflow");
	}
	else
	{
		rear = (rear+1)%len;
		a[rear] = n;
	}
}

int dequeue()
{
	int n;
	if(front == -1 && rear == -1)
	{
		printf("\nQueue Underflow");
	}
	else if(rear == front)
	{
		n = a[rear];
		rear = -1;
		front = -1;
	}
	else
	{
		n = a[front];
		front = (front+1)%len;
	}
	return n;
}

void display()
{
	if(front == -1)
	{
		printf("\nQueue is empty");
	}
	else
	{
		int temp = front;
		while(temp != rear)
		{
			printf("\n%d",a[temp]);
			temp = (temp+1)%len;
		}
		printf("\n%d",a[rear]);
	}
}
int isEmpty()
{
	if(front == -1 && rear == -1)
	{
		return 1;
	}
	return 0;
}
int isFull()
{
	if((rear+1)%len == front)
	{
		return 1;
	}
	return 0;
}

void main()
{
	clrscr();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	dequeue();
	display();
	printf("\n%d",isEmpty());
	printf("\n%d",isFull());
	getch();

}