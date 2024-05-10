#include "memory_managment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *allocate_name(const char *name) {

    char *name_copy= (char *)malloc(50 * sizeof(char));
    if (name_copy == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(name_copy, name);
    return name_copy;
}
char *allocate_password(const char *pass) {

    char *pass_copy = (char *)malloc(30 * sizeof(char));
    if (pass_copy == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(pass_copy, pass);
    return pass_copy;
}
void free_name(char *name) {
    free(name);
    name=NULL;
}
void free_password(char *pass) {
    free(pass);
    pass=NULL;
}

