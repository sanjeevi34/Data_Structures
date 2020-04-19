#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<iostream.h>
#define length 100
int TOS = -1;
//int length = 100;

char stack[length];

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

char pop()
{
	char pop_ele;
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

char top()
{
	return stack[TOS];
}

void display()
{
	int temp = TOS;
	for(;temp >= 0 ; temp--)
		printf("\n%c",stack[temp]);
}

int priority(char c)
{
	if(c == '(')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
return NULL;
}
void infix_to_postfix(char *n)
{
	char x;
	while(*n != '\0')
	{
		if(*n == '(')
		{
			push(*n);
		}
		else if (isalnum(*n))
		{
			printf("%c",*n);
		}
		else if(*n == ')')
		{
			while( (x = pop()) != '(' )
			{
				printf("%c",x);
			}
		}
		else
		{
			while(priority(top()) >= *n)
			{
				printf("%c",pop());
			}
			push(*n);
		}
		n++;
	}
	while(!is_empty())
	{
		printf("%c",pop());
	}
}

void main()
{
	clrscr();
	char n[] = "(a+(b*(d+2)))";
	infix_to_postfix(n);
	getch();
}