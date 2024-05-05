#include "student_database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_student_data(int id, const char *name, int age, const char *gender, const char *pass, int grade) {
    FILE *student_file = fopen("student.csv", "a");
    if (student_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    } else {
        fprintf(student_file, "%d,%s,%d,%s,%s,%d\n", id, name, age, gender, pass, grade);
    }
    fclose(student_file);
    return 0;
}

int read_student_data(int student_id) {
    FILE *student_file = fopen("student.csv", "r");
    if (student_file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    students read;
    int found = 0;

    while (fscanf(student_file, "%d,%49[^,],%d,%9[^,],%29[^,],%d\n", &read.id, read.name, &read.age, read.gender, read.pass, &read.grade) != EOF) {
        if (student_id == read.id) {
            printf("Student ID: %d\n", read.id);
            printf("Name: %s\n", read.name);
            printf("Age: %d\n", read.age);
            printf("Gender: %s\n", read.gender);
            printf("Password: %s\n", read.pass);
            printf("Grade: %d\n", read.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", student_id);
    }

    fclose(student_file);
    return found;
}

int write_admin_password(const char *password) {
    FILE *admin_file = fopen("admin_password.csv", "w");
    if (admin_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    } else {
        fprintf(admin_file, "%s\n", password);
    }
    fclose(admin_file);
    return 0;
}