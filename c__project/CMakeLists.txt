cmake_minimum_required(VERSION 3.28)
project(c__project)

set(CMAKE_CXX_STANDARD 17)

add_executable(c__project
        file_access.h
        file_access.c
        data_managment.h
        memory_managment.c
        data_managment.c
        student.h
        student.c
        admin.h
        admin.c
        authintication.h
        authintication.c
        menu.h
        menu.c
        "input and output.h"
        "input and output.c")
