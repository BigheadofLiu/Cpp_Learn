//
// Created by ZYB on 2024/10/18.
//

#include "order_login.h"
 void login::login(std::string file_name, int type) {
     //用于接收输入数据
     int id = 0;
     string name;
     string pwd;
     string tip;
     string error_tip;
     if (type == 1) {
          file_name=STUDENT_FILE;
          tip="请输入学号：";
          error_tip="学号重复，请重新输入";
     } else if (type == 2) {
          file_name = TEACHER_FILE;
          tip = "请输入职工编号：";
          error_tip = "职工号重复，请重新输入";
         }
     std::cout<<tip<<endl;
     while (true){
         std::cin>>id;
         bool ret=admin::admin::check_order(id,type);
         if(ret){
             cout<<error_tip<<endl;
         }else{
             cout<<"账号不存在，可以继续添加"<<endl;
             break;
             }
         }
     cout << "请输入用户名：" << endl;
     cin >> name;
     cout << "请输入密码：" << endl;
     cin >> pwd;
     person *person = nullptr;
     fstream fst1(file_name, ios::in);
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
             while (fst1 >> s_id && fst1 >> s_name && fst1 >> s_pwd) {
                 if (s_id == id && s_name == name && s_pwd == pwd) {
                     cout << "身份验证成功" << endl;
                     system("pause >nul");
                     system("cls");
                     person = new student::student(id, name, pwd);
                     person->main_menu();
                     return;
                 }
             }
         } else if (type == 2) {
             //教职工身份认证
             int s_id;
             string s_name;
             string s_pwd;
             while (fst1 >> s_id && fst1 >> s_name && fst1 >> s_pwd) {
                 if (s_id == id && s_name == name && s_pwd == pwd) {
                     cout << "身份验证成功" << endl;
                     system("pause >nul");
                     system("cls");
                     person = new teacher::teacher(id, name, pwd);
                     person->main_menu();
                     return;
                 }
             }
         } else if (type == 3) {
             //管理员身份认证
             // int s_id;
             string s_name;
             string s_pwd;
             while (fst1 >> s_name && fst1 >> s_pwd) {
                 if (s_name == name && s_pwd == pwd) {
                     cout << "身份验证成功" << endl;
                     system("pause >nul");
                     system("cls");
                     person = new admin::admin(name, pwd);
                     // person.manager_order();
                     // person->main_menu();
                     admin::admin::manager_order(person);
                     return;
                 }
             }
         }
         cout << "验证登录失败" << endl;
         system("pause >nul");
         system("cls");
         return;
 }
