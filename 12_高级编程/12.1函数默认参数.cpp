#include<iostream>  
using namespace std;
//函数默认参数
//1.函数声明与函数定义，只能有一个定义参数。
//2.函数可以有默认参数值，从第一个定义值的变量往右的所有变量都必须定义。
//3.函数的默认参数需要在函数声明时定义 语法：返回值类型 函数名（参数=默认值）{};

void fun1(int a=10,int b=20);  //函数声明中定义参数  函数定义时不支持修改

void fun2(int,int);  //函数声明中没有定义参数，函数定义中可以定义参数 函数使用过程中以传入的参数为准

void fun3(int a,int b = 10,int c = 1000){   //函数声明中直接定义函数的参数和操作。
    cout<<a+b+c<<endl;
};

int main(){
    fun1(); //函数声明时已定义默认参数 可以不传入参数 也可以传入自己需要的数
    
    fun2(10,20);

    fun3(10,20,30);  //也可以定义三个
    fun3(10);       //可以直定义一个参数
}
void fun1(/*int a=20,int b=20*/ int a,int b){
    cout<<a+b<<endl;   //previous specification in 'void fun1(int, int)' 函数声明中的默认参数不支持再定义修改
}

void fun2(int c=10,int d=30){  //函数定义中定义了默认参数 
    cout<<c+d<<endl;
}

