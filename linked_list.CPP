#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    char choice;

    do
    {
        // Allocate memory for a new node
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        // If the list is empty
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // Traverse to the last node
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            // Link the new node
            temp->next = newNode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // Display the linked list
    printf("\nLinked List:\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}