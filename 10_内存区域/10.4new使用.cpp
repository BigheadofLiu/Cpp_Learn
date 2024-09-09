#include<iostream>  
using namespace std;
//new关键字用于申请堆区的数据
//关于new new关键字申请的空间需要用指针变量接收（栈区） 指针的指向为堆区
//int *arr=new int[10]
//delete []arr;
int * fun1();
int * fun2();  

int main(){
    int *p=fun1();
    cout<<*p<<endl;
    cout<<*p<<endl;
    cout<<*p<<endl;
    delete p;
    cout<<*p<<endl;
    fun2();
    

}
//new申请变量（开辟变量）
int * fun1(){
    int *p= new int(10);
    return p;
}

//new申请数组(开辟数组)
int * fun2(){
    int* arr=new int[10];  //语法格式重要！
    for(int i=0;i<10;i++){  //赋值
        arr[i]=i;
    }
    for(int i=0;i<10;i++){
        cout<<arr[i];
    }
    cout<<endl;
    // return arr[];
    //数组变量释放 delete []arr; 重要！
    // delete []arr;
    // for(int i=0;i<10;i++){
    //     cout<<arr[i];
    // }
}