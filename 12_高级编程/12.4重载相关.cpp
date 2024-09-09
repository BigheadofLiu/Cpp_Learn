#include<iostream>  
using namespace std;
/*1.函数重载+引用
函数重载+引用  √（正确）
函数重载+默认参数 ×（歧义） 避免使用
*/
void func(int &a){
cout<<"调用int &a"<<endl;
};
void func(const int &a){
cout<<"调用const int &a"<<endl;
};

void func1(int a,int b=10){
cout<<"调用int a,int b=10"<<endl;

};
void func1(int a){
cout<<"int a"<<endl;

};


int main(){
    int a=10;
    func(a);
    func(10);

    // func1(10); //有多个 重载函数 "func1" 实例与参数列表匹配 此时函数接收参数会造成歧义
    // func1(10);



}