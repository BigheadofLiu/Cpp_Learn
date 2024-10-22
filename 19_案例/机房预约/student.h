#pragma once
#include"person.h"
namespace student {
    class student : public person {
    public:
        student();//默认构造
        student(int, string, string);//有参构造
        virtual void main_menu();  //重新父类虚方法
        void apply_order();

        void show_my_order();

        void show_all_order();

        void cancel_order();

        int m_sid;  //学号
    };
}
