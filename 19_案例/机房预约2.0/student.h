//
// Created by ZYB on 2024/10/22.
//

#ifndef VSCODE_STUDENT_H
#define VSCODE_STUDENT_H
#include "person.h"
#include <vector>
#include "computer_room.h"
#include "save_file.h"
#include "order.h"
#include "cstdlib"

class student: public person {
public:
    student(); //构造函数
    student(int id,string name, string password); //有参构造函数
    void main_menu() override; //学生菜单
    void apply_order(); //预约函数
    void cancel_order(); //取消预约函数
    void show_my_order(); //查看预约函数
    void show_all_order();//查看所有预约
    void init_computerRoom(); //初始化机房
    int s_id; //学号

    vector<computer_room> v_computer; //机房容器
};
#endif //VSCODE_STUDENT_H
