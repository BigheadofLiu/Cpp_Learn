//
// Created by ZYB on 2024/10/23.
//

#ifndef VSCODE_ADMIN_H
#define VSCODE_ADMIN_H
#include "person.h"
#include "student.h"
#include "teacher.h"
#include <iostream>
#include <fstream>
#include "save_file.h"
#include <vector>
#include <algorithm>
#include "computer_room.h"
using namespace std;

class admin:public person {
public:
    admin();
    admin(string name, string pwd);
    void main_menu() override;  //管理员菜单
    void add_order();  //添加预约
    void show_order();  //查看预约
    void clear_order_file();  //清除预约
    void init_vector(); //初始化容器
    bool check_order(int,int);  //检查预约
    void show_computer_room();  //查看机房信息
    void init_computer();
    /*void manage_order();  //管理预约*/

    vector<student> v_stu;  //学生容器
    vector<teacher> v_tea;  //老师容器
    vector<computer_room> v_computer;  //机房容器
};
void print_order_student(student &);
void print_order_teacher(teacher &);


#endif //VSCODE_ADMIN_H
