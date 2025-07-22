#include<iostream>
#include<atomic>
#include<thread>
#include<mutex>
#include<chrono>
#include<algorithm>
#include<functional>
using namespace std;
/*使用atomic替代mutex*/
class caculate{
    private:
    // int m_num{0};
    atomic_int m_num{0};
    // mutex m_mutex;

    public:
    void auto_add(){
    for(auto i=0;i<10;i++){
        // lock_guard<mutex> locker(mutex);
        m_num++;
        cout<<m_num<<" "<<this_thread::get_id()<<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    }
    void auto_dec(){
        for(auto i=0;i<10;i++){
            // lock_guard<mutex> locker(mutex);
            m_num--;
            cout<<m_num<<" "<<this_thread::get_id()<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
};
int main(){
    caculate c1;
    auto a1=bind(&caculate::auto_add,&c1);
    auto a2=bind(&caculate::auto_dec,&c1);
    thread t1(a1);
    thread t2(a2);
    t1.join();
    t2.join();
    return 0;
}