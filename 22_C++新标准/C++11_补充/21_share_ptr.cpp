//
// Created by ZYB on 2025/2/16.
//
//文章：https://subingwen.cn/cpp/shared_ptr/

#include <cstring>
#include "memory"
#include "iostream"
#include "string"
using namespace std;

//一、share_ptr的初始化
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
//   shared_ptr<int> sp6(p); //编译无错误，运行无结果？两个共享智能指针，引用计数没有共享，各自析构时重复释放。
    shared_ptr<int> sp6(sp5); //正确做法，通过拷贝构造或移动构造，避免使用裸指针。
   cout<<sp5.use_count()<<endl;
   cout<<sp6.use_count();
}

//2.通过拷贝构造函数或移动构造函数初始化
void test03(){
    shared_ptr<int> s1(new int(100)); //默认构造
    shared_ptr<int> s2(s1); //拷贝构造
    auto s3=s1;//拷贝构造
    auto s4(std::move(s1));
    auto s5=std::move(s1);

    cout<<s1.use_count()<<endl;  //本来为1 所有权转移之后为0
    cout<<s2.use_count()<<endl; //
    cout<<s3.use_count()<<endl; //经过两轮拷贝构造 引用计数+2=3
    cout<<s4.use_count()<<endl; //s4获得s1所有权
    cout<<s5.use_count()<<endl; //s1引用计数为0 所以s5为0
//    cout<<sp1.use_count()<<endl;
    //0 3 3 3 0
    //如果使用拷贝的方式初始化共享智能指针对象，
    //这两个对象会同时管理同一块堆内存，堆内存对应的引用计数也会增加；
    //如果使用移动的方式初始智能指针对象，只是转让了内存的所有权，
    //管理内存的对象并不会增加，因此内存的引用计数不会变化。
}
//3.通过make_share初始化
//函数原型：
//template< class T, class... Args >
//shared_ptr<T> make_shared( Args&&... args );

//make_share函数的作用是返回一个share_ptr智能指针，并且会自动管理内存，
//make_share函数会根据传入的参数类型自动创建一个share_ptr智能指针，
//并且会自动管理传入的参数的内存，当share_ptr智能指针被释放时，会自动释放传入的参数的内存。
//make_share函数的参数可以是任何类型的对象，包括基本数据类型、自定义类型、数组等。
//make_share函数的返回值是一个share_ptr智能指针，可以像普通指针一样使用。
class test{
public:
    test(){
        cout<<"无参构造"<<endl;
    }
    test(int a){
        cout<<"int有参构造"<<endl;
    }
    test(string str){
        cout<<"string有参构造"<<str<<endl;
    }
    ~test(){
        cout<<"析构"<<endl;
    }
};
void test04(){
     std::shared_ptr<int> sp1= make_shared<int>(500);

     std::shared_ptr<test> sp2= make_shared<test>();

     std::shared_ptr<test> sp3= make_shared<test>(100);

     std::shared_ptr<test> sp4= make_shared<test>("wdnmd");

     cout<<sp1.use_count()<<endl;
     cout<<sp2.use_count()<<endl;
     cout<<sp3.use_count()<<endl;
     cout<<sp4.use_count()<<endl;
//    无参构造
//    int有参构造
//    string有参构造wdnmd
//    1
//    1
//    1
//    1
//    析构
//    析构
//    析构
}
//4.通过reset函数初始化
void test05(){
shared_ptr<int> sp1= make_shared<int>(500);
    auto sp2=sp1;
    auto sp3=sp1;
    auto sp4=sp1;
    cout<<sp1.use_count()<<endl;
    cout<<sp2.use_count()<<endl;
    cout<<sp3.use_count()<<endl;
    cout<<sp4.use_count()<<endl;
    //4 4 4 4
    sp4.reset();
    cout<<sp1.use_count()<<endl;
    cout<<sp2.use_count()<<endl;
    cout<<sp3.use_count()<<endl;
    cout<<sp4.use_count()<<endl;
    //3 3 3 0

    shared_ptr<int> sp5;
    decltype(sp5) sp6;
    sp5.reset(new int(500));
//    sp6.reset()
    cout<<sp5.use_count()<<endl;
    //1
//    对于一个未初始化的共享智能指针，
//    可以通过reset方法来初始化，
//    当智能指针中有值的时候，
//    调用reset会使引用计数减1。
}
//5.通过get方法获取共享指针地址
void test06(){
    int a=100;
    auto sp1= make_shared<int>(a);
    int* p1=sp1.get();
    cout<<p1<<endl; //0x1e6750
}
//二、share_ptr的删除
//1.指定删除器
void my_delete_ptr(int* p){
    //自定义释放方式，智能指针会自动进行调用
    p= nullptr;
    delete p;
    cout<<"指定内存已释放"<<endl;
}
void test07(){
//    auto sp1= make_shared<int>(250, my_delete_ptr);
    shared_ptr<int> sp2(new int(100), my_delete_ptr);
}
//2.默认删除器不支持数组对象，需要手动指定或使用default_delete<T>()
void test08(){
    shared_ptr<int> sp2(new int[100], my_delete_ptr);
    shared_ptr<int> sp3(new int[100], std::default_delete<int[]>()); //default指定模板参数
    shared_ptr<int> sp4(new int[100], [](int* p){delete []p;}); //lambda函数释放
    cout<<sp2.get()<<endl;
    cout<<sp3.get()<<endl;
}

int main() {
//    test01();
    test02();
//      test03();
//test04();
//test05();
//test06();
//test07();
//test08();
}
