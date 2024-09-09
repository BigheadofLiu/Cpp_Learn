#include<iostream>  
using namespace std;
//静态属性和静态方法的继承调用
//:继承
//::作用域
class dad{
    public:
    static int a;
    static void fun(){
        cout<<"dad void fun()"<<endl;

    }
    static void fun(int a){
    cout<<"dad void fun(int)"<<endl;     
    }
};

class son:public dad{
    public:
    static int a;
    static void fun(){
    cout<<"son void fun()"<<endl;
    }
    static void fun(int a){
    cout<<"son void fun(int)"<<endl;
        
    }
};
int dad::a=100;
int son::a=200;

//静态成员属性访问
void test01(){
    //1.通过对象访问
    son s1;
    cout<<s1.a<<endl;
    cout<<s1.dad::a<<endl;
   

    //2.通过类名访问
    cout<<son::a<<endl;
    cout<<son::dad::a<<endl; //通过子类访问父类静态属性（重要）
    cout<<dad::a<<endl;
}

//访问静态方法
void test02(){
    //1.
    son s2;
    s2.fun();
    s2.fun(10);

    s2.dad::fun();
    s2.dad::fun(10);

    //2.
    son::fun();
    son::fun(100);
    
    //通过作用域访问
    son::dad::fun();
    son::dad::fun(100);

    dad::fun();
    dad::fun(100);


}
int main(){
    test01();
    test02();
}