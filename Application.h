#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "student_database.h"

#define MAX_STUDENTS 100
const char *student_file = "student.csv";

typedef struct {
    char name[50];
    float total_grade;
    int id;
    int age;
    char gender;
    char password[20];
} Student;

admin_mode();
student_mode();
void add_student(FILE *student_file) ;
void viewStudentRecordById(const char *filename, int id);
void viewAllRecords(const char *student_file);





#endif _APPLICATION_H_

