#include<iostream>
#include<string.h>
//原始字面量：C++11新特性
//R"(原始字符串)" 原始字面量 直接输出字符串中的所有字符，包括转义字符


void test(){
    std::cout<<"D:\hello\world"<<std::endl; //包含转义字符 无法完整输出
    std::cout<<"D:\\hello\\world"<<std::endl; // \\完整输出
    std::cout<<R"(D:\hello\world)"<<std::endl; //原始字面量 直接输出
    std::cout<<R"(D:\\hello\\world)"<<std::endl;
}
void test2() {
   std::cout<<R"caixukun(wdnmd)caixukun"<<std::endl;
//   std::cout<<R"a()b"<<std::endl; //error 前后需要保持一致
}
int main(){
//    test();
test2();
}