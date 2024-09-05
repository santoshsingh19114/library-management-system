// main.c
#include <stdio.h>
#include "admin.h"
#include "user.h"
#include "book.h"

int main() {
    int choice;
    int adminLoggedIn = 0;
    loadBooks();


    do {
        if(adminLoggedIn){
        printf("\nLibrary Management System Menu:\n");
        printf("1. Admin Logout\n");
        printf("2. User Registration\n");
        printf("3. User Login\n");
        printf("4. Add Book\n");
        printf("5. Delete Book\n");
        printf("6. Issue Book\n");
        printf("7. Return Book\n");
        printf("8. Display Available Books\n");
        printf("9. Display Issued Books\n");
        printf("10. Search Book\n");
        
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminLoggedIn = 0; // Admin Logout
                    printf("Admin Logout successful!\n");
                break;
            case 2:
                userRegistration();
                break;
            case 3:
                userLogin();
                break;
            case 4:
                addBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                issueBook();
                break;
            case 7:
                returnBook();
                break;
            case 8:
                displayBookAvailability();
                break;
            case 9:
                displayIssuedBooks();
                break;
            case 10:
                searchBook();
                break;
            
            case 0:
                printf("Exiting Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }    
        } else {
              printf("\nAdmin Login Menu:\n");
            printf("1. Admin registration\n");
            printf("2. Admin Login\n");
            printf("0. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    adminRegistration();
                    break;
                case 2:
                    adminLoggedIn = adminLogin();
                    break;
                case 0:
                    printf("Exiting Library Management System. Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
        }
        }
    } while (choice != 0);

    return 0;
}
