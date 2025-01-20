//
// Created by ZYB on 2024/12/31.
//
#include <iostream>
using namespace std;
class A{
public:
    A(){}
    A(int a):min(a){
        this->min=a;
        cout<<a<<endl;
    }
    A(int a,int b):min(a),mid(b){
        this->min=a;
        cout<<a<<endl;
        this->mid=b;
        cout<<b<<endl;

    }
    A(int a,int b,int c):min(a),mid(b),max(c){
        /*int temp;
        if(a>b){
            temp=b;
            b=a;
            a=temp;
        }
        if(a>c){
            temp=c;
            c=a;
            a=temp;
        }
        if(b>c){
            temp=c;
            c=b;
                b=temp;
        }*/
        this->min=a;
        cout<<a<<endl;
        this->mid=b;
        cout<<b<<endl;
        this->max=c;
        cout<<c<<endl;

//        cout<<min<<" "<<mid<<" "<<max<<endl;
    }
    int min,mid,max=0;
};
void test01(){
    A a1{10};
    A a2{10,20};
    A a3{10,20,30};
}

class  B{
public:
    B(){}
    B(int a){
        this->min=a;
        cout<<a<<endl;
    }
    B(int a,int b): B(a){
        this->mid=b;
        cout<<b<<endl;
    }
    B(int a,int b,int c):B(a,b)/*,max(c)*//*min(a),mid(b),*/{
        this->max=c;
        cout<<c<<endl;
    }
    int min,mid,max;
};
//委托构造函数（优化类内冗余的构造函数代码）
//使用委托构造函数无法使用初始化列表方式为类内成员变量赋值
//tips:
// 1.这种链式的构造函数调用不能形成一个闭环（死循环），否则会在运行期抛异常。
// 2.如果要进行多层构造函数的链式调用，建议将构造函数的调用的写在初始列表中而不是函数体内部，否则编译器会提示形参的重复定义。
// 3.在初始化列表中调用了代理构造函数初始化某个类成员变量之后，就不能在初始化列表中再次初始化这个变量了。
//
void test02(){
    B b1{1,2,3};
}

//继承构造函数
class base{
public:
    base(){};
    base(int a):min(a){
    }
    base(int a,int b):min(a),mid(b){
    }
    base(int a,int b,int c):min(a),mid(b),max(c){
    }

    void fun(int a){
        cout<<"i`m base fun(int a)"<<endl;
    }
    void fun(int a,int b){
        cout<<"i`m base fun(int a,int b)"<<endl;
    }
    int min,mid,max;
};
class child_1:public base{
    //非委托构造需要重新定义
public:
    void fun(){
        cout<<"i`m child_1 fun()"<<endl;
    }
    child_1():base();
    child_1(int a): base(a){}
    child_1(int a,int b):base(a,b){}
    child_1(int a,int b,int c): base(a,b,c){}
};
class child_2:public base{
public:
    using base::base;  //使用父类对象的构造函数
    using base::fun;   //启用被隐藏父函数  普通成员函数也可以继承
    void fun(){  //自定义fun函数会隐藏父对象同名函数
    cout<<"child_2`s fun()"<<endl;
    }
};
void test03(){
    //使用非构造继承
    child_1 c1{1,2,4};
    //使用构造继承
    child_2 c2{1,2,4};
}
void test04(){
    child_2 c1;
    c1.fun();
    c1.fun(2);

    child_1 c2;
    c2.fun();
//  c2.fun(3); //调用失败

}
int main(){
//test01();
//test02();
test04();
}