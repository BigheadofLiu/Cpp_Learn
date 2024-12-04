#include<iostream>
#include<thread>
#include<string>
#include<memory>  //智能指针头文件
#include <mutex>  //互斥量头文件

int count;
std::mutex m1;
std::mutex m2;
//void auto_add(){
//    for(int i=0;i<100000;i++){
////        m1.lock(); //添加互斥锁
//        count++;
////        m1.unlock();
//    }
//}
void test01(){
    for (int i = 0; i < 1000; ++i) {
        m1.lock();
        m2.lock();
//    auto_add();
        m1.unlock();
        m2.unlock();
    }
}
void test02(){
    for (int i = 0; i < 1000; ++i) {
        m1.lock();
        m2.lock();
//    auto_add();
        m2.unlock();
        m1.unlock();   //调整m1,m2的获取顺序从而避免死锁
    }
}
int main(){
    std::thread t1(test01);
    std::thread t2(test02);
    t1.join();
    t2.join();
    std::cout<<"over"<<std::endl;
    return 0;
}