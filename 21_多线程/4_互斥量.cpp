#include<iostream>
#include<thread>
#include<string>
#include<memory>  //智能指针头文件
#include <mutex>  //互斥量头文件

int count=0;
std::mutex m1;
void auto_add(){
    for(int i=0;i<100000;i++){
        m1.lock(); //添加互斥锁
        count++;
        m1.unlock();
    }
}
void  test01(){
    //数值较大时得到的结果错误
    std::thread t1(auto_add);
    std::thread t2(auto_add);
    t1.join();
    t2.join();
    std::cout<<count<<std::endl;

}
int main(){
    test01();

    return 0;
}
