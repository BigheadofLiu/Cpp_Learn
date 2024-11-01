//
// Created by ZYB on 2024/10/22.
//

#include "save_file.h"
#include <iostream>
#include <fstream>
using namespace std;
int mian(){
    fstream fst;
    fst.open("./save_file/admin.txt",ios::out);
    if(!fst){
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    return 0;
}