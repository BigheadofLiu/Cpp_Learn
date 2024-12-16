#include<iostream>
#include<string.h>
using namespace std;

//函数模板可以自动推倒参数类型 类模板不可以
//类模板参数列表可以有默认参数(c++11后函数模板也可以有默认参数)

template<class T1,class T2=int>
class Person{
    public:
    Person(T1 name,T2 age){
        this->name=name;
        this->age=age;
    }
    public:
    T1 name;
    T2 age;
};

template<class T>
void printf(T &a,T &b){
    cout<<a<<b<<endl;
}

void test1(){
    int a,b=30;
    printf(a,b); //自动推导类型
}

void test2(){
    // Person p1=("蔡徐坤",18);   //无法推导类模板类型
    Person <string,int>p1("蔡徐坤",18);  //手动指定参数类型
    cout<<p1.age<<p1.name<<endl;   
}
void test03(){
    Person<string> p2("丁真",999);  //类模板默认参数
    cout<<p2.age<<p2.name<<endl;
}
void test04(){
    Person<string,string> p1("蔡徐坤","丁真"); //默认参数类型可以修改
    cout<<p1.age<<p1.name<<endl;
}

int main(){
    test1();
    test2();
    test03();
    test04();
}
