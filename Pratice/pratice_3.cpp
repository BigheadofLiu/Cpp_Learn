//
// Created by ZYB on 2025/3/25.
//
#include "iostream"
//类模板的成员函数&构造函数的类外实现
template<class T1,class T2>
class person{
public:
    person(T1,T2);
    T1 name;
    T2 age;
    void print(person*);
};

template<class T1,class T2>
person<T1,T2>::person(T1 m_name,T2 m_age) {
    this->name=m_name;
    this->age=m_age;
}
template<class T1,class T2>
void person<T1, T2>::print(person<T1, T2> *) {
    std::cout<<this->age<<std::endl;
    std::cout<<this->name<<std::endl;
}