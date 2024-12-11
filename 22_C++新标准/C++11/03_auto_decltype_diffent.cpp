#include <iostream>
#include <typeinfo> //using typeid
#include <vector> //using vector
#include <string>
/*
 * 1.语法格式区别
 * auto 根据右值推导 优点：简洁
 * decltype根据表达式推导跟右值无关 优点：灵活
 *
 * 2.对cv限定符的处理
 * cv（const volatile）
 * decltype会保留cv限定符
 * auto会选择性保留：
 * auto 关键字对 cv 限定符的推导规则：
 * 如果表达式的类型不是指针或者引用，auto 会把 cv 限定符直接抛弃，推导成 non-const 或者 non-volatile 类型。
 * 如果表达式的类型是指针或者引用，auto 将保留 cv 限定符。
 *
 * 3.对引用的处理
 * decltype 会保留引用类型，而 auto 会抛弃引用类型，直接推导出它的原始类型。
 * 
 */
void fun1(){
    const int a=10;
    auto b=&a; //b:const int* 保留const
    auto c=a;  //c:int(const舍弃)
    auto d=&a; //d:const int* 保留const
    auto &e=a;

//    *a=100; //赋值失败
//    *b=100; //赋值失败
//    c=100;  //赋值成功
}
void fun2() {
    int a = 10;
    int &b = a;
    auto c = b;  //c为int（&被舍弃）
    c = 20;

//    decltype(b) d=a; //d为int&
//    d=30;
    std::cout << a << " " << b << " " << c << std::endl;  //10 10 20
//    std::cout<<a<<" "<<b<<" "<<d<<std::endl;  //30 30 30

}
void fun3(){

}
int main(){
    fun2();
}
