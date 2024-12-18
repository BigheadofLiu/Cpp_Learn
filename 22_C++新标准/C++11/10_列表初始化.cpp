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



