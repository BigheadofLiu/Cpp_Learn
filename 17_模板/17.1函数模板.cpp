#include<iostream>
using namespace std;

template<class T>
T max(T &a,T &b){
  if (a>b)
  {
    return a;
  }else{
    return b;
  }
  
}
int main(){
int a=100;
int b=200;

float c=12.5;
float d=15.7;
cout<<max(a,b)<<endl; //模板自动类型推导
cout<<max<float>(c,d)<<endl; //指定类型

// cout<<max(a,d)<<endl;  //函数模板不支持隐式类型强转。
cout<<max<float>(a,d)<<endl; //指定类型后支持强转。
return 0;
}