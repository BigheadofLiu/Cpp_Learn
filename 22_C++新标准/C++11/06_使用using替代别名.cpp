//
// Created by ZYB on 2024/12/10.
//
//用来替代 typedef
/*
 * typedef 现有类型 新名
 * 1.基本类型的别名
 * 2.指针类型的别名
 * 3.数组类型的别名
 * 4.函数指针的别名
 * 5.结构体的别名
 * 6.兼容跨平台代码
 */
#include <iostream>
#include <map>
#include "string"
#include <vector>
//typedef局限性
//函数重载
typedef int int_1;
int_1 a=12; //本质还为int
void fun1(int){
}
//void fun1(int_1){  //Redefinition of 'fun1'重载失败
//}

//2定义模板
void fun2() {
    typedef std::map<int,float> map_i_f;
    using map_i_f =std::map<int,float>;  //等价

    typedef std::map<std::string,int> map_s_i;
    using map_s_i =std::map<std::string,int>; //等价

    map_i_f m1;
    std::map<int,float> m2;
    m1.insert(std::make_pair(1,1.1));
    m2.insert(std::make_pair(1,1.1));  //

    typedef std::vector<int> v_int;
    v_int v1;
    v1.push_back(1);
}
template <class T1>
struct my_map_1{
    typedef std::map<T1,std::string> map_T_s; //C++11之前写法
};
my_map_1<int>::map_T_s map1;

template <class T2>
using my_map_2=std::map<T2,std::string>;   //新写法
my_map_2<int> map2;

void fun3(){
    //旧

}
int main(){

}










