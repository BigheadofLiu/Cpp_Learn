//
// Created by ZYB on 2025/2/8.
//https://subingwen.cn/cpp/default-delete/
/*
 * =delete 用于禁止指定函数（重载）
 * =default 用于指定默认构造函数
 *
 */
/*
 * default
 * 不能使用 =default 修饰这六个函数以外的函数。
 */
//类内
#include "iostream"
using namespace std;
class A{
public:
    A()=default; //默认（无参构造）
    A(const A&)=default;//拷贝构造
    A(A&& obj)=default;//移动构造
    A& operator=(const A& obj)=default;//拷贝赋值构造
    A& operator=(A&& obj)=default;//移动赋值构造
    ~A()=default;//析构
};
//类外
class B{
    B();
    B(const B&);
    B(B&& obj);
    B& operator=(const B& obj);
    B& operator=(B&& obj);
    ~B();
};
B::B()=default;
B::B(const B&)=default;
B::B(B&& obj)=default;
B::B& operator=(const B& obj)=default;
B::B& operator=(B&& obj)=default;
B::~B()=default;


//delete
//禁用默认构造
class C{
public:
    C()=delete; //默认（无参构造）
    C(const C&)=delete;//拷贝构造
    C(C&& obj)=delete;//移动构造
    C& operator=(const C& obj)=delete;//拷贝赋值构造
    C& operator=(C&& obj)=delete;//移动赋值构造
    ~C()=delete;//析构
};
//禁用自定义函数（重载）可以禁用默认生构造函数
//内部delete
class D{
public:
    void func(){std::cout<<"hello"<<endl;}
    void func(int a){cout<<"func(int a)"<<endl}=delete;
    D()=delete;
};
//外部delete
D::D(const D&)=delete;

void test01(){
    D d1;
//    d1.func(1);
    d1.func();
}
int main(){
    test01();
}
