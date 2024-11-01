cmake_minimum_required(VERSION 3.27)
project(2_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2_0
        save_file/admin.txt
        save_file/computer_room.txt
        save_file/order.txt
        save_file/student.txt
        save_file/teacher.txt
        admin.cpp
        admin.h
        computer_room.cpp
        computer_room.h
        order.cpp
        order.h
        person.cpp
        person.h
        save_file.cpp
        save_file.h
        student.cpp
        student.h
        teacher.cpp
        teacher.h
        机房预约系统.cpp)
