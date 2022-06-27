// to impliment stack and its various operations
#include<stdio.h>
#include<conio.h>
int push();		// for insertion
int pop();			// for deletion
int display();		// display the contents
int stack[100],n,choice,x,i,top;		// Global variables
int main()
{
	top=-1;
	printf("Entert the elements to be inserted in the stack = ");
	scanf("%d",&n);
	printf("Enter the element");
	printf("\n 1. Push");
	printf("\n 1. Pop");
	printf("\n 1. Display");
	do
	{
		printf("Enter the choice = ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default: printf("Entered wrong choice");
		}
		while(choice!=4);
		getch();
	};
	int push()
	{
		if(top>=n-1)	// if(top>=maxsize-1)
		{
			printf("\n Stack is overflow");
			//	exit(0);
		}
		else
		{
			printf("\n Enter the element in the stack = ");
			scanf("%d",&x);
			top=top+1;
			stack[top]=x;
		
		}
	};
	int pop()
	{
		if(top<=-1)
		{
			printf("\n stack is underflow");		//exit(0);
		}
		else
		{
			printf("Deleted element is = %d",stack[top]);
			top=top-1;
		}
	}
}
