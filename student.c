#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void edit_student_name(int student_id) {
    char *new_name = (char *)malloc(50 * sizeof(char));
    if (new_name == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", new_name);
    edit_student_data(student_id, new_name, -1, NULL, NULL, -1);
    read_student_data(student_id);
    free(new_name);
    new_name = NULL;
}

void edit_student_pass(int student_id) {
    char *new_pass = (char *)malloc(30 * sizeof(char));
    if (new_pass == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter new password: ");
    scanf("%s", new_pass);
    edit_student_data(student_id, NULL, -1, NULL, new_pass, -1);
    read_student_data(student_id);
    free(new_pass);
    new_pass = NULL;
}

void view_student_data(int student_id) {
    read_student_data(student_id);
}
