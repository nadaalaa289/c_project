#include "file_access.h"
#include <stdio.h>
#include "string.h"
int write_student_data(int id, const char *name, int age, const char *gender, const char *pass, int grade) {
    char *name_copy = allocate_name(name);
    char *pass_copy = allocate_password(pass);
    if (name_copy == NULL || pass_copy == NULL) {
        free_name(name_copy);
        free_password(pass_copy);
        return 1;
    }
    FILE *student_file = fopen("student.csv", "a");
    if (student_file == NULL) {
        printf("Error opening file!\n");
        free_name(name_copy);
        free_password(pass_copy);
        return 1;
    }
    fprintf(student_file, "%d,%s,%d,%s,%s,%d\n", id, name_copy, age, gender, pass_copy, grade);
    fclose(student_file);
    free_name(name_copy);
    free_password(pass_copy);
    return 0;
}
int read_student_data(int student_id, const char *password) {
    FILE *student_file = fopen("student.csv", "r");
    if (student_file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    students read;
    int found = 0;
    if (student_id == -1) {
        printf("All Student Records:\n");
        while (fscanf(student_file, "%d,%49[^,],%d,%9[^,],%29[^,],%d\n", &read.id, read.name, &read.age, read.gender, read.pass, &read.grade) != EOF) {
            printf("Student ID: %d\nName: %s\nAge: %d\nGender: %s\nPassword: %s\nGrade: %d\n--------------------------\n", read.id, read.name, read.age, read.gender, read.pass, read.grade);
            found = 1;
        }
    } else if (student_id == -2) {
        while (fscanf(student_file, "%*d,%*49[^,],%*d,%*9[^,],%29[^,],%*d\n", read.pass) != EOF) {
            if (strcmp(password, read.pass) == 0) {
                fclose(student_file);
                printf("student authentication successful\n");
                return 1;
            }
        }
    } else {
        while (fscanf(student_file, "%d,%49[^,],%d,%9[^,],%29[^,],%d\n", &read.id, read.name, &read.age, read.gender, read.pass, &read.grade) != EOF) {
            if (student_id == read.id) {
                printf("Student ID: %d\nName: %s\nAge: %d\nGender: %s\nPassword: %s\nGrade: %d\n", read.id, read.name, read.age, read.gender, read.pass, read.grade);
                found = 1;
                break;
            }
        }
    }
    if (!found && student_id != -1 && student_id != -2) {
        printf("Student with ID %d not found.\n", student_id);
    }
    fclose(student_file);
    return found;
}
int write_admin_password(const char *password) {
    FILE *admin_file = fopen("admin.csv", "w");
    if (admin_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    } else {
        char *pass_copy = allocate_password(password);
        if (pass_copy == NULL) {
            fclose(admin_file);
            return 1;
        }
        fprintf(admin_file, "%s\n", pass_copy);
        fclose(admin_file);
        free_password(pass_copy);
    }
    return 0;
}
int read_admin_file(const char *password) {
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


