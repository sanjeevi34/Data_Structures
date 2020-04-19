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

void kth_node_last(struct node* start, int k)
{
 int i;
 struct node* ptemp;
 struct node* kthnode;
 kthnode = start;
 ptemp = start;
 for(i=0; i<k-1; i++)
 {
   ptemp = ptemp->next;
 }
 while(ptemp->next != NULL)
 {
   ptemp=ptemp->next;
   kthnode=kthnode->next;
 }
 printf("%d",kthnode->data);
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
 printf("The Linked list is :");
 display();
 printf("\nThe %dth node from end of list is: ",3);
 kth_node_last(head,1);
 getch();
}