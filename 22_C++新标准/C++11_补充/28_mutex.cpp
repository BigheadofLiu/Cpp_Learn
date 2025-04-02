//
// Created by ZYB on 2025/3/12.
//
#include "iostream"
#include "mutex"
#include "thread"
//mutex的成员函数
//1.lock()
//void lock()
//lock()函数用于给临界区加锁，并且只能有一个线程获得锁的所有权，它有阻塞线程的作用
static int num1=0;
std::mutex num1_mutex; //用于保护num

//线程同步
void fun1(int id){
    for (int i = 0; i < 4; i++) {
        num1_mutex.lock();
//        num_mutex.try_lock();
        ++num1;
        std::cout<<id<<":"<<num1<<std::endl;
//      num_mutex.unlock();
        num1_mutex.unlock();
//    如果不加互斥锁 则输出无序
//    互斥锁的个数和共享资源的个数相等，
//    也就是说每一个共享资源都应该对应一个互斥锁对象。
//    互斥锁对象的个数和线程的个数没有关系。
    }
}
void test01(){
    std::thread t1(fun1,110);
    std::thread t2(fun1,120);
    t1.join();
    t2.join();
}

//2.try_lock()
//bool try_lock();
// 二者的区别在于try_lock()不会阻塞线程，lock()会阻塞线程：
// 如果互斥锁是未锁定状态，得到了互斥锁所有权并加锁成功，函数返回true
// 如果互斥锁是锁定状态，无法得到互斥锁所有权加锁失败，函数返回false
static int num2=0;
std::mutex mutex_num2;
void fun02(){
    for (int i = 0; i < 4; ++i) {
        if (mutex_num2.try_lock()){
            num2++;
            std::cout<<i<<std::endl;
            mutex_num2.unlock();
        } else{
            std::cout<<"mutex_num2_try_lock_error"<<std::endl;
        }
    }
}
void test02(){
    std::thread t1(fun02);
    std::thread t2(fun02);
    t1.join();
    t2.join();
}

//3.unlock()
//void unlock();
//只有拥有互斥锁所有权的线程也就是对互斥锁上锁的线程才能将其解锁，其它线程是没有权限。

//lock_guard<> lock();
//原型函数
// 类的定义，定义于头文件 <mutex>
//template< class Mutex >
//class lock_guard;
// 常用构造函数
//explicit lock_guard( mutex_type& m );
//作用：自动锁定/释放临界区资源（简化互斥锁）
void fun03(){
    for (int i = 0; i < 4; ++i) {
//        if (mutex_num2.try_lock()){
            //lock_guard自动管理临界资源（哨兵锁管理互斥锁）
            std::lock_guard<std::mutex> lock(mutex_num2);
            num2++;
            std::cout<<i<<std::endl;
//            mutex_num2.unlock();
//        } else{
//            std::cout<<"mutex_num2_try_lock_error"<<std::endl;
//        }
    }
}
void test03(){
    std::thread t1(fun03);
    std::thread t2(fun03);
    t1.join();
    t2.join();
}

//std::recursive_mutex
//递归互斥锁
//作用：允许同一线程多次获得互斥锁，可以用来解决同一线程需要多次获取互斥量时死锁的问题。
//尽量少用 效率比lock_guard低
//std::mutex num3_lock;
std::recursive_mutex num3_lock;
struct caculate_rec{
    caculate_rec(int num):m_num(num){
    }
    void div(int x){
    std::lock_guard<std::recursive_mutex> lock(num3_lock);
//    std::lock_guard<std::mutex> lock(num3_lock);
    m_num/=x;
    }
    void mul(int x){
        std::lock_guard<std::recursive_mutex> lock(num3_lock);
//    std::lock_guard<std::mutex> lock(num3_lock);
    m_num*=x;
    }
    void all(int x){
        std::lock_guard<std::recursive_mutex> lock(num3_lock);
//    std::lock_guard<std::mutex> lock(num3_lock);
    div(x);
    mul(x);
    //
    }
    int m_num;
};
void test04(){
    caculate_rec c1(10);
    c1.all(1);
    std::cout<<c1.m_num<<std::endl;
}

//time_mutex 超时独占互斥锁
//try_look_for()与try_lock_until()

int main() {
//    test01();
//    test02();
//test03();
test04();
}

