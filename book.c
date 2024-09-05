// book.c
#include <stdio.h>
#include <string.h>
#include "book.h"

struct Book library[100];
int bookCount = 0;

void saveBook(struct Book book) {
    FILE *file = fopen("books.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s %d %d\n", book.title, book.author, book.isAvailable, book.userID);
        fclose(file);
    } else {
        printf("Error: Unable to save book data.\n");
    }
}

void loadBooks() {
    FILE *file = fopen("books.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s %d %d", library[bookCount].title, library[bookCount].author,
                      &library[bookCount].isAvailable, &library[bookCount].userID) != EOF) {
            library[bookCount].bookID = bookCount;
            bookCount++;
        }
        fclose(file);
    }
}

// void addBook() {
//     struct Book newBook;

//     printf("Enter book title: ");
//     scanf("%s", newBook.title);

//     printf("Enter book author: ");
//     scanf("%s", newBook.author);

//     newBook.isAvailable = 1;
//     newBook.userID = -1;
//      newBook.bookID = bookCount;

//     library[bookCount++] = newBook;
//     saveBook(newBook);

//     printf("Book added successfully!\n");
// }

void addBook() {
    struct Book newBook;
    int numCopies;

    printf("Enter book title: ");
    scanf("%s", newBook.title);

    printf("Enter book author: ");
    scanf("%s", newBook.author);

    printf("Enter the number of copies: ");
    scanf("%d", &numCopies);

    for (int i = 0; i < numCopies; ++i) {
        newBook.isAvailable = 1;
        newBook.userID = -1;
        newBook.bookID = bookCount;  // Assign a unique book ID

        library[bookCount++] = newBook;
        saveBook(newBook);
    }

    printf("%d copies of the book added successfully!\n", numCopies);}
    

void deleteBook() {
    int bookID;

    printf("Enter book ID to delete: ");
    scanf("%d", &bookID);

    if (bookID >= 0 && bookID < bookCount) {
        // Move all subsequent books one position back
        for (int i = bookID; i < bookCount - 1; ++i) {
            library[i] = library[i + 1];
        }
        bookCount--;

        // Update the file with the modified book list
        FILE *file = fopen("books.txt", "w");
        if (file != NULL) {
            for (int i = 0; i < bookCount; ++i) {
                fprintf(file, "%s %s %d %d\n", library[i].title, library[i].author,
                        library[i].isAvailable, library[i].userID);
            }
            fclose(file);
        } else {
            printf("Error: Unable to update book data.\n");
        }

        printf("Book deleted successfully!\n");
    } else {
        printf("Invalid book ID.\n");
    }
}

void issueBook() {
    int bookID, userID;

    printf("Enter book ID to issue: ");
    scanf("%d", &bookID);

    if (bookID >= 0 && bookID < bookCount) {
        if (library[bookID].isAvailable) {
            printf("Enter user ID: ");
            scanf("%d", &userID);

            library[bookID].isAvailable = 0;
            library[bookID].userID = userID;

            // Update the file with the modified book list
            FILE *file = fopen("books.txt", "w");
            if (file != NULL) {
                for (int i = 0; i < bookCount; ++i) {
                    fprintf(file, "%s %s %d %d\n", library[i].title, library[i].author,
                            library[i].isAvailable, library[i].userID);
                }
                fclose(file);
            } else {
                printf("Error: Unable to update book data.\n");
            }

            printf("Book issued successfully!\n");
        } else {
            printf("Book is not available for issuing.\n");
        }
    } else {
        printf("Invalid book ID.\n");
    }
}

void returnBook() {
    int bookID;

    printf("Enter book ID to return: ");
    scanf("%d", &bookID);

    if (bookID >= 0 && bookID < bookCount) {
        if (!library[bookID].isAvailable) {
            library[bookID].isAvailable = 1;
            library[bookID].userID = -1;

            // Update the file with the modified book list
            FILE *file = fopen("books.txt", "w");
            if (file != NULL) {
                for (int i = 0; i < bookCount; ++i) {
                    fprintf(file, "%s %s %d %d\n", library[i].title, library[i].author,
                            library[i].isAvailable, library[i].userID);
                }
                fclose(file);
            } else {
                printf("Error: Unable to update book data.\n");
            }

            printf("Book returned successfully!\n");
        } else {
            printf("Book is already available.\n");
        }
    } else {
        printf("Invalid book ID.\n");
    }
}

void displayBookAvailability() {
    printf("Available Books:\n");

    for (int i = 0; i < bookCount; ++i) {
        if (library[i].isAvailable) {
            printf("ID: %d, Title: %s, Author: %s\n", library[i].bookID, library[i].title, library[i].author);
        }
    }
}

void displayIssuedBooks() {
    printf("Issued Books:\n");

    for (int i = 0; i < bookCount; ++i) {
        if (!library[i].isAvailable) {
            printf("ID: %d, Title: %s, Author: %s, Issued to User ID: %d\n", library[i].bookID,
                   library[i].title, library[i].author, library[i].userID);
        }
    }
}

void searchBook() {
    char searchTitle[100];

    printf("Enter book title to search: ");
    scanf("%s", searchTitle);

    printf("Search Results:\n");

    for (int i = 0; i < bookCount; ++i) {
        if (strstr(library[i].title, searchTitle) != NULL) {
            printf("ID: %d, Title: %s, Author: %s, Available: %s\n", library[i].bookID,
                   library[i].title, library[i].author, library[i].isAvailable ? "Yes" : "No");
        }
    }
}
