// Implementation of queue using array
#include <stdio.h>
#include <conio.h>
#include <process.h>
void inqueue();
void delqueue();	//deletion
void display();
void display2();
int queue[100], front=-1,rear=-1,n,i,choice,x;
void main()
{       clrscr();
	printf("Enter the elements you want in the queue =  ");
	scanf("%d",&n);
	printf("\n Operations on the queue");
	printf("\n 1. Inqueue");
	printf("\n 2. Delqueue");
	printf("\n 3. Display");
	printf("\n 4. Display2");
	printf("\n 5. Exit");
		do
		{
			printf("\n Enter any Choice = ");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1: inqueue();
				break;
			case 2: delqueue();
				break;
			case 3: display();
				break;
			case 4: display2();
				break;
			default: printf("Wrong choice"); exit(0);
			}
	       }while(choice!=6);
	getch();
}
void inqueue()
{
	if (front>rear)
	{
	front=-1;rear=-1;
	}
	if(front==0 && rear==n-1)
	{
	printf("\n Queue is FULL!!!");
	}
	else if(front==-1 && rear==-1)
	{
	front=0; rear=0;
	printf("Enter the element = ");
	scanf("%D",&x);
	queue[rear]=x;
	}
	else
	{
		printf("\n Enter the Element = ");
		scanf("%d",&x);
		rear=rear+1;
		queue[rear]=x;
	}
}
void delqueue()
{
	if (front==-1 || front>rear)		//queue empty
	{
		printf("\n queue is underflow");
	}
	else if (front==0 && rear==0)		//if queue contains single element
	{
		printf("Deleted element is = %d",queue[front]);
		front=-1; rear=-1;
	}
	else					//queue is partially full
	{
		printf("Deleted element is = %d",queue[front]);
		front=front+1;
	}
}
void display()
{
	if(front==-1 || front>rear)
	{
		printf("\n Queue is Empty");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
		printf("\n %d",queue[i]);
		}
	}
}
void display2()
{
	if (rear==-1)
		printf("Queue is Empty \n");
	else
	{
		printf("Queue is  = \n");
		for (i = rear; i>=front; i--)
		{
			printf("\n %d", queue[i]);
		}
		printf("\n");
	}
}