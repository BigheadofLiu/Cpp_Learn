#include"iostream"
using namespace std;
int main(){
    //if语句
    // if (/* condition */)
    // {
    //     /* code */
    // }

    // if (/* condition */)
    // {
    //     /* code */
    // }else{

    // }
    // if (/* condition */)
    // {
    //     /* code */
    // }else if (/* condition */)
    // {
    //     /* code */
    // }else if (/* condition */)
    // {
    //     /* code */
    // }else{

    // }

    // if (/* condition */)
    // {
    //     if (/* condition */)
    //     {
    //         /* code */
    //     }
        
    //     /* code */
    // }else if (/* condition */)
    // {
    //     /* code */
    // }else{

    // }
    
    //三目运算符 表达式1?表达式2:表达式3
    // int a=10;
    // int b=20;
    // a>b?cout<<"a>b"<<endl:cout<<"a<=b"<<endl;

    // int a=true;
    // a?cout<<"a=true"<<endl:cout<<"a=false"<<endl;

    //等价于
    // if(表达式1){
    //     表达式2

    // }esle{
    //     表达式3
    // }

    // int a=10;
    // int b=20;
    // b>a?cout<<"b>a"<<endl:cout<<"b<=a"<<endl;

    //三目运算符可以用来赋值(可以是表达式右值，也可以是表达式左值)
    int a=10;
    int b=20;
    int c=(a>b?a:b); //把最大值赋值给c
    cout<<c<<endl;
    
    //三目运算符也可以被赋值
    a>b?a:b=100;  //将最大值赋值为100
    cout<<a<<endl;
    cout<<b<<endl;
// 20
// 10
// 100

}