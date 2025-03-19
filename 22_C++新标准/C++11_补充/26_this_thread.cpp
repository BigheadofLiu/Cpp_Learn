//
// Created by ZYB on 2025/3/11.
//
#include "iostream"
#include "string"
#include "thread"
#include "chrono"
//this_thread命名空间下的四个函数
//get_id() 获取当前进程下的进程id
//sleep_for(chrono::) 运行态->阻塞态 (休眠时长) 指定线程阻塞一定的时间长度duration 类型，之后解除阻塞
//sleep_until() 指定线程阻塞到某一个指定的时间点time_point类型，之后解除阻塞
//yield() 让出cpu 运行态->就绪态
void fun1(){
    std::cout<<"hello"<<std::endl;
}
void test01(){
    std::thread t1(fun1);
    t1.join();
    std::cout<<std::this_thread::get_id()<<std::endl;

}
void test02(){
    std::thread t1(fun1);
    t1.join();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"thread weak up"<<std::endl;
}
void test03(){
    auto now=std::chrono::steady_clock::now();
    std::chrono::seconds sec(4);
    std::thread t1(fun1);
    t1.join();
    std::this_thread::sleep_until(now+sec);
    std::cout<<"thread weak up"<<std::endl;
}
void fun2(){
    for (int i = 0; i <10000000000000000 ; i++) {
        std::cout<<"子线程:"<<std::this_thread::get_id()<<i<<std::endl;
    }
}
void test04(){
    std::thread t1(fun2);
    std::thread t2(fun1);
    t1.join();
    std::this_thread::yield();
    t2.join();
}
int main(){
//test01();
//test02();
//test03();
test04();
}