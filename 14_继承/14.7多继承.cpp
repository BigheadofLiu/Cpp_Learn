#include<iostream>  
using namespace std;
//多继承
class dad1{
    public:
    int a=100;
};
class dad2{
    public:
    int a=200;
};
//多继承语法: class 子类名：继承方式 父类名1,继承方式 父类名2...
class son:public dad1,public dad2{
    public:
    int a=300;
};
void test01(){
    son s1;
    cout<<s1.a<<endl;
    cout<<sizeof(s1)<<endl;
    cout<<s1.dad1::a<<endl;
    cout<<s1.dad2::a<<endl; //多继承同名成员属性需要添加作用域
}
int main(){
    test01();

}
/*
class dad1      size(4):
        +---
 0      | a
        +---

class dad2      size(4):
        +---
 0      | a
        +---

class son       size(12):
        +---
 0      | +--- (base class dad1)
 0      | | a
        | +---
 4      | +--- (base class dad2)
 4      | | a
        | +---
 8      | a
        +---
*/