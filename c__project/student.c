#include "student.h"
#include <stdio.h>
void edit_student_name() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d",&student_id);
    char *new_name = allocate_name("");
    printf("Enter new name: ");
    scanf("%s", new_name);
    edit_student_data(student_id, new_name, -1, NULL, NULL, -1);
    read_student_data(student_id,NULL);
    free_name(new_name);
}
void edit_student_pass() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d",&student_id);
    char *new_pass = allocate_password("");
    printf("Enter new password: ");
    scanf("%s", new_pass);
    edit_student_data(student_id, NULL, -1, NULL, new_pass, -1);
    read_student_data(student_id,NULL);
    free_password(new_pass);
}
void view_student_data() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d",&student_id);
    read_student_data(student_id,NULL);
}
