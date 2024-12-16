//类模板成员函数调用时机
//发生函数调用时才创建相关成员函数
//普通类成员函数一开始就创建
#include"iostream"
#include"string.h"
using namespace std;

class person1{
    public:
    void test1(){
        cout<<"111"<<endl;
    }

};
class person2{
    public:
    void test2(){
        cout<<"222"<<endl;
    }

};
template<class T>
class person3{
    public:
    // person3(T& obj){
    //     this->obj=obj;
    // }
    T obj;
    void fun1(){
        obj.test1();

    }
    void fun2(){
        obj.test2();
    }
};

int main(){
// person1 p2;
person3<person1> p1;
// person2 p3;
person3<person2> p2;
p1.fun1();
p2.fun2();

}
