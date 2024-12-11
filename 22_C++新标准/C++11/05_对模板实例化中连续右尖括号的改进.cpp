#include <iostream>
template <class T1>
class A{
public:
    static T1 a;
};
template <class T2>
class  B{
public:
    T2 b;
};
template <int N>
struct  C{
public:

};
void fun1(){
//    A<B<int> >::a; //c++11之前写法 >>会被识别为右移运算符
    A<B<int>>::a;
    return;
}
void fun2(void){
    C< (100>>2) > xx;  //success
//    C< 100 >> 2 > xx;  //error:Expected unqualified-id

}
int main(){
    fun1();
}