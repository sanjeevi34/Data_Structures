//This is to test
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
  struct node* pre;
  }*head,*tail;

void addNode(int neww)
{
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  if(head==NULL)
  {
    newnode->data = neww;
    newnode->next = NULL;
    newnode->pre = NULL;
    head = newnode;
    tail = newnode;
  }
  else
  {
    tail->next = newnode;
    newnode->data = neww;
    newnode->pre = tail;
    newnode->next = NULL;
    tail = newnode;
  }
}

void display()
{
   struct node* temp = (struct node*)malloc(sizeof(struct node));
   temp = head;
   while(temp!=NULL)
   {
     printf("\n%d",temp->data);
     temp = temp->next;
   }
}

void ins_at_beg(int neww)
{
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = neww;
  newnode->pre = NULL;
  newnode->next = head;
  head = newnode;
}

void ins_at_end(int neww)
{
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp = head;
  newnode->data = neww;
  newnode->next = NULL;
  if(head == NULL)
  {head=newnode;
   newnode->pre = NULL;
  }
  else
  {
   while(temp->next != NULL)
     temp = temp->next;
   temp->next = newnode;
   newnode->pre = temp;
  }
}
void del_at_beg()
{
  if(head == NULL)
  {
    printf("\nThe list is empty");
  }
  else
  {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    head = head->next;
    free(temp);
  }
}
void del_at_end()
{
  if(head == NULL)
  {
    printf("\nThe list is empty");
  }
  else
  {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp = head;
    if(temp->next == NULL)
    {
     head = NULL;
     free(temp);
    }
    else{
    while(temp->next != NULL)
    {
      temp1 = temp;
      temp=temp->next;
    }
    temp1->next = NULL;
    free(temp);
    }
  }
}

void ins_at_pos(int n, int neww)
{
  if(n==1)
    ins_at_beg(neww);
  else
  {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = neww;
    newnode->pre = NULL;
    newnode->next = NULL;
    int count = 1;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp = head;

    while(count != n && temp!= NULL)
    {
     temp1=temp;
     count++;
     temp = temp->next;
    }
   temp1->next=newnode;
   newnode->pre=temp1;
   newnode->next=temp;
   temp->pre=newnode;
  }
}
void del_at_pos(int n)
{
 if(n==1)
   del_at_beg();
 else
 {
  struct node* temp,*temp1,*delnode;
  temp=head;
  int count=1;
  while(count!=n && temp!=NULL)
  {
   temp1=temp;
   count++;
   temp=temp->next;
  }
  delnode = temp;
  temp1->next=temp->next;
  temp->next->pre = temp1;
  free(delnode);

 }
}
void main()
{
 clrscr();
 addNode(10);
 addNode(20);
 addNode(30);
 display();
 printf("\nInserting at beginning");
 ins_at_beg(500);
 display();
 printf("\nInserting at end");
 ins_at_end(800);
 display();
 printf("\nDeletion at beginning");
 del_at_beg();
 display();
 printf("\nDeletion at end");
 del_at_end();
 display();
 printf("\nInserting at a position");
 ins_at_pos(2,4000);
 display();
 printf("\nDeleting at a position");
 del_at_pos(3);
 display();
 getch();
}