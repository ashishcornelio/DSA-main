// Develop a menu-driven Program in C for the following operations on a Singly Linked List of Student Records:
// Create a linked list using front insertion.
// Display all student records and count the number of nodes.
// Insert and delete nodes at the beginning of the list.
// Search for a student record using USN.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char usn[20];
    char name[50];
    char branch[30];
    int semester;
    struct node *next;
};

struct node *first = NULL, *temp = NULL, *last = NULL;

/* Create one student node */
void create()
{
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter USN: ");
    scanf("%s", temp->usn);

    printf("Enter Name: ");
    scanf(" %[^\n]", temp->name);

    printf("Enter Branch: ");
    scanf("%s", temp->branch);

    printf("Enter Semester: ");
    scanf("%d", &temp->semester);

    temp->next = NULL;
}

/* Insert a student node at the beginning */
void insertBeg()
{
    create();

    if (first == NULL)
    {
        first = last = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
}

/* Display student records and count nodes */
void display()
{
    struct node *temp;
    int count = 0;

    temp = first;

    if (first == NULL)
    {
        printf("List is empty\n");
        printf("Number of nodes = 0\n");
        return;
    }

    printf("\nStudent Records:\n");

    while (temp != NULL)
    {
        printf("\nUSN      : %s", temp->usn);
        printf("\nName     : %s", temp->name);
        printf("\nBranch   : %s", temp->branch);
        printf("\nSemester : %d\n", temp->semester);

        count++;
        temp = temp->next;
    }

    printf("\nNumber of nodes = %d\n", count);
}

/* Delete a student node at the beginning */
void deleteBeg()
{
    if (first == NULL)
    {
        printf("List is empty. Deletion not possible\n");
        return;
    }

    temp = first;

    printf("Deleted student USN: %s\n", temp->usn);

    first = first->next;
    free(temp);

    if (first == NULL)
        last = NULL;

    printf("First node deleted successfully\n");
}

/* Search student using USN */
void search()
{
    char key[20];
    struct node *temp;
    int position = 1;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter USN to search: ");
    scanf("%s", key);

    temp = first;

    while (temp != NULL)
    {
        if (strcmp(temp->usn, key) == 0)
        {
            printf("\nStudent record found\n");
            printf("USN      : %s\n", temp->usn);
            printf("Name     : %s\n", temp->name);
            printf("Branch   : %s\n", temp->branch);
            printf("Semester : %d\n", temp->semester);
            printf("Position : %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Student record not found\n");
}

int main()
{
    int choice, n, i;

    while (1)
    {
        printf("\n--- STUDENT LINKED LIST ---\n");
        printf("1. Create linked list using front insertion\n");
        printf("2. Display records and count nodes\n");
        printf("3. Insert node at beginning\n");
        printf("4. Delete node at beginning\n");
        printf("5. Search student using USN\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of students: ");
            scanf("%d", &n);

            for (i = 1; i <= n; i++)
            {
                printf("\nEnter details of student %d:\n", i);
                insertBeg();
            }
            break;

        case 2:
            display();
            break;

        case 3:
            insertBeg();
            printf("Student record inserted successfully\n");
            break;

        case 4:
            deleteBeg();
            break;

        case 5:
            search();
            break;

        case 6:
            printf("Exiting program\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
