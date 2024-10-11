#pragma once
#include<iostream>
using namespace std;
//三种用户的基类 用于继承使用
class person{
    public:
    virtual void main_menu()=0; //个性化功能菜单（纯虚函数）
    string m_name;      //姓名
    string m_password;   //密码
};