//
// Created by ZYB on 2024/10/22.
//

#ifndef VSCODE_TEACHER_H
#define VSCODE_TEACHER_H
#include "person.h"
#include "order.h"
class teacher:public person {
public:
    //成员方法
    teacher();
    teacher(int t_id,string name,string pwd);
    void main_menu() override;
    void show_all_order();
    void valid_order();
public:
    //成员属性
    int t_id{};
};
#endif //VSCODE_TEACHER_H
