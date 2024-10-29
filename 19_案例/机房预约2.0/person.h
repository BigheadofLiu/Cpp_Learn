//
// Created by ZYB on 2024/10/22.
//

#ifndef VSCODE_PERSON_H
#define VSCODE_PERSON_H
#include "iostream"
#include <string>
using namespace std;

class person {
public:
    virtual void main_menu()=0;
    std::string name; //姓名
    std::string password; //密码
};
#endif //VSCODE_PERSON_H
