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

void insbegin(int neww)
{
  struct node* newnode=(struct node*)malloc(sizeof(struct node*));
  newnode->data = neww;
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
  }
  else
  {
  newnode->next=head;
  head=newnode;
  }
}
void insend(int neww)
{
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data=neww;
  newnode->next = NULL;
  if(head == NULL)
  {
    head=newnode;
  }
  else
  {
    struct node* temp = head;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}
void del_first()
{
  if(head == NULL)
  {
   printf("\nThe list is empty");
  }
  else
  {
   struct node* temp = (struct node*)malloc(sizeof(struct node));
   temp = head;
   head=head->next;
   free(temp);
  }
}

void del_last()
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
   while(temp->next != NULL)
   {
     temp1 = temp;
     temp = temp->next;
   }
    temp1->next = NULL;
    free(temp);

 }
}

void ins_at_pos(int n,int neww)
{
  if(n==1)
    insbegin(neww);
  else
  {
   struct node* temp = (struct node*)malloc(sizeof(struct node));
   struct node* temp1 = (struct node*)malloc(sizeof(struct node));
   temp = head;
   int count=1;
   while(count!=n && temp!=NULL)
   {
     temp1=temp;
     temp=temp->next;
     count++;
   }
   if(temp == NULL)
   {
    printf("\nNo position exists");
   }
   else
   {
     struct node* newnode = (struct node*)malloc(sizeof(struct node));
     newnode->data = neww;
     temp1->next=newnode;
     newnode->next=temp;

   }
  }
}

void del_at_pos(int n)
{
 if(n==1)
   del_first();
 else
 {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));
  int count = 1;
  temp = head;
  while(count != n && temp!=NULL)
  {
     count++;
     temp1=temp;
     temp = temp->next;
  }
  temp1->next = temp->next;
  free(temp);

 }
}

void main()
{
 clrscr();
 addNode(10);
 addNode(20);
 addNode(30);
 insbegin(80);
 insend(90);
 display();
 printf("\nAfter deleting first node");
 del_first();
 display();
 printf("\nAfter deleting last node");
 del_last();
 display();
 printf("\nAfter inserting at 2nd position");
 ins_at_pos(2,300);
 display();
 printf("\nAfter deleting at 3rd position");
 del_at_pos(3);
 display();
 getch();
}