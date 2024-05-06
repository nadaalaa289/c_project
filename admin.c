
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

    edit_student_data(student_id, NULL, -1, NULL, NULL, -1);

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
