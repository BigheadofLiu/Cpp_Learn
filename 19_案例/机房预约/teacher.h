#pragma once
#include "person.h"

class teacher:public person{
public:
    teacher();
    teacher(int,string,string);
    virtual void main_menu();
    void show_all_order();   //
    void valid_order();

    int m_tid;  //职工编号
};