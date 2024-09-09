//类模板的成员函数的类外实现 都需要加上模板参数列表

#include<iostream>
using namespace std;
template<class T1,class T2>
class Person{
    public:
    Person(T1 name,T2 age);
    void print();

    public:
    T1 name;
    T2 age;
};

//类外实现(函数模板具体化)

//自己的想法 error
/* Person<string,int>::Person(string name,int age){
    Person::name=name;
    this.age=age;
} */

//成员函数使用 模板参数列表实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    this->name=name;
    this->age=age;
}

template<class T1,class T2>
void Person<T1,T2>::print(){
}
int main(){
    Person<string,int> p("知识雪豹",99);
    p.print();
}