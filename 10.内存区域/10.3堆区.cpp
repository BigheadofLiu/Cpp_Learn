#include<iostream>  
using namespace std;
//堆区 产生于程序运行后
//使用new来申请堆区的内存，堆区的内存由程序来管理，可以人为释放，也可以由编辑器自动释放。
//指针本质也是局部变量，存储在栈区，指向的数据存储在堆区（），堆区的数据在程序结束之前都存在，除非手动释放。
int * fun1();
int main(){
    int *p=fun1();
    cout<<*p<<endl;
    cout<<*p<<endl;
    cout<<*p<<endl;

}
int * fun1(){
    int *p=new int(10);
    return p;
}