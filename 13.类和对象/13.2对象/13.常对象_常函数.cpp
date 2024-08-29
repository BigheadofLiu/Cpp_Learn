#include "iostream"
using namespace std;
//常对象 与常函数
/*常函数：成员函数后加const 语法格式：void fun1（）const{
    常函数中不能调用普通成员属性
    如果想要调用 成员属性需要加mutable
}
常对象：const Person p1
    常对象只能调用常函数
*/
class Person{

    public:
    Person(){

    }

    //常函数
    void fun1()  const   //这里加上const 相当于 const Person * const this 把指针常量改变为 常量指针常量  指针的值和指向均不支持修改
    {
    // this->m_age=100; //编译器报错 不允许修改 加this后仍然报错  本质为：Person * const this
                        //this指针的本质为 指针常量
        // this=NULL; //所以this指针的指向不可以改变 指向的值可以改变
        this->m_sex=0;
        // this->m_high=180;
        cout<<"我是常函数"<<endl;

    }
    void fun2(){
        m_age=100;
    }

    int m_age;
    mutable int m_sex;
    // const int m_high;
    };

    void fun2(){
    const Person p1;  //常对象 常对象只能调用常属性(mutable修饰)或者常函数
    p1.m_sex=1;
    // p1.m_age=1; //修改失败
    p1.fun1();
    // p1.fun2(); //fun2调用失败
    // p1.m_high=180;
       
    }

int main(){
    fun2();

}