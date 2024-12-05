#include<iostream>
#include<thread>
#include<string>
#include<memory>  //智能指针头文件
#include <mutex>  //互斥量头文件
/*
 *
std::lock_guard 是 C++ 标准库中的一种互斥量封装类，用于保护共享数据，防止多个线程同时访问同一资源而导致的数据竞争问题。
std::lock_guard 的特点如下:
当构造函数被调用时，该互斥量会被自动锁定。
当析构函数被调用时，该互斥量会被自动解锁。
std::lock_guard 对象不能复制或移动，因此它只能在局部作用域中使用。

std::unique_lock 是 C++ 标准库中提供的一个互斥量封装类，用于在多线程程序中对互斥量进行加锁和解锁操作。它的主要特点是可以对互斥量进行更加灵活的管理，包括延迟加锁、条件变量、超时等。
std::unique_lock 提供了以下几个成员函数：
lock()：尝试对互斥量进行加锁操作，如果当前互斥量已经被其他线程持有，则当前线程会被阻塞，直到互斥量被成功加锁。
try_lock()：尝试对互斥量进行加锁操作，如果当前互斥量已经被其他线程持有，则函数立即返回 false，否则返回 true。
try_lock_for(const std::chrono::duration<Rep, Period>& rel_time)：尝试对互斥量进行加锁操作，如果当前互斥量已经被其他线程持有，则当前线程会被阻塞，直到互斥量被成功加锁，或者超过了指定的时间。
try_lock_until(const std::chrono::time_point<Clock, Duration>& abs_time)：尝试对互斥量进行加锁操作，如果当前互斥量已经被其他线程持有，则当前线程会被阻塞，直到互斥量被成功加锁，或者超过了指定的时间点。
unlock()：对互斥量进行解锁操作。
其他默认构造函数
unique_lock() noexcept = default：默认构造函数，创建一个未关联任何互斥量的 std::unique_lock 对象。
explicit unique_lock(mutex_type& m)：构造函数，使用给定的互斥量 m 进行初始化，并对该互斥量进行加锁操作。
unique_lock(mutex_type& m, defer_lock_t) noexcept：构造函数，使用给定的互斥量 m 进行初始化，但不对该互斥量进行加锁操作。
unique_lock(mutex_type& m, try_to_lock_t) noexcept：构造函数，使用给定的互斥量 m 进行初始化，并尝试对该互斥量进行加锁操作。如果加锁失败，则创建的 std::unique_lock 对象不与任何互斥量关联。
unique_lock(mutex_type& m, adopt_lock_t) noexcept：构造函数，使用给定的互斥量 m 进行初始化，并假设该互斥量已经被当前线程成功加锁。
 */
int count=0;
std::mutex m1;
void auto_add(){
    for(int i=0;i<100000;i++){
//        m1.lock(); //添加互斥锁
//        count++;
//        m1.unlock();

//使用lock_guard
//std::lock_guard<std::mutex> lg(m1);  //创建一个mutex类型的lock_guard容器lg存储m1(自动管理m1的生命周期)

//使用unique_lock
std::unique_lock<std::mutex> ul(m1/*,std::defer_lock*/); //添加defer_lock调用不自动上锁构造函数
//m1.lock();
//std::this_thread::sleep_for(std::chrono::seconds(5));  //等待5s
count++;
//m1.unlock();
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
