//
// Created by ZYB on 2025/2/14.
//
#include "iostream"
using namespace std;
//枚举
void test01(){
    enum {a,b,c}; //匿名枚举
    enum demo{d,e,f};//有名枚举
//1.旧枚举
    enum color1{green,blue,yellow};
    cout<<demo::d<<endl;  //cout:0
//enum color2{pink,blue}; //error:Redefinition of enumerator 'blue'
//具名（有名字）的enum类型的名字，以及 enum 的成员的名字都是全局可见的
}
void test02(){

//强枚举（枚举类）
    enum class color3{blue,wright,pink};
    enum class color4:char {blue,yellow,black};
    std::cout<<int(color3::blue)<<endl; //cout:0
    //强类型枚举具有以下几点优势∶
    //强作用域，强类型枚举成员的名称不会被输出到其父作用域空间。
    //强类型枚举只能是有名枚举，如果是匿名枚举会导致枚举值无法使用（因为没有作用域名称）。
    //转换限制，强类型枚举成员的值不可以与整型隐式地相互转换。
    //可以指定底层类型。强类型枚举默认的底层类型为 int，但也可以显式地指定底层类型，
    //具体方法为在枚举名称后面加上∶type，其中 type 可以是除 wchar_t 以外的任何整型。
//    int m=color3::pink; //不支持隐式转换，虽然枚举底层默认为int
//    int n=blue; //缺少命名空间
    if(int(color3::pink)>=2){
        cout<<"okey"<<endl;  //okey
    }
    cout<< sizeof(color3::blue)<<endl; //4:sizeof(int)
    cout<<sizeof(color4::blue)<<endl;//1:sizeof(char)
//    enum class 的成员没有公有私有之分，也不会使用模板来支持泛化的声明
}
int main(){
//    test01();
    test02();
}
