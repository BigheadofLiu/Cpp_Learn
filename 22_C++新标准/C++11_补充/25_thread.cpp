//
// Created by ZYB on 2025/3/1.
//
// https://subingwen.cn/cpp/thread/
#include "iostream"
#include "thread"
using namespace  std;
//1.thread构造函数
//   ① 默认构造
//thread() noexcept;
//// ② 移动构造
//thread( thread&& other ) noexcept;
//// ③
//template< class Function, class... Args >
//explicit thread( Function&& f, Args&&... args );
//// ④禁用拷贝构造
//thread( const thread& ) = delete;
void fun1(int a,int b){};
void test01(){
    std::thread();
    std::thread t1;
//    std::thread t2(t1); //拷贝构造被禁用
    std::thread t3(thread&& t1);

    std::thread t4(std::move(t1));
    std::thread t5(const thread& t1);

}
//2.thread成员函数
//thread::get_id() 获取线程id
//函数原型std::thread::id get_id() const noexcept;
//应用程序启动之后默认只有一个线程，这个线程一般称之为主线程或父线程，
//通过线程类创建出的线程一般称之为子线程，每个被创建出的线程实例都对应一个线程ID，
//这个ID是唯一的，可以通过这个ID来区分和识别各个已经存在的线程实例，
//这个获取线程ID的函数叫做get_id()
void fun2(int a,string s){
    cout<<"我是线程:"<<a<<"我被调用了"<<s<<endl;
}
void fun3(){
    this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void test02(){
    std::thread t1(fun2,12,"wdnmd");
    cout<<"test02的线程id:"<<t1.get_id()<<endl;
}
//3.thread::join 用于阻塞当前线程
//函数原型：void join();
void test03(){

}
// 4.thread::detach();用于线程分离(在主线程退出之前，
// 它可以脱离主线程继续独立的运行，任务执行完毕之后，
// 这个子线程会自动释放自己占用的系统资源。）
// 函数原型：void detach()
void test04(){

}
//thread::joinable() 判断主线程和子线程是否处于连接状态
//函数原型:bool joinable() const noexcept;
void test05(){

}

//operator=
//// move (1)
//thread& operator= (thread&& other) noexcept;  支持移动构造
//// copy [deleted] (2)
//thread& operator= (const other&) = delete; 禁用拷贝构造
//thread不支持复制,只支持move
void test06(){
    thread t1(fun3);
    thread t2(std::move(t1));
//    t2= move(t1);
//    t1.join();
//    t2.join();
    cout<<t1.get_id()<<" "<<t2.get_id()<<endl;
}

//静态构造函数
//static unsigned hardware_concurrency() noexcept;
//用于获取当前计算机cpu核心数
void test07(){
    cout<<"cpu-core number:"<<std::thread::hardware_concurrency<<endl;
}
int main(){
/*//    test02();
    std::thread t1(fun2,12,"wdnmd");
    std::thread t2(fun2,111,"丁真珍珠");

    cout<<"主线程ID:"<<std::this_thread::get_id()<<endl;
    cout<<"t1的线程id:"<<t1.get_id()<<endl;
    cout<<"t2的线程id:"<<t2.get_id()<<endl;

    //thread::join() 使用join 阻塞当前线程 执行调用线程后返回 防止主线程结束后字线程还没结束运行
    t1.join();
    t2.join();
//    if(t1.joinable()){
//        cout<<"已连接"<<endl;
//    }
    return 0;*/

//joinable()
/*thread t1;
cout<<((t1.joinable())?"连接":"未连接")<< std::endl;

t1=thread(fun3);
cout<<((t1.joinable())?"连接":"未连接")<< std::endl;

t1.join();
cout<<((t1.joinable())?"连接":"未连接")<< std::endl;

thread t2(fun3);
//t2.join();
//cout<<((t2.joinable())?"连接":"未连接")<< std::endl;

t2.detach();
cout<<((t2.joinable())?"连接":"未连接")<< std::endl;

return  0;*/
/*  未连接:线程没有绑定运行函数
    连接:绑定函数之后处于连接状态
    未连接:join 阻塞主线程之后处于未连接
    未连接:detach 之后未连接
    */

//test06();
test07();
}

