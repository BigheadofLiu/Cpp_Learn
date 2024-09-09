#include<iostream>  
using namespace std;
//继承基础语法：
// class 子类：继承方式 父类{
//}
class Cat{

    public:
    // Cat(string name,int weigth){
    //     this->weigth=weigth;
    //     this->name=name;
    // } //不重写默认构造

    string name;
    int weigth;

    void print(){
    cout<<"我是："<<this->name;
    cout<<"我的重量："<<this->weigth;
    }
};
class buou:public Cat{
    public:
    buou(string name,int weigth){
        this->weigth=weigth;
        this->name=name;
    //可以自定义自己的方法
    }
    void printf_1(){
        cout<<this->name<<""<<this->weigth<<endl;  //支持通过this指针访问继承自父类成员的属性
    }

    //也可以自定义父类外的成员属性
    int cat_1;
    int cat_sleep;

};
void fun1(){
    buou b1("面包",6);  //父类自定义构造函数不能继承；
    b1.print(); //父类的成员属性、方法可以继承 
    b1.printf_1();
    
};
//发散 继承的继承还可以继承吗？
class mianbao:public buou{


}; //结论继承的继承还可以继承
int main(){
    fun1();
}