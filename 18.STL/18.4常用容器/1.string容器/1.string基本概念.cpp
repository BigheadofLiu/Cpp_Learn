/*string 是一个管理char*容器的类（容器）
char* 是一个指针
string作为容器管理char*所分配的内存 不会出现溢出和越界*/

#include<string>
#include<iostream>
#include<typeinfo>
using namespace std;

int main(){
    string a="abcdefghijkl";
    cout<<sizeof(a)<<endl; //24
    cout<<typeid(a).name()<<endl;   //NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    cout<<typeid(a[1]).name()<<endl;  //char

    
}