#include<iostream>  
using namespace std;
const int a=100; //全局常量
int b=100;//全局变量
static int c=100; //全局静态变量
static const int d=100;//全局静态常量
int main(){
    const int a_a=100; //局部常量
    int b_b=100; //局部变量
    static int c_c=100; //静态变量;
    static const int d_d=100; //静态常量
    
    cout<<"全局常量a的地址为"<<&a<<endl;
    cout<<"全局变量b的地址为"<<&b<<endl; //全局区


    cout<<"局部常量a_a的地址为"<<&a_a<<endl;
    cout<<"局部变量b_b的地址为"<<&b_b<<endl; //栈区

    cout<<"字符串变量的地址为"<<&("hello world!")<<endl;
    cout<<"局部静态变量c_c的地址为"<<&c_c<<endl;
    cout<<"局部静态常量d_d的地址为"<<&d_d<<endl; //全局区

    cout<<"全局静态变量c的地址为"<<&c<<endl;
    cout<<"全局静态常量d的地址为"<<&d<<endl; //全局区

}