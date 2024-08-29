#include<iostream>  
using namespace std;
//使用引用作为函数形参，用于修饰实参
void swap1(int &a,int &b);  //引用传递
void swap2(int *a,int *b);  //地址传递
void swap3(int ,int); //值传递 形参不能修饰实参
int main(){
    int a=10,b=20;
    swap3(a,b);  //值传递
    cout<<a<<" "<<b<<endl;

    swap1(a,b);  //引用传递
    cout<<a<<" "<<b<<endl;

    swap2(&a,&b);  //地址传递
    cout<<a<<" "<<b<<endl;

   

}
void swap1(int &a,int &b){
    int temp=a;  //直接用一个变量接收 函数内部同值传递一致（更好理解）
    a=b;
    b=temp;
}
void swap2(int *a,int *b){
    int* temp=a; //需要用指针进行接收
    a=b;
    b=temp;    
}
void swap3(int a,int b){
    int temp=a;
    a=b;
    b=temp; 
}