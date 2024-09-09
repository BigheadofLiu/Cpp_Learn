#include<iostream>  
using namespace std;
//class 权限
//public protected private
//public 类内成员可以访问 类外也可以访问
//protected 类内成员可以访问 类外不可以访问 通过继承可以访问
//private 类内成员可以访问 类外成员不可以访问 通过继承不可以访问

class person{
    public:
    string name;

    protected:
    string car;

    private:
    string password;

    public:
    void fun1(){
        cout<<name<<endl;
    }

    protected:
    void fun2(){
        cout<<car<<endl;
    }

    private :
    void fun3(){
        cout<<password<<endl;
    }

    private:
    void fun4(){
        name="张三";
        car="帕拉梅拉";
        password="bjhl@0616";   //类内的成员变量均可以访问
    }
};

int main(){
    person p1;
    p1.name="大头儿子";
    p1.fun1();
    // p1.fun2(); //访问失败
    // p1.fun3();

    //p1.car="帕萨特"; //访问失败
    //p1.password="12345"; //访问失败
}
