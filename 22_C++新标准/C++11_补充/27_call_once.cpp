//
// Created by ZYB on 2025/3/11.
//
#include "iostream"
#include "mutex"
#include "thread"
using namespace std;
    // 函数原型:
// 定义于头文件 <mutex>
// template< class Callable, class... Args >
// void call_once( std::once_flag& flag, Callable&& f, Args&&... args );
// std::call_once()内部的回调函数只会被执行一次
once_flag flag;
void do_once(int a,string b){
    cout<<"id:"<<a<<"name:"<<b<<endl;
}
void do_something(int age,string name){
    static int num=1;
//    call_once(do_once(age,name)); //语法错误
    call_once(flag,do_once,age,name);
    cout<<"dosomething`s num="<<num++<<endl;
}
void fun1(){

    thread t1(do_something,18,"坤坤");
    thread t2(do_something,19,"丁真");
    thread t3(do_something,20,"芙蓉王源");
    //call_once()只执行了一次
}
int main(){
fun1();
}

