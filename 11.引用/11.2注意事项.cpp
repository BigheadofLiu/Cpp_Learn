#include<iostream>  
using namespace std;
int main(){
    int b=100;
    //int &a; 定义的同时需要赋值
    int &a=b;
    int c=10;
    // &a=c; 无法再次引用到其他变量  //不支持更改指针的朝向

}