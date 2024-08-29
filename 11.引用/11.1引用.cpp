#include<iostream>  
using namespace std;
int main()
{
    int a=100;
    int &b=a;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    //通过引用b修改a的值 修改成功
    b=10;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    

}