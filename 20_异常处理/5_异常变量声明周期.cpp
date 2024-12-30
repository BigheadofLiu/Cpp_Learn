#include<iostream>
using namespace std;
 class my_exception{
    public:
    my_exception(){
        cout<<"myexception默认构造"<<endl;
    }
    my_exception(const my_exception& e){
        cout<<"myexception拷贝构造"<<endl;
    }
    ~my_exception(){
        cout<<"myexception析构函数"<<endl;
    }
 };
 void test01(){ //使用普通对象接异常值
    try{
        throw my_exception();
    }catch(my_exception e){
        cout<<"普通对象接异常"<<endl;
    }

//输出
/* 
myexception默认构造
myexception拷贝构造
普通函数接异常
myexception析构函数
myexception析构函数 */
 }

 void test02(){
    //使用对象指针接异常
    try{
        throw my_exception();
    }catch(my_exception* e){
        cout<<"对象指针接"<<endl;
        delete e;   //记得释放指针
    }
// 输出：
// myexception默认构造
// terminate called after throwing an instance of 'my_exception'
// myexception析构函数
 }

 void test03(){
    //对象引用接异常
    try{
        throw my_exception();
    }catch(my_exception &e){
        cout<<"对象指针接"<<endl;
        /* delete e; */
    }
//输出
// myexception默认构造
// 对象指针接
// myexception析构函数

 }


 int main(){
   /*  test01(); */
   /* test02(); */
   test03();

 }
