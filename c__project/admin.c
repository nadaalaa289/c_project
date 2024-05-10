
#include "file_access.h"
#include"data_managment.h"
#include"admin.h"
#include <stdio.h>
void edit_admin_password() {
    printf("Enter new admin password: ");
    char* new_pass = allocate_password("");
    scanf("%s", new_pass);
    int result = write_admin_password(new_pass);
    if (result == 0) {
        printf("Admin password edited successfully.\n");
    }
    free_password(new_pass);
}
void remove_student_data() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d",&student_id);
    edit_student_data(student_id, NULL, -1, NULL, NULL, -1);
}
void edit_student_grade() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d",&student_id);
    int new_grade;
    printf("Enter new grade for student %d: ", student_id);
    scanf("%d", &new_grade);
    if (new_grade < 0 || new_grade > 100) {
        printf("Error: Grade should be between 0 and 100.\n");
        return;
    }
    edit_student_data(student_id, NULL, -1, NULL, NULL, new_grade);
    read_student_data(student_id,NULL);
}
void add_student_record() {
    students add;
    printf("Enter student ID, name, age, gender, password, and grade (separated by spaces): ");
    scanf("%d %s %d %s %s %d", &add.id, add.name, &add.age, add.gender, add.pass, &add.grade);
    int result = write_student_data(add.id, add.name, add.age, add.gender, add.pass, add.grade);
    if (result == 0) {
        printf("Student record added successfully.\n");
    } else {
        printf("Error adding student record.\n");
    }
}
void view_student_record() {
    int student_id;
    printf("Enter student ID: ");
    scanf("%d",&student_id);
    read_student_data(student_id,NULL);
}
void view_all_students()
{
    read_student_data(-1,NULL);
}