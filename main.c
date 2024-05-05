#include <stdio.h>
#include <stdlib.h>
#include "student_database.h"

int mode;

int main()
{
    const char *student_file = "student.csv";

    printf("1. Admin Mode\n");
    printf("2. User Mode\n\n");
    printf("Enter mode: ");
    scanf("%d", &mode);

    switch(mode)
    {
    case 1 :
           admin_mode();
        break ;
    case 2 :
          student_mode();
        break;
    default :
        printf("Invalid mode\n");
    }

    return 0;
}
