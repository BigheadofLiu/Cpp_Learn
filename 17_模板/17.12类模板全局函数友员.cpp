//类模板的全局函数友员
//1.类外实现
//2.类外实现

#include<iostream>
#include<string.h>
using namespace std;

template<class T1,class T2> class Person; //不先声明 函数模板无法识别。。
//类外实现 模板定义声明实现写开头
template<class T1,class T2>
void print(Person<T1,T2> &p){
    cout<<p.age<<endl;
    cout<<p.name<<endl;
} 

template<class T1,class T2>
class Person{
    //类外实现
    friend void print<>(Person<T1,T2> &p);  //<>强制调用 很关键
    //类内实现(常用)
    friend void print1(Person<T1,T2> &p){
    cout<<p.age<<endl;
    cout<<p.name<<endl;
}
    public:
    Person(T1 name,T2 age){
        this->age=age;
        this->name=name;
    }

    private:
    T1 name;
    T2 age;
};


 
//类外实现 非函数模板形式
/* void print(Person<string,int> &p){
    cout<<p.age<<endl;
    cout<<p.name<<endl;
} */

int main(){
    Person<string,int> p1("面包",22);
    print(p1);
    print1(p1);
}