#include<iostream>  
using namespace std;
//引用的本质：指针常量 int * const p;
void fun1(int &);
int main(){
    int b=100;
    int &a=b;  //int * const a=b;
    a=20;      //int *a=20;
    cout<<a<<endl;
    cout<<b<<endl;

    fun1(b);
    cout<<a<<endl;
    cout<<b<<endl;


}

void fun1(int &a){  //void fun1(int * const a)
    a=200; //*a=200; 改变指针的值
}