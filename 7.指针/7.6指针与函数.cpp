#include<iostream>
using namespace std;
void swap(int *,int *);
//函数调用传参数 分为实参和形参两种类型
//常规的 值传递 形参无法改变实参的值
//通过地 址传递 形参可以改变实参的值

int main(){
    int a=10,b=20;
    swap(&a,&b);
    cout<<a<<"\n"<<b<<endl;
}
void swap (int *p1,int*p2){
    int temp=*p1;  //注意这里的temp数据类型仍然为int形常量 而不是指针类型
    *p1=*p2;
    *p2=temp;
}