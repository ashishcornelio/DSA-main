#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
  int Book_ID;
  char Title[50];
  char Author[50];
  float Price;
  int Availability_Status; // 1 = Available, 0 = Issued
};
struct Book *books;
int N = 0;
/* Function to create book records */
void create() {
  int i;
  printf("Enter number of books: ");
  scanf("%d", &N);
  books = (struct Book *)malloc(N * sizeof(struct Book));
  if (books == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  for (i = 0; i < N; i++) {
    printf("\nEnter details of Book %d\n", i + 1);
    printf("Book ID: ");
    scanf("%d", &books[i].Book_ID);

    printf("Title: ");
    scanf(" %[^\n]", books[i].Title);
    printf("Author: ");
    scanf(" %[^\n]", books[i].Author);
    printf("Price: ");
    scanf("%f", &books[i].Price);
    books[i].Availability_Status = 1; // Initially Available
  }
  printf("\nBook records added successfully!\n");
}
/* Function to display available books */
void display() {
  int i, found = 0;
  printf("\n--- Available Books ---\n");
  for (i = 0; i < N; i++) {
    if (books[i].Availability_Status == 1) {
      printf("\nBook ID: %d", books[i].Book_ID);
      printf("\nTitle: %s", books[i].Title);
      printf("\nAuthor: %s", books[i].Author);
      printf("\nPrice: %.2f", books[i].Price);
      printf("\nStatus: Available\n");
      found = 1;
    }
  }
  if (found == 0)
    printf("No books are currently available.\n");
}

/* Function to search book */
void search() {
  int id, i, found = 0;
  printf("Enter Book ID to search: ");
  scanf("%d", &id);
  for (i = 0; i < N; i++) {
    if (books[i].Book_ID == id) {
      printf("\nBook Found!\n");
      printf("Book ID: %d\n", books[i].Book_ID);
      printf("Title: %s\n", books[i].Title);
      printf("Author: %s\n", books[i].Author);
      printf("Price: %.2f\n", books[i].Price);
      if (books[i].Availability_Status == 1)
        printf("Status: Available\n");
      else
        printf("Status: Issued\n");
      found = 1;
      break;
    }
  }
  if (found == 0)
    printf("Book not found!\n");
}
/* Function to issue a book */
void issueBook() {
  int id, i;
  printf("Enter Book ID to issue: ");
  scanf("%d", &id);

  for (i = 0; i < N; i++) {
    if (books[i].Book_ID == id) {
      if (books[i].Availability_Status == 1) {
        books[i].Availability_Status = 0;
        printf("Book issued successfully!\n");
      } else {
        printf("Book is already issued.\n");
      }
      return;
    }
  }
  printf("Book not found!\n");
}
/* Function to return a book */
void returnBook() {
  int id, i;
  printf("Enter Book ID to return: ");
  scanf("%d", &id);
  for (i = 0; i < N; i++) {
    if (books[i].Book_ID == id) {
      if (books[i].Availability_Status == 0) {
        books[i].Availability_Status = 1;
        printf("Book returned successfully!\n");
      } else {

        printf("Book is already available.\n");
      }
      return;
    }
  }
  printf("Book not found!\n");
}
/* Main function */
int main() {
  int choice;
  do {
    printf("\n\n===== LIBRARY MENU =====");
    printf("\n1. Add Book Records");
    printf("\n2. Display All Book Records");
    printf("\n3. Search Book by Book ID");
    printf("\n4. Issue a Book");
    printf("\n5. Return a Book");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      create();
      break;
    case 2:
      display();
      break;
    case 3:
      search();
      break;

    case 4:
      issueBook();
      break;
    case 5:
      returnBook();
      break;
    case 6:
      free(books);
      printf("Program ended.\n");
      break;
    default:
      printf("Invalid choice!\n");
    }
  } while (choice != 6);
  return 0;
}