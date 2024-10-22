#pragma once
#include "person.h"
#include "teacher.h"
#include"student.h"
#include<algorithm>

namespace admin{
    class admin:public person{
    public:
        admin();

        admin(string,string);
        virtual void main_menu();

        void add_order();

        static void show_order();

        void show_computer_info();

        void clear_order();

        static void manager_order(person* &);

        void vector_init();

        static bool check_order(int,int);
        /* void login(string,int);*/

        /*[[maybe_unused]] void print_order_student(student&);

        [[maybe_unused]] void print_order_teacher(teacher&);*/

    public:
        static vector<student::student> v_stu;
        static vector<teacher::teacher> v_tea;
    };
}
