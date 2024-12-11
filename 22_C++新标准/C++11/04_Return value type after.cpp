#include<iostream>
//不知所云。。
//语法
//C++返回值类型后置（跟踪返回值类型）
// template <typename T, typename U>
// auto add(T t, U u) -> decltype(t + u)
// {
//     return t + u;
// }
template <class A,class B,class C>
A add_1(B b,C c){
    return b+c;
}
template <class T1,class T2>
auto add_2(T1 t1,T2 t2)-> decltype(t1+t2){  //auto会根据传入的参数不同 自动推导相应的类型
    return  t1+t2;
}

void fun1(){
    double a,b;
    a=2.1,b=3.3;
    auto c= add_1<decltype(a+b)>(a,b);  //知道add内部算法的情况下，很多时间add内部实现细节并不知道
    auto d= add_2<>(a,b);
    std::cout<<c<<std::endl;
    std::cout<<d<<std::endl;
}
void fun2(){


}
int main(){
    fun1();
}


