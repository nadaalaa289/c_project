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

    FILE *temporary_file = fopen("temp_student.csv", "w");
    if (temporary_file == NULL) {
        printf("Error creating temporary file!\n");
        fclose(original_file);
        return;
    }

    students edit;
    int found = 0;

    while (fscanf(original_file, "%d,%49[^,],%d,%9[^,],%29[^,],%d\n", &edit.id, edit.name, &edit.age, edit.gender, edit.pass, &edit.grade) != EOF) {
        if (id == edit.id) {
            if (name != NULL) strcpy(edit.name, name);
            if (age != -1) edit.age = age;
            if (gender != NULL) strcpy(edit.gender, gender);
            if (pass != NULL) strcpy(edit.pass, pass);
            if (grade != -1) edit.grade = grade;
            found = 1;
        }
        fprintf(temporary_file, "%d,%s,%d,%s,%s,%d\n", edit.id, edit.name, edit.age, edit.gender, edit.pass, edit.grade);
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(original_file);
    fclose(temporary_file);

    remove("student.csv");
    rename("temp_student.csv", "student.csv");
}