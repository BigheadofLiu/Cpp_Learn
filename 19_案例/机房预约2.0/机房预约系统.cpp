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
void login_check(std::string,int);

int main() {
    int select = 0;
    while (true) {
        person *ad= nullptr;
        show_menu();
        cin >> select;
        switch (select) {
            case 1:
                /*student_menu(ad);*/
                login_check(STUDENT_FILE,select);
                break;
            case 2:
                /*teacher_menu(ad);*/
                login_check(TEACHER_FILE,select);
                break;
            case 3:
                /*admin_menu(ad);*/
                login_check(ADMIN_FILE,select);
                break;
            case 0:
                system("pause >nul");
                system("cls");
                /*break;*/
                return 0;
            default:
                cout << "输入有误，重新输入" << endl;
                system("pause >nul");
                system("cls");
                break;
        }
        system("pause >nul");
        return 0;
    }
}
//函数实现
void show_menu(){
    while(true){
        std::cout << "======================  欢迎来到机房预约系统  =====================" << endl;
        std::cout << endl << "请输入您的身份" << endl;
        std::cout << "\t\t -------------------------------\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          1.学生代表             |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          2.老    师            |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          3.管 理 员            |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          0.退    出            |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t -------------------------------\n";
        std::cout << "输入您的选择: ";
        break;
}
}
void admin_menu(person* &ad){
    while(true){
        admin* man=(admin*)ad; //强制类型转换,将父类指针转换为子类指针
        man->main_menu();
        int select;
        cin >> select;
        switch(select){
            case 1:
                man->add_order();
                break;
            case  2:
                man->show_order();
                break;
            case 3:
                man->show_computer_room();
                break;
            case 4:
                man->clear_order_file();
                break;
            case 0:
                delete man;
                system("pause >nul");
                system("cls");
                return;
        }
    }
}
void student_menu(person* &stud){
    while(true) {
        student *stu = (student *) stud;
        int select;
        stu->main_menu();
        cin >> select;
        switch (select) {
            case 1:
                stu->apply_order();
                break;
            case 2:
                stu->show_my_order();
                break;
            case 3:
                stu->show_all_order();
                break;
            case 4:
                stu->cancel_order();
                break;
            case 0:
                delete stu;
                system("pause >nul");
                system("cls");
                return;
        }
    }
}
void teacher_menu(person* &teach){
    while(true){
        teacher* tea=(teacher*) teach;
        int select;
        switch(select){
            case 1:
                tea->show_all_order();
                break;
            case 2:
                tea->valid_order();
                break;
            case 3:
                delete tea;
                system("pause >nul");
                system("cls");
                return;
        }
    }
}
void login_check(std::string file_name, int type) {
    //用于接收输入数据
    person* check_in;
    int id = 0;
    string name;
    string pwd;
    fstream fst1;
    fst1.open(file_name, ios::in);
    if (!fst1.is_open()) {
        std::cout << "文件打开失败" << endl;
        fst1.close();
        return;
    }
    if (type == 1) {

        //学生身份认证
        //用于获取来自文件的数据
        int s_id;
        string s_name;
        string s_pwd;
        cout<<"请输入学生id:"<<endl;
        cin>>id;
        cout<<"请输入姓名:"<<endl;
        cin>>name;
        cout<<"请输入密码:"<<endl;
        cin>>pwd;
        while (fst1 >> s_id && fst1 >> s_name && fst1 >> s_pwd) {
            if (s_id == id && s_name == name && s_pwd == pwd) {
                cout << "身份验证成功" << endl;
                system("pause >nul");
                system("cls");
                check_in = new student(id, name, pwd);
                /*check_in->main_menu();*/
                student_menu(check_in);
                fst1.close();
                return;
            }
        }
    } else if (type == 2) {
        //教职工身份认证
        int s_id;
        string s_name;
        string s_pwd;
        cout<<"请输入职工id:"<<endl;
        cin>>id;
        cout<<"请输入姓名:"<<endl;
        cin>>name;
        cout<<"请输入密码:"<<endl;
        cin>>pwd;
        while (fst1 >> s_id && fst1 >> s_name && fst1 >> s_pwd) {
            if (s_id == id && s_name == name && s_pwd == pwd) {
                cout << "身份验证成功" << endl;
                system("pause >nul");
                system("cls");
                check_in = new teacher(id, name, pwd);
                /*check_in->main_menu();*/
                teacher_menu(check_in);
                fst1.close();
                return;
            }
        }
    } else if (type == 3) {
        //管理员身份认证
        // int s_id;
        string s_name;
        string s_pwd;
        /*cout<<"请输入账号id:"<<endl;
        cin>>id;*/
        cout<<"请输入管理员id:"<<endl;
        cin>>name;
        cout<<"请输入密码:"<<endl;
        cin>>pwd;
        while (fst1 >> s_name && fst1 >> s_pwd) {
            if (s_name == name && s_pwd == pwd) {
                cout << "身份验证成功" << endl;
                system("pause >nul");
                system("cls");
                check_in = new admin(name, pwd);
                // person.manager_order();
                // person->main_menu();
                /*admin::admin::manager_order(person);*/
                admin_menu(check_in);
                fst1.close();
                return;
            }
        }
    }
    cout << "验证登录失败" << endl;
    system("pause >nul");
    system("cls");
    return;
}

