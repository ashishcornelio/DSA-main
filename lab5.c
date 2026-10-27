/*Develop a program in C for simulating a Printer Queue using Queue data structure with the following operations: 
a. Add a print job to the Printer Queue.
 b. Process (delete) a print job from the Printer Queue. 
c. Display all pending print jobs in the Queue. 
d. Demonstrate Queue overflow and underflow conditions. 
e. Exit. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

/* Add a print job */
void addJob()
{
    int job;
    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow! Printer Queue is full.\n");
        return;
    }
    printf("Enter Print Job Number: ");
    scanf("%d", &job);
    rear++;
    queue[rear] = job;
    printf("Print Job %d added successfully.\n", job);
}

/* Process a print job */
void processJob()
{
    if (front > rear)
    {
        printf("\nQueue Underflow! No print jobs available.\n");
        return;
    }

    printf("\nProcessing Print Job %d...\n", queue[front]);
    front++;
}

/* Display all pending print jobs */
void display()
{
    int i;
    if (front > rear)
    {
        printf("\nPrinter Queue is empty.\n");
        return;
    }
    printf("\nPending Print Jobs:\n");
    for (i = front; i <= rear; i++)
    {
        printf("Job %d\n", queue[i]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n--- PRINTER QUEUE ---");
        printf("\n1. Add Print Job");
        printf("\n2. Process Print Job");
        printf("\n3. Display Pending Jobs");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addJob();
                break;

            case 2:
                processJob();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
