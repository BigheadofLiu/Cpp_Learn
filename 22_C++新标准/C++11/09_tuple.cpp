#include <iostream>
#include "tuple"
/*
 *
 * tuple可以理解为一种容器 用于存储不同类型的数据 具有不可变性
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
    std::tuple<int,float> first;
    std::tuple<double,int,int> second;
    std::tuple<int,float> third(first);
    std::tuple<int,float> fourth(std::make_tuple(1,1.1));
    std::tuple<int,float>   five(std::make_pair(1,1.1));
}

//make_tuple()函数 创建tuple右值对象
void fun2(){
    auto first=std::make_tuple("wdnmdzy",121);
    const int a = 0; int b[3];
    auto second=std::make_tuple(a,b);

}
//常用函数
//函数或类模板	                        描 述
//tup1.swap(tup2) swap(tup1, tup2)	tup1 和 tup2 表示类型相同的两个 tuple 对象，tuple 模板类中定义有一个 swap() 成员函数， 头文件还提供了一个同名的 swap() 全局函数。 swap() 函数的功能是交换两个 tuple 对象存储的内容。
//get(tup)	tup 表示某个 tuple 对象，num 是一个整数，get() 是 头文件提供的全局函数，功能是返回 tup 对象中第 num+1 个元素。
//tuple_size::value	tuple_size 是定义在 头文件的类模板，它只有一个成员变量 value，功能是获取某个 tuple 对象中元素的个数，type 为该tuple 对象的类型。
//tuple_element<I, type>::type	tuple_element 是定义在 头文件的类模板，它只有一个成员变量 type，功能是获取某个 tuple 对象第 I+1 个元素的类型。
//forward_as_tuple<args…>	args… 表示 tuple 对象存储的多个元素，该函数的功能是创建一个 tuple 对象，内部存储的 args… 元素都是右值引用形式的。
//tie(args…) = tup	tup 表示某个 tuple 对象，tie() 是 头文件提供的，功能是将 tup 内存储的元素逐一赋值给 args… 指定的左值变量。
//tuple_cat(args…)	args… 表示多个 tuple 对象，该函数是 头文件提供的，功能是创建一个 tuple 对象，此对象包含 args… 指定的所有 tuple 对象内的元素。




