// user.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

struct User {
    char username[50];
    char password[50];
};

void saveUser(struct User user) {
    FILE *file = fopen("users.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s\n", user.username, user.password);
        fclose(file);
    } else {
        printf("Error: Unable to save user data.\n");
    }
}

void userRegistration() {
    struct User user;

    printf("Enter user username: ");
    scanf("%s", user.username);

    printf("Enter user password: ");
    scanf("%s", user.password);

    saveUser(user);

    printf("User registration successful!\n");
}

int verifyUser(struct User inputUser) {
    struct User storedUser;
    FILE *file = fopen("users.txt", "r");

    if (file != NULL) {
        while (fscanf(file, "%s %s", storedUser.username, storedUser.password) != EOF) {
            if (strcmp(storedUser.username, inputUser.username) == 0 &&
                strcmp(storedUser.password, inputUser.password) == 0) {
                fclose(file);
                return 1; // Credentials match
            }
        }
        fclose(file);
    }

    return 0; // Credentials do not match
}

int userLogin() {
    struct User user;
    
    printf("Enter user username: ");
    scanf("%s", user.username);

    printf("Enter user password: ");
    scanf("%s", user.password);

    if (verifyUser(user)) {
        printf("User login successful!\n");
        return 1;
    } else {
        printf("Invalid credentials. User login failed.\n");
        return 0;
    }
}
