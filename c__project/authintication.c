#include "authintication.h"
int authenticate_student(const char *password) {
    read_student_data(-2, password);
}
int authenticate_admin(const char *password)
{
    read_admin_file(password);
}