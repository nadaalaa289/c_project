#include "memory_managment.h"
#ifndef NADA_STUDENT_DATABASE_H
#define NADA_STUDENT_DATABASE_H
typedef struct {
    char name[50];
    int id;
    int age;
    char gender[10];
    char pass[30];
    int grade;
} students;


int write_student_data(int, const char *, int, const char *, const char *, int );
int read_student_data(int );
int write_admin_password(const char *);


#endif //NADA_STUDENT_DATABASE_H

