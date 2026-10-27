/*Develop a menu-driven Program in C for the following operations on Circular Queue (integer/floating point data):
Insert an element into the Circular Queue.
Delete an element from the Circular Queue.
Display the contents of the Circular Queue.
Demonstrate overflow and underflow conditions.
Exit.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;

/* Insert an element into Circular Queue */
void insert()
{
    int item;

    if (count == MAX)
    {
        printf("\nCircular Queue Overflow!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &item);

    rear = (rear + 1) % MAX;
    queue[rear] = item;
    count++;

    printf("%d inserted into the Circular Queue.\n", item);
}

/* Delete an element from Circular Queue */
void delete()
{
    int item;

    if (count == 0)
    {
        printf("\nCircular Queue Underflow!\n");
        return;
    }

    item = queue[front];
    front = (front + 1) % MAX;
    count--;

    printf("%d deleted from the Circular Queue.\n", item);
}

/* Display the Circular Queue */
void display()
{
    int i, index;

    if (count == 0)
    {
        printf("\nCircular Queue is empty.\n");
        return;
    }

    printf("\nContents of Circular Queue:\n");

    index = front;

    for (i = 0; i < count; i++)
    {
        printf("%d ", queue[index]);
        index = (index + 1) % MAX;
    }

    printf("\n");
}

/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n----- CIRCULAR QUEUE -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExiting program...\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
