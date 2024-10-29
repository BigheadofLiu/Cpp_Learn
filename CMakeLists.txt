cmake_minimum_required(VERSION 3.27)
project(Vscode)

set(CMAKE_CXX_STANDARD 14)

include_directories(19_案例/机房预约2.0)

add_executable(Vscode
        19_案例/机房预约2.0/save_file/admin.txt
        19_案例/机房预约2.0/save_file/student.txt
        19_案例/机房预约2.0/save_file/teacher.txt
        19_案例/机房预约2.0/admin.cpp
        19_案例/机房预约2.0/admin.h
        19_案例/机房预约2.0/person.cpp
        19_案例/机房预约2.0/person.h
        19_案例/机房预约2.0/save_file.cpp
        19_案例/机房预约2.0/save_file.h
        19_案例/机房预约2.0/student.cpp
        19_案例/机房预约2.0/student.h
        19_案例/机房预约2.0/teacher.cpp
        19_案例/机房预约2.0/teacher.h
        19_案例/机房预约2.0/机房预约系统.cpp
        19_案例/机房预约2.0/computer_room.cpp
        19_案例/机房预约2.0/computer_room.h
        19_案例/机房预约2.0/order.cpp
        19_案例/机房预约2.0/order.h)
