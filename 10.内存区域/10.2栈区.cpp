#include<iostream>  
using namespace std;
//栈区
//栈区由编译器来管理，变量的内存由编译器来回收与释放，不能在函数中返回局部变量的地址，因为该地址中会被编译器回收。
//函数的形参也存储于函数的栈区。

int * test1();
int mian(){
    // int a=10; //局部变量
    // const int a_a=10;//局部常量
    int *b=test1();
    cout<<*b<<endl;
    cout<<*b<<endl;

}
int * test1(){
    int c=10;
    return &c;
}

//address of local variable 'c' returned