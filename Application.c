#include "application.h"
admin_mode()
{
    char password[10];
    const char default_password[] = "1234";
    int attempts = 3;
    int authenticated = 0;

    printf("Enter the password: ");
    while (attempts > 0)
    {
        scanf("%s", password);
        if (strcmp(password, default_password) == 0)
        {
            authenticated = 1;
            break;
        }
        else
        {
            attempts--;
            if (attempts > 0)
            {
                printf("Incorrect password. You have %d attempts left.\n", attempts);
                printf("Enter the password: ");
            }
        }
    }

    if (authenticated)
    {
        printf("Access granted.\n");

        /*************************************************************/
        students students_info[100];
        int num_students = 0;
        int choice;

        do
        {
            printf("\nAdmin Menu:\n");
            printf("1. Add student record\n");
            printf("2. Remove student record\n");
            printf("3. View student record\n");
            printf("4. View all records\n");
            printf("5. Edit admin password\n");
            printf("6. Edit student grade\n");
            printf("7. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:

             add_student(student_file);

                break;
            case 2:
                //   remove_student_record(students, &num_students);
                break;
            case 3:
                int idToFind;
                printf("Enter the ID of the student you want to view: ");
                scanf("%d", &idToFind);

                viewStudentRecordById(student_file,idToFind);

                break;
            case 4:
                  viewAllRecords(student_file);
                break;
            case 5:
                //   edit_admin_password();
                break;
            case 6:
                //  edit_student_grade(students, num_students);
                break;
            case 7:
                //  printf("Exiting admin mode.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
            }
        }
        while (choice != 7);

        /*************************************************************/

void add_student(FILE *student_file) {
    Student s;
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter total grade: ");
    scanf("%d", &s.total_grade);
    printf("Enter unique id: ");
    scanf("%d", &s.id);
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter gender: ");
    scanf(" %c", &s.gender);
    printf("Enter password: ");
    scanf("%s", s.password);

    fprintf(student_file, "%s,%d,%d,%d,%c,%s\n", s.name, s.total_grade, s.id, s.age, s.gender, s.password);
}


void viewStudentRecordById(const char *student_file, int id) {
    FILE *file = fopen(student_file, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", student_file);
        return;
    }

    char line[MAX_RECORD_LENGTH];
    StudentInfo students_info[MAX_STUDENTS];
    int index = 0;

    while (fgets(line, sizeof(line), student_file)) {
        char *token = strtok(line, ",");
        students_info[index].stu_id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(students_info[index].stu_Name, token);

        token = strtok(NULL, ",");
        students_info[index].stu_grade = token[0];

        token = strtok(NULL, ",");
        strcpy(students_info[index].stu_course, token);

        index++;
    }

    fclose(student_file);

    int i;
    for (i = 0; i < index; i++) {
        if (students_info[i].stu_id == id) {
            printf("Student ID: %d\n", students_info[i].stu_id);
            printf("Name: %s\n", students_info[i].stu_Name);
            printf("Grade: %c\n", students_info[i].stu_grade);
            printf("Course: %s\n", students_info[i].stu_course);
            return;
        }
    }
    printf("No record found for ID: %d\n", id);
}




void viewAllRecords(const char *student_file) {
    FILE *file = fopen(student_file, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", student_file);
        return;
    }

    char line[100];
    printf("Name\t\tCourse\t\tGPA\n");
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        StudentRecord record;

        strcpy(record.name, token);

        token = strtok(NULL, ",");
        strcpy(record.course, token);

        token = strtok(NULL, ",");
        record.gpa = atof(token);

        printf("%s\t\t%s\t\t%.2f\n", record.name, record.course, record.gpa);
    }

    fclose(file);
}


    }

    /**************************************************************/





    student_mode()
    {



    }

