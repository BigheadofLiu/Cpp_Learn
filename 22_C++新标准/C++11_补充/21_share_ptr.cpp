//
// Created by ZYB on 2025/2/16.
//
//文章：https://subingwen.cn/cpp/shared_ptr/

#include "memory"
#include "iostream"
using namespace std;

//share_ptr的初始化
//1.通过构造函数初始化：std::share_ptr<T> share_ptr_name(堆内存)
void test01(){
    shared_ptr<int> sp1(new int(500));
    shared_ptr<char> sp2(new char[10]); //指向堆区内存
    shared_ptr<int> sp3; //木有指向堆区内存
    shared_ptr<int> sp4(nullptr); //指向空指针
    std::cout<<sp1.use_count()<<endl; //函数原型：long use_count() const noexcept;
    std::cout<<sp2.use_count()<<endl;
    std::cout<<sp3.use_count()<<endl;
    std::cout<<sp4.use_count()<<endl;
    //1 1 0 0
}
void test02(){
   /* 如果智能指针被初始化了一块有效内存，那么这块内存的引用计数+1，
    如果智能指针没有被初始化或者被初始化为nullptr空指针，引用计数不会+1。
    另外，不要使用一个原始指针初始化多个shared_ptr。*/
   int* p=new int(5);
   shared_ptr<int> sp5(p);
//   shared_ptr<int> sp6(p); //why there`s no error? yes there si error that no output
   cout<<sp5.use_count();
//   cout<<sp6.use_count();
}

//2.通过拷贝构造函数或移动构造函数初始化
void test03(){
    shared_ptr<int> sp1(new int(100));
    shared_ptr<int> sp2(sp1);
    auto sp3=sp1;
    

}
//如果使用拷贝的方式初始化共享智能指针对象，
//这两个对象会同时管理同一块堆内存，堆内存对应的引用计数也会增加；
//如果使用移动的方式初始智能指针对象，只是转让了内存的所有权，
//管理内存的对象并不会增加，因此内存的引用计数不会变化。

int main(){
//    test01();
test02();
}