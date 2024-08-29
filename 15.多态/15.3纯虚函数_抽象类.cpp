#include<iostream>
#include"string.h"
using namespace std;
//纯虚函数与抽象类
//纯虚函数 virtual 函数=0;
//含有纯虚函数的基类称为抽象类
//抽象类无法实例化对象
//子类必须重写虚方法不然仍然是抽象类
class baseclass{
    public:
    virtual void fun1()=0;
};
class son:public baseclass{
    void fun1(){};

}; 
void test(){
    // baseclass b1; //抽象类无法实例化
    // son s1; //没有重写父类虚方法仍然属于抽象类。
    son s1; //实例化对象成功
}