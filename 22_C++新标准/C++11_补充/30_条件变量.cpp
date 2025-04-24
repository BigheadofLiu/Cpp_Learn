//
// Created by ZYB on 2025/3/14.
//
// condition_variable
// condition_variable_any

//线程同步之条件变量
//https://subingwen.cn/cpp/condition/

//condition_variable
//成员函数：线程等待（阻塞）函数、线程通知（唤醒）函数
//调用wait线程被阻塞
// ①
//void wait (unique_lock<mutex>& lck);
// ②
// template <class Predicate>
// void wait (unique_lock<mutex>& lck, Predicate pred);
// 函数①：调用该函数的线程直接被阻塞
// 函数②：该函数的第二个参数是一个判断条件，是一个返回值为布尔类型的函数

// 条件变量通常用于生产者和消费者模型
#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
#include<list>
#include<functional>
using namespace std;
class sync_quene{
private:
list<int> m_quene;
mutex m_mutex;
condition_variable 不空; //   我尼玛就要用中文  消费
condition_variable 不满;  //生产
int m_maxsize;
public:
sync_quene(int maxsize):m_maxsize(maxsize){}
bool is_full(){
    return (this->m_maxsize==m_quene.size());
}
int  now_size(){
    lock_guard<mutex> locker(m_mutex);
    return m_quene.size();
}
void list_put(const int& x){
    unique_lock<mutex> locker(m_mutex);
    while(m_quene.size()==m_maxsize){
        cout<<"当前队列已满，牛马们还tm生产！"<<endl;
        不满.wait(locker);  //阻塞生产
        }
        m_quene.push_back(x);
        cout<<x<<"被生产"<<endl;
        不空.notify_one(); //唤醒消费
}
int list_take(){
    unique_lock<mutex> locker(m_mutex);
    while(now_size()==0){
        cout<<"队列空，我通知牛马去生产！"<<endl;
        不空.wait(locker); //阻塞消费
    }
    int x=m_quene.front();
    m_quene.pop_front();
    不满.notify_one(); //唤醒生产   
    cout<<x<<"被消费"<<endl;
    return x;
    }   

};
int main(){
    sync_quene sq1(20);
    auto 牛马=bind(&sync_quene::list_put,&sq1,placeholders::_1);
    auto 老爷=bind(&sync_quene::list_take,&sq1);
    thread t1[3];
    thread t2[3];
    for(auto i=0;i<3;++i){
        t1[i]=thread(牛马,i+100);
        t2[i]=thread(老爷);
    }
    for(auto i=0;i<3;i++){
        t1[i].join();
        t2[i].join();
    }
    return 0;
}