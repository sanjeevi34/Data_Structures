#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
  }*start,*tail;

void addNode(int neww)
{
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = neww;
  newnode->next = NULL;

  if(start == NULL)
  {
  start = newnode;
  newnode->next=newnode;
  tail=newnode;
  }
  else
  {
  tail->next = newnode;
  newnode->next=start;
  tail = newnode;
  }
}

void display()
{
  if(start == NULL)
  {
    printf("\nThe list is empty");
  }
  else
  {
    struct node* temp;
    temp = start;
    while(temp->next != start)
    {
      printf("\n%d",temp->data);
      temp = temp->next;
    }
    printf("\n%d",temp->data);
  }
}

void ins_at_beg(int neww)
{
 struct node* newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = neww;
 newnode->next = NULL;
 if(start == NULL)
 {
    start = newnode;
    newnode->next = newnode;
    tail = newnode;
 }
 else
 {
   newnode->next = start;
   struct node* temp;
   temp = start;
   while(temp->next != start)
   {
     temp = temp->next;
   }
   temp->next = newnode;
   start = newnode;
 }

}
void ins_at_end(int neww)
{
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = neww;
 newnode->next = NULL;
 if(start == NULL)
 {
    start = newnode;
    newnode->next = newnode;
    tail = newnode;
 }
 else
 {
   struct node* temp;
   temp=start;
   while(temp->next != start)
   {
     temp = temp->next;
   }
   temp->next = newnode;
   newnode->next = start;
 }

}

void del_at_beg()
{
 if(start == NULL)
 {
   printf("\nList is empty");
 }
 else
 {
   struct node* temp;
   temp = start;
   while(temp->next != start)
     temp = temp->next;
   temp->next = start->next;
   temp = start;
   start = start->next;
   free(temp);
 }

}
void del_at_end()
{
  if(start == NULL)
  {
    printf("\nList is empty");
  }
  else
  {
    struct node* temp;
    struct node* temp1;
    temp = start;
    while(temp->next != start)
    {
      temp1 = temp;
      temp = temp->next;
    }
    temp1->next = start;
    free(temp);
  }
}

void count()
{
  struct node* temp;
  int count=0;
  temp=start;
  if(start == NULL)
    printf("\nCount : 0");
  while(temp->next != start)
  {
    count++;
    temp=temp->next;
  }
  count++;
  printf("\nCount : %d",count);
}

void main()
{
 clrscr();
 addNode(10);
 addNode(20);
 display();
 printf("\nAfter inserting at beginning");
 ins_at_beg(100);
 display();
 printf("\nAFter inserting at end");
 ins_at_end(400);
 display();
 printf("\nDelete at begin");
 del_at_beg();
 display();
 printf("\nDelete at end");
 del_at_end();
 display();
 count();
 getch();
}