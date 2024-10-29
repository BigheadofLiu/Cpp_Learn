#include "student.h"
#include "teacher.h"
#include "admin.h"
#include "save_file.h"
#include <fstream>
#include "computer_room.h"
#include <iostream>
using namespace std;
//函数声明
void show_menu();  //主菜单
void admin_menu(person* &); //管理员菜单
void student_menu(person* &); //学生菜单
void teacher_menu(person* &); //教师菜单

int main(){}

//函数实现
void show_menu(){
    while(true){
        std::cout << "======================  欢迎来到机房预约系统  =====================" << endl;
        std::cout << endl << "请输入您的身份" << endl;
        std::cout << "\t\t -------------------------------\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          1.学生代表           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          2.老    师           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          3.管 理 员           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          0.退    出           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t -------------------------------\n";
        std::cout << "输入您的选择: ";
}
}
void admin_menu(person* &ad){
    while(true){
        ad->main_menu();
        admin* man=(admin*)ad; //强制类型转换,将父类指针转换为子类指针

    }

}
void student_menu(){}
void teacher_menu(){}

