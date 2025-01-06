//
// Created by ZYB on 2024/12/31.
//
#include "iostream"
// C++11之前 const关键字表示： 只读 常量
// 变量只读并不等价于常量
// C++11中推出constexpr用于对const功能做分割：const表示只读 constexpr表示常量
// 这个关键字是用来修饰常量表达式的。所谓常量表达式，
// 指的就是由多个（≥1）常量（值不会改变）组成并且在编译过程中就得到计算结果的表达式。

// 常量表达式和非常量表达式的计算时机不同，
// 非常量表达式只能在程序运行阶段计算出结果，
// 但是常量表达式的计算往往发生在程序的编译阶段，
// 这可以极大提高程序的执行效率，

void test01(const int num1){
    const int num2=24;
//  num1++;             //error:num1只读
    int array_1[num1];  //为毛我成功了
    int array_2[num2];

    int a1=1314;
    int a2=520;
    const int& b=a1;
//    b=a2; //error &被修饰相当于常量指针常量
    a1=1111;
    std::cout<<sizeof(array_1)/sizeof(array_1[0])<<" ";
    std::cout<<sizeof(array_2)/sizeof(array_2[0])<<" ";
    std::cout<<b<<" ";
}
void test02(int num1){
    constexpr int num2=0;
    
}
int main(){
    test01(10);
}

