#include<iostream>
using namespace std;
int main() {
    int a = 10;
    int b = 20;

    //常量指针 指针的指向可以改变 指针指向的值不支持修改
    const int* p=&b;
    p = &a;
    //*p = 10; //无法对常量指针指向的值进行修改

    //指针常量 指针的指向无法修改 指针指向的值可以修改
    int* const p1 = &a;
   // p1=&b;  //不支持修改指针指向
    *p1=100;
    cout<<*p1<<endl;  //修改成功

    //常量指针常量
    const int* const p2=&a;
    //p2=&b; 
    //*p2=1000;  两者均不支持修改

    



}
