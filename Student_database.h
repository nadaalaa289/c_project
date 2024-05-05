#ifndef _STUDENT_DATABASE_H_
#define _STUDENT_DATABASE_H_


typedef struct
{
    int   stu_id ;
    char  stu_password[30];
    char  stu_Name[50];
    char  stu_course[50];
    float stu_grade;

} students;

int write_student_data(const char *filename,const char *name, int id, float GPA);
int read_student_data(const char *filename,int student_id);
void Edit_Student_Record(students *students_info, const char *New_Name, const char *new_pass  , const char *New_Course , float New_GPA);










#endif //_STUDENT_DATABASE_H_
