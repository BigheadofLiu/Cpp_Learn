#pragma once
#include<iostream>
#include<fstream>
#include"save_file.h"
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
//三种用户的基类 用于继承使用
class person{
    public:
    virtual void main_menu()=0; //个性化功能菜单（纯虚函数）
    std::string m_name;      //姓名
    std::string m_password;   //密码
};