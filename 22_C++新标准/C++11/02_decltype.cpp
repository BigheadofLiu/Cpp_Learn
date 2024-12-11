#include <iostream>
#include <typeinfo> //using typeid
#include <vector> //using vector
#include <string>
/*
decltype(exp) varname = value;
decltype通过exp表达式推导变量类型与右值(value)无关
所以,decltype声明的变量无需初始化

规则:
(1)如果 exp 是一个不被括号( )包围的表达式，或者是一个类成员访问表达式，
或者是一个单独的变量，那么 decltype(exp) 的类型就和 exp 一致，这是最普遍最常见的情况。
(2)如果 exp 是函数调用，那么 decltype(exp) 的类型就和函数返回值的类型一致。
(3)如果 exp 是一个左值，或者被括号( )包围，那么 decltype(exp) 的类型就是 exp 的
引用；假设 exp 的类型为 T，那么 decltype(exp) 的类型就是 T&。
*/

void fun1(){
    int a=0;
    class A{
    public:
        int a;
        std::string b;
    };
    const int & c=a;
    A d;

    decltype(a) e=a; //a为int，推导为a的type
    decltype(c) f=a; //c为const int&推导为相同类型
    decltype(d.a) g=a;  //d.a为int
    decltype(d.b) h="wdnmd";
}

int& func_int_r(int, char);  //返回值为 int&
int&& func_int_rr(void);  //返回值为 int&&
int func_int(double);  //返回值为 int
const int& fun_cint_r(int, int, int);  //返回值为 const int&
const int&& func_cint_rr(void);  //返回值为 const int&&
void fun2(){
    int x=0;
    const int y = 0;
    decltype(func_int_r(10,20)) a=x;  //a：int&  函数调用要带参数，并不会真正执行
    decltype(func_cint_rr()) b=0;
    decltype(func_int(1.1)) e=x;
}
void fun3(){
    int a=10;
    decltype((a)) b=a; //带（）推导为int&
    decltype(a) c=a; //不带() 推导为int

    decltype(a+b) e=a+b; //表达式
    decltype(e=a+b) f=a; //左值表达式
}
//左值：指那些在表达式执行结束后依然存在的数据，持久性的数据
//右值：在表达式执行结束后不再存在的数据，也就是临时性的数据
//很简单的方法来区分左值和右值，对表达式取地址，如果编译器不报错就为左值，否则为右值。

//decltype用法
//auto不能用于类的非静态成员变量的推导而decltype可以
void fun4(){

}
template <typename T>
class Base {
public:
    void func(T& container) {
        m_it =container.begin();
    }
private:
//    typename T::iterator m_it;  //error:注意这里
//    T::iterator m_it;
    decltype(T().begin()) m_it; //?
};

int main(){
        const std::vector<int> v;
        Base<const std::vector<int>> obj;
        obj.func(v);
        return 0;
}
