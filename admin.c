// admin.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"

struct Admin {
    char username[50];
    char password[50];
};

void saveAdmin(struct Admin admin) {
    FILE *file = fopen("admins.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s %s\n", admin.username, admin.password);
        fclose(file);
    } else {
        printf("Error: Unable to save admin data.\n");
    }
}

void adminRegistration() {
    struct Admin admin;

    printf("Enter admin username: ");
    scanf("%s", admin.username);

    printf("Enter admin password: ");
    scanf("%s", admin.password);

    saveAdmin(admin);

    printf("Admin registration successful!\n");
}

int verifyAdmin(struct Admin inputAdmin) {
    struct Admin storedAdmin;
    FILE *file = fopen("admins.txt", "r");

    if (file != NULL) {
        while (fscanf(file, "%s %s", storedAdmin.username, storedAdmin.password) != EOF) {
            if (strcmp(storedAdmin.username, inputAdmin.username) == 0 &&
                strcmp(storedAdmin.password, inputAdmin.password) == 0) {
                fclose(file);
                return 1; // Credentials match
            }
        }
        fclose(file);
    }

    return 0; // Credentials do not match
}

int adminLogin() {
    struct Admin admin;
    
    printf("Enter admin username: ");
    scanf("%s", admin.username);

    printf("Enter admin password: ");
    scanf("%s", admin.password);

    if (verifyAdmin(admin)) {
        printf("Admin login successful!\n");
        return 1;
    } else {
        printf("Invalid credentials. Admin login failed.\n");
        return 0;
    }
}
