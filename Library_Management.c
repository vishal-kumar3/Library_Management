#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store book information
struct book {
  char title[100];
  char author[100];
  int quantity;
  int is_available;
};

// Array to store book information
struct book books[100];

// Global variable to store the number of books
int books_count = 0;

// Function to add a book to the library
void add_book() {
  // Get book information from the user
  printf("\n***********Add Book Information***********\n");
  printf("\nEnter book title: ");
  scanf(" %[^\n]", books[books_count].title);
  printf("Enter book author: ");
  scanf(" %[^\n]", books[books_count].author);
  printf("Enter book quantity: ");
  scanf("%d", &books[books_count].quantity);

  // Initialize the is_available field to 1
  books[books_count].is_available = 1;

  books_count++;
}

void borrow_book() {
  // Get book information from the user
  char book_title[100];
  printf("Enter book title: ");
  scanf(" %[^\n]", book_title);

  // Find the book in the library
  int i;
  for (i = 0; i < books_count; i++) {
    if (strcmp(books[i].title, book_title) == 0) {
      break;
    }
  }

  // If the book is not found, print an error message
  if (i == books_count) {
    printf("Book not found.\n");
    return;
  }

  // If the book is already borrowed, print an error message
  if (books[i].is_available == 0) {
    printf("Book is already borrowed.\n");
    return;
  }

  // Borrow the book and decrease the quantity
  books[i].is_available = 0;
  books[i].quantity--;
}



// Function to return a book to the library
void return_book() {
  // Get book information from the user
  char book_title[100];
  printf("Enter book title: ");
  scanf("%s", book_title);

  // Find the book in the library
  int i;
  for (i = 0; i < books_count; i++) {
    if (strcmp(books[i].title, book_title) == 0) {
      break;
    }
  }

  // If the book is not found, print an error message
  if (i == books_count) {
    printf("Book not found.\n");
    return;
  }

  // Return the book and increase the quantity
  books[i].is_available = 1;
  books[i].quantity++;
}


// Function to list all the books in the library
void list_books() {
  int i;
  printf("\n***********Book Information***********\n");
  for (i = 0; i < books_count; i++) {
    printf("\nTitle: %s\nAuthor: %s\nQuantity: %d\nIs Available: %d\n", books[i].title, books[i].author, books[i].quantity, books[i].is_available);
  }
}



// Main function
int main() {
  // Initialize the number of books
  int books_count = 0;

  // Start a loop to keep running until the user wants to exit
  while (1) {
    // Print the menu
    printf("\n1. Add book\n2. Borrow book\n3. Return book\n4. List books\n5. Exit\n");
    int choice;
    printf("\nChoice> ");
    scanf("%d", &choice);

    // Switch on the choice
    switch (choice) {
      case 1:
        add_book();
        break;
      case 2:
        borrow_book();
        break;
      case 3:
        return_book();
        break;
      case 4:
        list_books();
        break;
      case 5:
        return 0;
    }
  }
}
