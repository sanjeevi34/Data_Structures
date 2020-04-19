#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node* next;
}*head,*tail;

void addNode(int data)
{
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
    tail=newnode;
  }
  else
  {
    tail->next=newnode;
    tail=newnode;
  }
}
void display()
{
 struct node* temp=head;
 while(temp!=NULL)
 {
  printf("\n%d",temp->data);
  temp=temp->next;
 }
}

void divide()
{
  struct node *first=NULL,*first_temp=NULL,*second_temp=NULL, *second=NULL, *temp;
  temp = head;
  int count = 0;
  while(temp != NULL)
  {
	  if(count % 2 == 0)
	  {
		  if(first == NULL)
			  first = first_temp = temp;
		  else
		  {      first_temp->next = temp;
			 first_temp = first_temp->next;
		  }
	  }
	  else
	  {
		  if(second == NULL)
			  second = second_temp = temp;
		  else
		  {	  second_temp->next = temp;
			  second_temp = second_temp->next;
		  }
	  }
	  temp = temp->next;
	  count++;
  }
  first_temp->next = second_temp->next = NULL;
  head = first;
  printf("\nFirst splitted list:");
  display();
  head = second;
  printf("\nSecond splitted list:");
  display();
}
void main()
{
 clrscr();
 addNode(10);
 addNode(20);
 addNode(30);
 addNode(40);
 addNode(50);
 addNode(60);
 display();
 divide();
 getch();
}