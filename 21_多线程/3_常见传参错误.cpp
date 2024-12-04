#include<iostream>
#include<thread>
#include<string>
#include<memory>
/*
 * 常见的多线程传参错误有一下几类：
 * 1.传递临时变量
 * 2.所传递的指针或引用指向局部变量(局部变量在线程开始前被释放)
 * 3.传递指针或引用指向已释放的内存（原因：堆区自动释放）
 * 4.类成员函数作为入口函数，类对象被提前释放(使用智能指针解决)
 * 5.入口函数为类的私有成员函数（使用友员解决）
 * */

static int b=10;
//std::thread th4;
class A{
public:
    void foo(){
        std::cout<<"hello thread"<<std::endl;
    }
};
class B{
private:
    friend void test05();
    void foo(){
        std::cout<<"hello thread"<<std::endl;
    }
};

void count_test1(int& a){ //传递参数为引用类型  引用的本质是指针常量int* const a
    a+=1;
    std::cout<<a<<std::endl;
}
void count_test2(int* a){ //传递参数为引用类型
//    a+=1;
//    *a=*a+1;
    std::cout<<*a<<std::endl;
}

void test01(){
    //1.传递临时变量
    int a=1;  //存储在临时变量
//    std::thread th1(count_test,1);
    std::thread th1(count_test1,std::ref(a));  //ref()把变量转为引用形式
    th1.join();
}

void test02(){
    //2.1传递空指针(解决方法：使用智能指针)
//    int* ptr=new int(1);
//    std::thread th2(count_test2,ptr); //error:cout结果为0 为什么不对呢？ 原因：ptr被提前释放
//    delete ptr;
//    th2.join();

    //2.2 传递局部变量引用
    int a=1;
    std::thread th3(count_test2,&a); //error
    std::thread th4(count_test2,&b); //success
    th3.join();
    th4.join();
    return;
}

void test03() {
    //
    A a;   //a有可能被提前释放
    std::thread th5(&A::foo, &a); //多线程调用类内成员函数 thread(&class::class_funtion,&obj)  //需要使用具体对象绑定类内成员函数
    th5.join();
}
void test04(){
    std::shared_ptr<A> a=std::make_shared<A>(); //创建智能指针 防止a被提前释放
    std::thread th6(&A::foo, a);
    th6.join();
}
void test05(){
    //入口地址为类内私有成员函数
    std::shared_ptr<B> b=std::make_shared<B>(); //创建智能指针 防止b被提前释放
    std::thread th6(&B::foo, b);  //
    th6.join();


}
int main(){
//     test01();
//     test02();
//     test03();
//       test04();
test05();
       return 0;
}
