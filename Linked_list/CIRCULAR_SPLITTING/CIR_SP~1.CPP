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
void split()
{
  struct node *head1, *head2, *fast, *slow;
  if(start == NULL || start->next == start)
  {
    head1 = start;
    head2 = NULL;
  }
  else
  {
  slow = fast = start;
  while(fast->next != start && fast->next->next != start)
  {
   fast = fast->next->next;
   slow = slow->next;
  }
  if(fast->next->next == start)
      fast = fast->next;
  head1 = start;
  head2 = slow->next;
  slow->next = start;
  fast->next = head2;
  start = head1;
  printf("\nFirst list");
  display();
  printf("\nSecond list");
  start = head2;
  display();
  }
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
 addNode(70);
 display();
 split();
 getch();
}