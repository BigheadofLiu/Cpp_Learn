//类模板
#include<iostream>
#include<string.h>
using namespace std;

template<class Type1,class Type2>
class Person{
    public:
    Person(Type1 m_name,Type2 m_age ){
        name=m_name;
        age=m_age;       
    }
    public:
    Type1 name;
    Type2 age;
};
int main(){
    Person<string,int>p1("丁真",19);   //Person使用时需要指定数据类型

}