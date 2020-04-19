#include<stdio.h>
#include<conio.h>
// stacka
#define length 100
int TOS = -1;
int stack[length];

void push(int n)
{
  if(TOS == length-1)
	  printf("\nSTACK OVERFLOW");
  else
  {
	TOS++;
	stack[TOS] = n;
  }
}

int pop()
{
	int pop_ele;
	if (TOS == -1)
		printf("\nSTACK UNDERFLOW");
	else
	{
		pop_ele = stack[TOS];
		TOS--;
	}
	return pop_ele;
}

int is_empty()
{
	if(TOS == -1)
		return 1;
	else
		return 0;
}

int is_full()
{
	if(TOS == length - 1)
		return 1;
	else
		return 0;
}

int top()
{
	return stack[TOS];
}

void display_stack()
{
	int temp = TOS;
	for(;temp >= 0 ; temp--)
		printf("\n%d",stack[temp]);
}
// End of stack

//Start of queue
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
void display_queue()
{
	struct node* temp;
	temp = front;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp = temp->next;
	}
}
//end of queue

void reverse_queue(int k)
{
	int count = 0,i;
	struct node* temp=front;
	while(temp!=NULL)
	{
		count = count+1;
		temp = temp->next;
	}
	
	for(i=0;i<k;i++)
	{
		push(dequeue());
	}
	for(i=0;i<k;i++)
	{
		enqueue(pop());
	}
	for(i=0;i<count-k;i++)
	{
		enqueue(dequeue());
	}
	display_queue();
}
void main()
{
	int array[]={10,20,30,40,50,60,70,80,90};
	int k;
	clrscr();
	printf("\nEnter the value of k");
	scanf("%d",&k);
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	enqueue(70);
	enqueue(80);
	enqueue(90);
	reverse_queue(k);
	getch();
}