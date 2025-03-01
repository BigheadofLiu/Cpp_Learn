//
// Created by ZYB on 2025/2/16.
//
#include "iostream"
#include "memory"
#include <functional>
using namespace std;
//std::unique_ptr是一个独占型的智能指针，
// 它不允许其他的智能指针共享其内部的指针，
// 可以通过它的构造函数初始化一个独占智能指针对象，
// 但是不允许通过赋值将一个unique_ptr赋值给另一个unique_ptr。
//1.unique_ptr的创建(初始化)
void test01(){
    std::unique_ptr<int> up1(new int(500));
//    auto up2=up1; //error:不允许赋值（共享）
//    auto up3(up1);//error
    auto up4(std::move((up1))); //success 支持转移所有权
    auto up5= move((up1)); //success
//    std::unique_ptr不允许复制，但是可以通过函数返回给其他的std::unique_ptr，
//    还可以通过std::move来转译给其他的std::unique_ptr，
//    这样原始指针的所有权就被转移了，这个原始指针还是被独占的。
}
//2.reset方法：可用于解除对原始内存的管理，也可用于初始化独占类指针
void test02(){
    std::unique_ptr<int> up1(new int(500));
    auto up2=std::move(up1);
    up1.reset();
    cout<<up1.get()<<endl;  //0
//    cout<<up2.get()<<endl;
    unique_ptr<int> up3;
    cout<<up3.get()<<endl;  //0
    up3.reset(new int(200)); //初始化独占智能指针
    up1.reset(new int(100));

    cout<<up3.get()<<endl;
    cout<<up1.get()<<endl;
}
//3.删除器
void test03(){
    std::shared_ptr<int> sp1(new int(100),[](int* p){delete p;});
    std::shared_ptr<int> sp2(new int[100],[](int* p){delete []p;});


//    std::unique_ptr<int,func_ptr> sp3(new int(100),[](int *p){delete p;});//error 需要手动指定删除类型
    using func_ptr=void(*)(int*); //这啥，完全看不懂
//    std::unique_ptr<int,func_ptr> sp3(new int(100),[](int *p){delete p;}); //success 在没有捕获任何变量的情况下正确
//    std::unique_ptr<int,func_ptr> sp3(new int(100),[&](int *p){delete p;}); //error 捕获外部变量则报错
//需要使用可调用对象包装器（神马玩意）
// function<void(int*)> 函数包装器（作为删除器）
    std::unique_ptr<int,function<void(int*)>> sp3(new int(100),[&](int *p){delete p;});
    //这尼玛什么意思
}
int main(){
//    test02();
    test03();
}