#include<iostream>  
using namespace std;
//引用作为函数返回值
int & fun1(); 
int & fun2();
int * fun3();

int main(){
    // int a=fun1();

    int &a=fun2();
    cout<<a<<endl;
    cout<<a<<endl;

    fun2()=1000;   //如果函数的返回值是引用，那么该函数调用可以作为左值被赋值
    // fun1()=200;  //赋值失败 局部变量无法引用

    //fun3()=100; //指针作为返回值无法作为左值（引用的价值体现）

    cout<<a<<endl;
    cout<<a<<endl;


    // int* a=fun3();
    // cout<<*a<<endl;

}
//返回局部变量的引用 
int & fun1(){
    int a=100; //局部变量
    return a;
    // warning: reference to local variable 'a' returned 局部变量a不支持返回。
    //原因：局部变量存储在栈区，函数运行结束之后内存会被释放
}

int & fun2(){
    static int a=100;
    return a;
    //静态变量引用可以返回 静态变量存储在全局区，函数运行结束之后内存不会被释放
}

// 等同于fun2()
int * fun3(){
    static int a=100;
    return &a;
}