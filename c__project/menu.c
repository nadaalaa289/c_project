#include "menu.h"
#include <stdio.h>
void admin_mode()
{
    int choice;
    printf("Enter number to choose desired mode\n");
    printf(" 1. Add student record\n 2. Remove student record\n 3. View student record\n 4. View all records\n 5. Edit admin password\n 6. Edit student grade\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case(1):add_student_record();
            break;
        case(2):remove_student_data();
            break;
        case(3):view_student_record();
            break;
        case(4):view_all_students();
            break;
        case(5):edit_admin_password();
            break;
        case(6):edit_student_grade();
            break;
        default:
            printf("wrong choice.Try again");
            admin_mode();

    }
    int sec_choice;
    printf("Enter number to perform another task \n1.yes\n 2.no\n ");
    scanf("%d",&sec_choice);
    switch(sec_choice)
    {
        case(1):admin_mode();
            break;
        case(2):printf("Exiting.....");
            break;
    }


}
void user_mode()
{
    int choice;
    printf("Enter number to choose desired task\n");
    printf(" 1. View your record.\n"
           "2. Edit your password.\n"
           "3. Edit your name\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case(1):view_student_data();
            break;
        case(2):edit_student_pass();
            break;
        case(3):edit_student_name();
            break;
        default:
            printf("wrong choice.Try again");
            user_mode();

    }
    int sec_choice;
    printf("Enter number to perform another task \n1.yes\n 2.no\n ");
    scanf("%d",&sec_choice);
    switch(sec_choice)
    {
        case(1):user_mode();
            break;
        case(2):printf("Exiting.....");
            break;
    }
}
void select_mode()
{

    char password[50];
    printf("Enter  password: ");
    scanf("%s", password);
    if(authenticate_admin(password))
    {
        admin_mode();
    }
    else if(authenticate_student(password))
    {
        user_mode();
    }
    else
    {
        printf("wrong password.Try again");
        select_mode();

    }
}