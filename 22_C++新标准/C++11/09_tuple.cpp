#include <iostream>
#include "tuple"
/*
 *
1) 默认构造函数
constexpr tuple();
2) 拷贝构造函数
tuple (const tuple& tpl);
3) 移动构造函数
tuple (tuple&& tpl);
4) 隐式类型转换构造函数
    template <class... UTypes>
    tuple (const tuple<UTypes...>& tpl); //左值方式
    template <class... UTypes>
    tuple (tuple<UTypes...>&& tpl);      //右值方式
5) 支持初始化列表的构造函数
    explicit tuple (const Types&... elems);  //左值方式
    template <class... UTypes>
    explicit tuple (UTypes&&... elems);  //右值方式
6) 将pair对象转换为tuple对象
    template <class U1, class U2>
    tuple (const pair<U1,U2>& pr);       //左值方式
    template <class U1, class U2>
    tuple (pair<U1,U2>&& pr);            //右值方式
 */
void fun1(){
    std::tuple<int,float> i_f;
    std::tuple<double,int,int> d_i_i;
    
}