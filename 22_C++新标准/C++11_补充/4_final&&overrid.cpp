#include <iostream>
#include "string"
using namespace std;
//final 用于限制类或者虚函数被继承
class father{
public:
    virtual void fun1(){
        cout<<"i m father`s fun1"<<endl;
    }
};
class son:public father{
public:
    void fun1() override final{
        cout<<"i m son`s fun1"<<endl;
    }
};
class grandson final :public son{
public:
//    void fun1(){} //继承失败
};
//class orangeson:public grandson{};//继承失败

//override
//用于子类重写父类虚方法时使用

