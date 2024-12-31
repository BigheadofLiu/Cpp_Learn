#include<iostream>
#include<climits>
void test(){
    //long long
    long long num1=123456LL;  //LL后缀用于编译器解析为long long(防止解析为int?)
    long long num2=123456ll;
    auto num3=123456LL;

    //unsigned long long
    unsigned long long num4=123456ULL;
}
void test02(){
    long long max=LLONG_MAX;
    long long min=LLONG_MIN;

    unsigned long long ull_max=ULLONG_MAX;
    std::cout<<max<<std::endl;
    std::cout<<min<<std::endl;
    std::cout<<ull_max<<std::endl;
    // out >>
    // 9223372036854775807
    // -9223372036854775808
    // 18446744073709551615
}
void test03(){
    //转换过程中，低等级整型需要转换为高等级整型，有符号的需要转换为无符号整形。
}
int main(){
test02();
}