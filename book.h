// book.h
#ifndef BOOK_H
#define BOOK_H

struct Book {
    int bookID;
    char title[100];
    char author[100];
    int isAvailable;
    int userID;
};

void addBook();
void deleteBook();
void issueBook();
void returnBook();
void displayBookAvailability();
void displayIssuedBooks();
void searchBook();
void loadBooks();

#endif
