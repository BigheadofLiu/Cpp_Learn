#include <iostream>
#include "string"
using namespace std;
//final 用于限制类或者虚函数被继承
/*C++中增加了final关键字来限制某个类不能被继承，
或者某个虚函数不能被重写，和Java的final关键字的功能是类似的。
如果使用final修饰函数，只能修饰虚函数，并且要把final关键字放到类或者函数的后面。
*/
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

