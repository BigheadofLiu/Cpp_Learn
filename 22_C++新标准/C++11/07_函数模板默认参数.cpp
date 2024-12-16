#include <iostream>
#include <map>
#include "string"
#include <vector>
//c++11之前函数模具不支持指定默认类型
template<typename T1=int ,class T2>
T1 fun1(T2 val) {
    std::cout<<val<<std::endl;
    return 0 ;
}
int main(){
    fun1<std::string>("wdnmd");
    fun1<float, int>(1.0);  //支持修改
}