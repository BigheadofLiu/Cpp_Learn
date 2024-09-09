#include<iostream>  
using namespace std;
//函数占位参数
//用于函数声明时，语法： 返回值类型 函数名（变量类型···）
//占位参数 也可以有默认参数
void func1(int,int){
    cout<<"我是函数占位参数"<<endl;
}

void func2(int=10,int=10){
    cout<<"我是func2"<<endl;
}

int main(){
    func1(10,10); //此时调用函数必须传入参数，但是传入的参数目前还无法获取使用，之后会有用处。
    func2(); //此时无需传入参数
}

