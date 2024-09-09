#include<iostream>
using namespace std;
#include<string.h>

struct student
{
 
 int age;
 string name;
 int grade;
};

int main(){
    student s1=
    // (13,"刘俊龙",9), //错误写法，应该用{ }
    {13,"刘俊龙",9};
    student * p=&s1;
    //通过指针访问结构体变量
    cout<<p->age<<"|"<<p->grade<<"|"<<p->name<<"|"<<endl;



}