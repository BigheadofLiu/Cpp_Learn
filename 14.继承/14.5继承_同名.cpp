#include<iostream>  
using namespace std;
//同名属性、函数的继承
//子类调用父类的成员属性和方法需要加作用域

class dad{
    public:
    int a=100;
    void fun(){
        cout<<"dad fun()"<<endl;;
    }
    void fun(int a){
        cout<<"dad fun(int)"<<endl;
    }
};
class son:public dad{
    public:
    int a=200;

    void fun(){
        cout<<"son fun()"<<endl;
    }

    void fun(int){
        cout<<"son fun()"<<endl;
    }


};
void fun1(){
    son s1;
    cout<<s1.a<<endl;
    cout<<s1.dad::a<<endl;

    s1.fun();
    s1.fun(100);
    
    s1.dad::fun();
    s1.dad::fun(100); //支持调用重载函数
    

}
int main(){
fun1();   

}
