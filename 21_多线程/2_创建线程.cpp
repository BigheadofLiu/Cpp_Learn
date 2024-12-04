#include<iostream>
#include<thread>
#include<string>
/*
 * join() 方法会阻塞主线程（等待调用线程结束后继续主线程）
 * joinable() 检查线程是否可join返回值为bool类型（默认构造函数创建的进行的进程不可join）
 * detach() 线程与主线程分离
 *
 */
void thread_1(){
    std::cout<<"i m thread 1"<<std::endl;

}
void thread_2(){
    std::cout<<"i m thread 2"<<std::endl;
}
void thread_3(std::string msg){
    for (int i = 0; i < 1000; i++) {
        std::cout<<msg<<std::endl;
    }
}
void test1(){
//    std::thread t1(thread_1);
//    std::thread t2(thread_2);
      std::thread t3(thread_3,"hello thread!");
//    t1.join();
//    t2.join();
      if(t3.joinable()){
//        t3.detach();
          t3.join();
      }
    system("pause >nul");
    return;

}
int main(){
    test1();
}