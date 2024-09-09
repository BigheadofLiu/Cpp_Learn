#include "iostream"
using namespace std;
//静态成员方法 
class Person{
    public:
    // private:  可以设置为私有权限
    static void fun1(){
    p_name=20;
    // p_sex=10; //调用普通属性失败 只能调用静态成员变量

    cout<<"调用了类内静态方法"<<endl;
    }
    static int p_name;
    int p_sex;
};
int Person::p_name=10;
int main(){
    //1.
    // Person p1;
    // p1.fun1();
    
    //2.
    Person::fun1();
}