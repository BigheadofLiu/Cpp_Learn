#include<iostream>
using namespace std;
template <class T1,class T2>
class Person{
    public:
    Person(T1 age,T2 name){
        this->age=age;
        this->name=name;
    }
    void print(){
        cout<<this->age<<endl<<this->name<<endl;
    }
    public:
    T1 age;
    T2 name;
};

//
//1.通过指定类型传参（常用）
void test1(Person<int,string> &p){
    p.print();
}

//2.函数参数模板化
template<class T1,class T2>
void test2(Person<T1,T2> &p){
    p.print();
}

//3.类模板化
template<class T>
void test3(T &p){
    p.print();
}

int main(){
    Person<int,string> p1(18,"坤坤");
    test1(p1);

    Person<int,string> p2(19,"丁真");
    test2(p2);

    Person<int,string> p3(21,"王源");
    test2(p3);
}