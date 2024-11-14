#include<iostream>
using namespace std;
void swap(int , int);
int main(){
    int a=10,b=20;
    cout<<"a="<<a<<" b="<<b<<endl;
    swap(a,b);
    
    
    //函数调用前后并不影响实参的值（注意函数声明）
    cout<<"a="<<a<<" b="<<b<<endl;

}
void swap(int num1, int num2){

    cout<<"num1="<<num1<<" num2="<<num2<<endl;
    int temp=num1;
    num1=num2;
    num2=temp;
    cout<<"num1="<<num1<<" num2="<<num2<<endl;

}