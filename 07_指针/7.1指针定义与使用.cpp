#include<iostream>
using namespace std;
int main(){
    //指针的定义
    int *p;
    int a=100;
    p=&a;

    //指针的使用
    cout<<"a的地址是："<<p<<endl;
    cout<<"a的值是："<<*p<<endl;  //* 用于解地址

    //通过指针修改变量
    *p=1000;
    cout<<"a的值是："<<*p<<endl;

}