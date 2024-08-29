#include<iostream>
using namespace std;
int main(){
    /*int a,b;
    //cin>>a>>b; //同时输入两个数 c++方式
    scanf("%d %d",&a,&b); //c方式在c++中同样可以运行
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<a%b<<endl;*/

    //取模（小数不能取模，对0不能取模）

    //前置递减与后置递减

    //前置 变量自身先进行进行自加或者自减 然后参与运算
    //后置 变量先参加运算 后自身进行自加或者自减
    int c=10;
    /*++c;
    cout<<c<<endl;*/
    // --c;
    // cout<<c<<endl;

    // int b=c++ * 10;
    // cout<<b<<endl;
    // cout<<c<<endl;

    int d=++c * 10;
    cout<<d<<endl;
    cout<<c<<endl;
    

    
}