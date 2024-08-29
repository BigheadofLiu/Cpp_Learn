#include<iostream>  
using namespace std;
/*函数重载 
作用: 一段程序中可以有两个或两个及其以上的同名函数
条件：1.函数同属于一个作用域下
    2.函数名称相同
    3.函数参数类型不同、参数数量不同、参数顺序不同
！！：返回值类型不同不能作为函数重载的依据
*/
void func(int a){cout<<"我是重载1号"<<endl;};
void func(double b){cout<<"我是重载2号"<<endl;};
void func(int a,double b){cout<<"我是重载3号"<<endl;};
void func(double b,int a){cout<<"我是重载4号"<<endl;};
int main(){
    //传入不同的参数，调用不同的同名函数（重载）
    func(1);
    func(1.1);
    func(1,1.1);
    func(1.1,1);

}
