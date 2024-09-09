#include<iostream>  
using namespace std;
void fun1(const int &c);
//常量引用
//作用 用于修饰形参 防止函数内部的误操作（防止形参修改实参）
int main(){
    int b=100;
    // int &a=b; //引用必须指向一片内存空间，不能是一个具体的值
    // int &a=10; //error:非常量引用的初始值必须为左值
    const int &a=10; //使用常量引用可以指向一个具体的值 本质：int temp=10;const int &a=temp;
    fun1(b);
    
}
void fun1(const int &c){
    // a=1000; //此时函数内部无法修改a的值，a变为只读的不支持修改，防止误操作 error：表达式必须是可修改的左值
    cout<<c<<endl;

}