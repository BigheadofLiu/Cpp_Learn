#include<iostream>
#include "string"
void test(){
    int a=10086;
    auto b=std::to_string(a);
    std::cout<<b<<std::endl;
}
void test1(){
    auto a="10086 后面部分";  //为啥使用字符会报错？
    auto b=std::stoi(a);
    auto c=std::stod((a));
    auto d=std::stof(a);
    std::cout<<b<<" "<<c<<" "<<d<<std::endl;
}
int main(){
//test();
test1();
}

/*
 * 如果字符串中所有字符都是数值类型，整个字符串会被转换为对应的数值，并通过返回值返回
如果字符串的前半部分字符是数值类型，后半部不是，那么前半部分会被转换为对应的数值，并通过返回值返回
如果字符第一个字符不是数值类型转换失败
 */
