#include "edit.h"
#include "student_database.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void edit_student_data(int id, const char *name, int age, const char *gender, const char *pass, int grade) {
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

    students edit;
    int found = 0;
    int delete_record = 0;

    while (fscanf(original_file, "%d,%49[^,],%d,%9[^,],%29[^,],%d\n", &edit.id, edit.name, &edit.age, edit.gender,
                  edit.pass, &edit.grade) != EOF) {
        if (id == edit.id) {
            if (name == NULL && age == -1 && gender == NULL && pass == NULL && grade == -1) {
                
                delete_record = 1;
            } else {
                if (name != NULL) strcpy(edit.name, name);
                if (age != -1) edit.age = age;
                if (gender != NULL) strcpy(edit.gender, gender);
                if (pass != NULL) strcpy(edit.pass, pass);
                if (grade != -1) edit.grade = grade;
            }
            found = 1;
        }
        fprintf(temp_file, "%d,%s,%d,%s,%s,%d\n", edit.id, edit.name, edit.age, edit.gender, edit.pass, edit.grade);
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(original_file);
    fclose(temp_file);
    remove("student.csv");
    rename("temp_student.csv", "student.csv");
    if (delete_record) {
        // Open the file again to remove the record
        FILE *temp_file = fopen("temp_student.csv", "w");
        if (temp_file == NULL) {
            printf("Error creating temporary file!\n");
            return;
        }

        FILE *file = fopen("student.csv", "r");
        if (file == NULL) {
            printf("Error opening file!\n");
            fclose(temp_file);
            return;
        }

        while (fscanf(file, "%d,%49[^,],%d,%9[^,],%29[^,],%d\n", &edit.id, edit.name, &edit.age, edit.gender, edit.pass,
                      &edit.grade) != EOF) {
            if (id != edit.id) {
                fprintf(temp_file, "%d,%s,%d,%s,%s,%d\n", edit.id, edit.name, edit.age, edit.gender, edit.pass,
                        edit.grade);
            }
        }

        fclose(file);
        fclose(temp_file);

        
        remove("student.csv");
        rename("temp_student.csv", "student.csv");
        printf("Student record with ID %d deleted successfully.\n", id);
    }
}
