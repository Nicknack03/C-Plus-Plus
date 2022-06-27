//Implementing singly linkedlist (SLL) and display its contents
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct list
{
int data;
struct list *next;
}*head;
void main()
{
clrscr();
char ch;
struct list *node,*head1;
  head->next=NULL; //List is empty no node is available
do
{
   node=(struct list*)malloc(sizeof(struct list));
   printf("\nEnter data in node:");
   scanf("%d",&node->data);
   if(head->next==NULL)    //here we are adding the first node
   {
   head->next=node;
   node->next=NULL;
   head1->next=head->next; //both the pointers are pointing to the first node of the linked list
   }
   else
   {
	while(head->next!=NULL)  //adding node at location 2,3......n
	{
	head=head->next;   //shifting head pointer
	}
	head->next=node;
	node->next=NULL;
   }
   printf("\n Do you want to enter another node: [y/n]");
   ch=getche();
}while(ch!='n');
while(head1->next!=NULL)
{
	head1=head1->next;
	printf("\n%d",head1->data);
}
getch();
}//end of main

