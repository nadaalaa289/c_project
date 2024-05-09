#include "authentication.h"
#include <stdio.h>
#include <string.h>


int authenticate_admin(const char *password) {


    FILE *admin_file = fopen("admin.csv", "r");
    if (admin_file == NULL) {
        printf("Error opening admin file!\n");
        return 0;
    }

    char file_password[50];
    if (fscanf(admin_file, "%49[^\n]", file_password) != EOF) {
        if (strcmp(password, file_password) == 0) {
            fclose(admin_file);
            printf("Admin authentication successful\n");
            return 1;
        }
    }

    fclose(admin_file);
    return 0;
}


int authenticate_student(const char *password) {
    FILE *student_file = fopen("student.csv", "r");
    if (student_file == NULL) {
        printf("Error opening student file!\n");
        return 0;
    }

    students read;
    while (fscanf(student_file, "%*d,%*49[^,],%*d,%*9[^,],%29[^,],%*d\n", read.pass) != EOF) {
        if (strcmp(password, read.pass) == 0) {
            fclose(student_file);
            printf("student authentication successful\n");
            return 1;
        }
    }

    fclose(student_file);
    return 0;
}
