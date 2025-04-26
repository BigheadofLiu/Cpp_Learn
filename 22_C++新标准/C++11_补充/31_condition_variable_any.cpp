//  condition_variable_any
//  可以配合使用：mutex，timed_mutex,recursive_mutex,recursive_timed_mutex
//  成员函数：wait(),wait_for(),wait_until(),均可以接收一个或两个参数
//  notify_one()
//  notify_all()
//  以下改自condition_variable

#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
#include<list>
#include<functional>
using namespace std;
//---------------------------------
class sync_quene{
private:
list<int> m_quene;
mutex m_mutex;
condition_variable_any not_empty; //   我尼玛就要用中文  消费
condition_variable_any not_full;  //生产
int m_maxsize;
public:
sync_quene(int maxsize):m_maxsize(maxsize){}
bool is_full(){
    lock_guard<mutex> locker(m_mutex);
    return (this->m_maxsize==m_quene.size());
}
bool is_empty(){
    lock_guard<mutex> locker(m_mutex);
    return m_quene.empty();
}
int  now_size(){
    lock_guard<mutex> locker(m_mutex);
    return m_quene.size();
}
void list_put(const int& x){
    // unique_lock<mutex> locker(m_mutex);
        lock_guard<mutex> locker(m_mutex);
   /*  while(m_quene.size()==m_maxsize){
        cout<<"当前队列已满，niuma们还tm生产！"<<endl;
        not_full.wait(locker);  //阻塞生产
        } */
       //wait带两个参数 第二个条件（false阻塞，true继续执行）代替循环结构
        not_full.wait(m_mutex,[this](){
            return m_quene.size()!=m_maxsize; //不满
        });
        m_quene.push_back(x);
        cout<<x<<"被生产"<<endl;
        not_empty.notify_one(); //唤醒消费
}
int list_take(){
    // unique_lock<mutex> locker(m_mutex);
    lock_guard<mutex> locker(m_mutex);
   /*  while(m_quene.empty()){
        cout<<"队列空，我通知niuma去生产！"<<endl;
        not_empty.wait(locker); //阻塞消费
    } */
    not_empty.wait(m_mutex,[this](){
        return !m_quene.empty(); //不空 empty true为空 false非空
    });
    int x=m_quene.front();
    m_quene.pop_front();
    cout<<x<<"被消费"<<endl;
    not_full.notify_one(); //唤醒生产   
    return x;
    }   

};
int main(){
    sync_quene sq1(20);
    auto niuma=bind(&sync_quene::list_put,&sq1,placeholders::_1);
    auto laoye=bind(&sync_quene::list_take,&sq1);
    thread t1[10]; //牛马线程池
    thread t2[10]; //老爷线程池   //妈的10个老爷的消费能力太强了
    for(auto i=0;i<10;++i){
        t1[i]=thread(niuma,i+100);
        t2[i]=thread(laoye);
    }
    for(auto i=0;i<10;i++){
        t1[i].join();
        t2[i].join();
    }
    return 0;
}