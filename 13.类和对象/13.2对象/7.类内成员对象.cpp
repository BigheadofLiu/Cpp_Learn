#include "iostream"
using namespace std;
#include"string.h"
class Cat{
    public:
    Cat(string name,string kinds):c_name(name),c_kinds(kinds){
     cout<<"我是cat的初始化函数"<<endl;
    }
    string c_name;
    string c_kinds;

    ~Cat(){
        cout<<"我是cat的析构函数"<<endl;
    }

};

//类对象作为类成员（一个类内包含其他的类）
class Person{
    public:
    Person(string name,Cat cat):p_name(name),p_cat(cat){
        cout<<"我是person的初始化函数"<<endl;
    }
    string p_name;
    Cat p_cat;

    ~Person(){
        cout<<"我是person的析构函数"<<endl;
    }

};

void fun1(){
    Cat c1("火腿肠","银渐层");
    Person p1("刘俊龙",c1);
    // cout<<p1.p_name<<endl;
    // cout<<p1.p_cat.c_name<<endl;
    // cout<<p1.p_cat.c_kinds<<endl;
}
int main(){

fun1();

}