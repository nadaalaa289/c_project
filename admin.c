
#include "student_database.h"
#include "student.h"
#include"edit.h"
#include"admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int edit_admin_password() {
    printf("Enter new admin password: ");
    char* new_pass = (char*)malloc(50 * sizeof(char));
    scanf("%s", new_pass);
    int result = write_admin_password(new_pass);
    if (result == 0) {
        printf("Admin password edited successfully.\n");
    }
    free(new_pass);
    new_pass = NULL;
    return result;
}
void remove_student_data(int student_id) {

    FILE *original_file = fopen("student.csv", "r");
    if (original_file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    FILE *temp_file = fopen("temp_student.csv", "w");
    if (temp_file == NULL) {
        printf("Error creating temporary file!\n");
        fclose(original_file);
        return;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), original_file) != NULL) {
        int id;
        sscanf(buffer, "%d,", &id);
        if (id != student_id)
        {
            fprintf(temp_file, "%s", buffer);
        }
    }
    fclose(original_file);
    fclose(temp_file);
    remove("student.csv");
    rename("temp_student.csv", "student.csv");
    printf("Student record with ID %d deleted successfully.\n", student_id);
}
void edit_student_grade(int student_id) {
    int new_grade;

    printf("Enter new grade for student %d: ", student_id);
    scanf("%d", &new_grade);
    if (new_grade < 0 || new_grade > 100) {
        printf("Error: Grade should be between 0 and 100.\n");

        return;
    }


    edit_student_data(student_id, NULL, -1, NULL, NULL, new_grade);
    read_student_data(student_id);
}