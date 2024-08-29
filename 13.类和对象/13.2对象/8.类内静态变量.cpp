#include "iostream"
using namespace std;
#include"string.h"

class Person{
    public:
    static int p_name;//类内定义 
    
    private:
    static int p_sex;  //私有权限

};
int Person::p_name=10; //类外赋值
int Person::p_sex=0; //保护类型支持赋值 不支持访问
int main(){
    //1.通过对象访问
    // Person p1;
    // cout<<p1.p_name<<endl;
    // p1.p_name=20;  //修改静态变量的值
    // Person p2;
    // cout<<p2.p_name<<endl;

    //2.通过类名访问
    cout<<Person::p_name<<endl;
    // cout<<Person::p_sex<<endl; //私有权限类外访问失败

}