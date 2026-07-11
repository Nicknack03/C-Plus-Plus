#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int n;

// Function Prototypes
void enqueue();
void dequeue();
void display();
void displayReverse();

int main()
{
    int choice;

    printf("Enter the maximum size of the queue (Max %d): ", MAX);
    scanf("%d", &n);

    do
    {
        printf("\n******** QUEUE OPERATIONS ********");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Display in Reverse");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                displayReverse();
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid Choice!");
        }

    } while (choice != 5);

    return 0;
}

// Enqueue Operation
void enqueue()
{
    int x;

    if (rear == n - 1)
    {
        printf("\nQueue Overflow");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    queue[++rear] = x;

    printf("%d inserted successfully.", x);
}

// Dequeue Operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow");
        return;
    }

    printf("Deleted Element = %d", queue[front]);

    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

// Display Queue
void display()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }

    printf("\nQueue Elements:\n");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

// Display Queue in Reverse
void displayReverse()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }

    printf("\nQueue in Reverse:\n");

    for (int i = rear; i >= front; i--)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}