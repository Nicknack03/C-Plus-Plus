#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;
int n;

// Function Prototypes
void push();
void pop();
void display();

int main()
{
    int choice;

    printf("Enter the size of the stack (Max %d): ", MAX);
    scanf("%d", &n);

    do
    {
        printf("\n******** STACK OPERATIONS ********");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid Choice!");
        }

    } while (choice != 4);

    return 0;
}

// Push Operation
void push()
{
    int x;

    if (top == n - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        stack[++top] = x;

        printf("%d inserted successfully.", x);
    }
}

// Pop Operation
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("Deleted Element = %d", stack[top]);
        top--;
    }
}

// Display Operation
void display()
{
    if (top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nStack Elements:\n");

        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}