//列表初始化
#include "iostream"


auto fun1(){
    auto a_1={1};
    auto a{1};

    int b_1[]={10,20,30};
    int b[]{10,20,30};

    class C{
    public:
        decltype(a) a;
        decltype(a) b;
    };
    C c={10,20};
    C d{10,20};
    C{20,10};
}
auto fun2(){
    auto a{1}; //a=1
    class A{
    public:
        A(){}
        A(decltype(a)){};
    private:A(const A&){};
    };
    A a_1{}; //调用默认构造
    A a_2{10}; //调用A(decltype(a)){}
    //  A a_3{a_2}; //error:Calling a private constructor of class 'A'
    A a_4={123};
//    A a_5={a_2};
}
auto fun3(void){
    class A{
    public:
        A(int,int);
        int a;
        int b;
    };
    return A{10,10};  //列表初始化作为返回值
}

//列表初始化适用于聚合体，非聚合体不适用
//聚合：
//如果一个 struct 或 class 满足以下全部条件，则它是聚合类型：
//没有用户定义的构造函数（即 没有 A() {}）。
//没有私有/受保护成员（所有成员都是 public）。
//没有虚函数（virtual）。
//没有继承（不能继承其他 class）。
class A{
public:
    int a;
    int b;
    static int c;
};
class B{
public:
    int a;
protected:
    int b;
};
class C{
public:
    C():a(3),b(4){
    }
    int a;
    int b;
};
class D{
public:
    int a;
    int b;
};
void test_01(){
//    A a{1,2,3};//error
      A a{1,2};
      A::c=3;
//    B b{1,2}; //error
//    C c{1,23}; //error
      D d{1,2};//success
}

/*
 * 在C++的STL容器中，可以进行任意长度的数据的初始化，
 * 使用初始化列表也只能进行固定参数的初始化，
 * 如果想要做到和STL一样有任意长度初始化的能力，
 * 可以使用std::initializer_list这个轻量级的类模板来实现。
*/


