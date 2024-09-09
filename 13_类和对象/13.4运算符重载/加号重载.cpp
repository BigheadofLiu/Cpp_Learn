#include<iostream>  
using namespace std;
//加号运算符重载
//1.全局函数加号重载
//2.成员函数加号重载

class Person{
    public:
    
//成员函数加号重载
    Person operator+(Person &p1){
        Person temp;
        temp.m_age=this->m_age+p1.m_age;
        temp.m_high=this->m_high+p1.m_high;
        return temp;
    }

    Person operator+(int a){
        Person temp;
        temp.m_age=this->m_age+a;
        temp.m_high=this->m_high+a;
        return temp;
    }


    // private: 
    int m_age;
    int m_high;
};
void fun1(){
    Person p1;
    p1.m_age=10;
    p1.m_high=10;

    Person p2;
    p2.m_age=10;
    p2.m_high=10;

    Person p3;
    Person p4;

    p3=p1.operator+(p2);  
    // p3=p1+p2; //等价于以上语句 p4=p1+10与其不能同时使用
    
    // p4=p1.operator+(10);
    p4=p1+10; //等价于以上语句

    cout<<"p3.m_age="<<p3.m_age<<endl;
    cout<<"p3.m_high="<<p3.m_high<<endl;

    cout<<"p4.m_age="<<p4.m_age<<endl;
    cout<<"p4.m_high="<<p4.m_high<<endl;
};

//全局函数加号重载
Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_age=p1.m_age+p2.m_age;
    temp.m_high=p1.m_high+p2.m_high;
    return temp;
}

int main(){
    fun1();
}
