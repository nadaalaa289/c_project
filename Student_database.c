#include "student_database.h"

int write_student_data(const char *filename ,const char *name, int id, float GPA)
{

    FILE *file= fopen(student_file, "w");
    students students_info ;


    if (student_file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    else
    {
        fprintf(student_file, "%s,%d,%.2f\n", students_info.stu_Name , student_info.stu_id , student_info.stu_grade);
    }


    fclose(student_file);
}


int read_student_data(const char *filename ,int student_id)
{
   int found = 0 ;
   FILE *file = fopen(student_file, "r");
   students students_info ;


    if (student_file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    else
    {

        while (fscanf(student_file, "%d,%[^,],%c\n", &students_info.stu_id,students_info.stu_Name, &students_info.stu_grade) == 3)
        {
            if (students_info.stu_id == student_id)
            {
                printf("Student ID: %d\n", students_info.stu_id);
                printf("Name: %s\n", students_info.stu_Name);
                printf("Grade: %c\n", students_info.stu_grade);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("Student with ID %d not found.\n", student_info.stu_id);
        }

    }

}
void Edit_Student_Record(students *students_info, const char *New_Name, const char *new_pass  , const char *New_Course , float New_GPA) {
    if (New_Name != NULL) {
        strcpy(students_info->stu_Name, New_Name);
    }
    if (new_pass != NULL) {
        strcpy(students_info->stu_password, new_pass);
    }
    if (New_Course != NULL) {
        strcpy(students_info->stu_course, New_Course);
    }
    if (New_GPA >= 0) {
        students_info->stu_grade = New_GPA;
    }
    printf("Record with ID %d has been updated.\n", students_info->stu_id);
}
