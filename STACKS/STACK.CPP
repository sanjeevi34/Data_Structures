#include<stdio.h>
#include<conio.h>
#define length 100
int TOS = -1;
//int length = 100;

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

void display()
{
	int temp = TOS;
	for(;temp >= 0 ; temp--)
		printf("\n%d",stack[temp]);
}

void main()
{
	clrscr();
	push(10);
	push(20);
	push(30);
	push(40);
	pop();
	printf("\n%d",is_empty());
	printf("\n%d",is_full());
	display();
	printf("\n%d",top());
	getch();
}