//
// Created by ZYB on 2025/2/16.
//
#include "iostream"
#include "memory"
using namespace std;
//std::weak_ptr：弱引用的智能指针，它不共享指针，不能操作资源，是用来监视 shared_ptr 的。
//弱引用智能指针std::weak_ptr可以看做是shared_ptr的助手，
//它不管理shared_ptr内部的指针。std::weak_ptr没有重载操作符*和->，
//因为它不共享指针，不能操作资源，所以它的构造不会增加引用计数，
//析构也不会减少引用计数，它的主要作用就是作为一个旁观者监视shared_ptr中管理的资源是否存在。
//weak_ptr是模板类

//1.weak_ptr的构造函数
void test01(){
    // 默认构造函数
    //constexpr weak_ptr() noexcept;

    std::weak_ptr<int> wp1;
    //拷贝构造
    //weak_ptr (const weak_ptr& x) noexcept;
    //template <class U> weak_ptr (const weak_ptr<U>& x) noexcept;
    std::weak_ptr<int> wp2(wp1);
    std::weak_ptr<int> wp3=wp2;

    // 通过shared_ptr对象构造
    //template <class U> weak_ptr (const shared_ptr<U>& x) noexcept;
    std::shared_ptr<int> sp1= make_shared<int>(100);
//    std::weak_ptr<int> wp4=sp1;
    std::weak_ptr<int> wp4(sp1);
}

void test02(){
    std::shared_ptr<int> sp1(new int(100));
    std::weak_ptr<int> wp1;
    wp1=sp1;
    std::weak_ptr<int> wp2(sp1);
    cout<<sp1.use_count()<<endl;  //cout<<1 weak_ptr不增加引用计数
    cout<<wp1.use_count()<<" "<<wp2.use_count()<<endl;//1 1 weak_ptr.use_count用于获得当前观测资源的引用计数
    shared_ptr<int> sp2(sp1);
    cout<<wp1.use_count()<<" "<<wp2.use_count()<<endl;//2 2
//    weak_ptr只观测资源，不管理资源
//    sp1.reset();
//    cout<<sp1.use_count()<<endl; // 0
//    cout<<sp2.use_count()<<endl; // 1

//    cout<<wp1.use_count()<<endl; //1
//    cout<<wp2.use_count()<<endl; //1
//    sp2.reset();

    wp1.reset();
    wp2.reset();
//    cout<<sp1.use_count()<<endl; // 2
//    cout<<sp2.use_count()<<endl; // 2
//    cout<<wp1.use_count()<<endl; //0
//    cout<<wp2.use_count()<<endl; //0
    if (wp2.expired()){ //所观测资源被释放才返回true
        cout<<"资源已释放"<<endl;
    }else{
        cout<<"资源未释放"<<endl;
    }
}
void test03(){
//    std::weak_ptr.lock() 用于返回该weak_ptr所观测资源对象的共享智能指针
std::shared_ptr<int> sp1,sp2;
weak_ptr<int> wp1,wp2;
sp1= make_shared<int>(100);
cout<<sp1.use_count()<<endl; // 1
wp1=sp1;
cout<<wp1.use_count()<<endl;// 1
sp2=wp1.lock(); //相当于sp2=sp1?
cout<<sp1.use_count()<<" "<<sp2.use_count()<<endl;//2 2
//cout<<wp1.use_count()<<" "<<wp2.use_count()<<endl; //2 0
sp1.reset();
cout<<sp1.use_count()<<" "<<sp2.use_count()<<endl;//0 1
cout<<wp1.use_count()<<endl; // 1

//sp1=wp1.lock();
cout<</**sp1*/" "<<*sp2<<endl; //100 100
}
void test04(){
//    weak_ptr.reset() 清空对象，使其不监测任何资源
}
void test05(){
    //返回管理this指针的share_ptr
    class Test{
    public:
        shared_ptr<Test> get_this_ptr(){
            return shared_ptr<Test>(this);
        }
        ~Test(){
            cout<<"class has destroyed"<<endl;
        }
    };
    shared_ptr<Test> sp1(new Test);   /*Test sp1;*/
    cout<<sp1.use_count()<<endl; //1
    shared_ptr<Test> sp2=sp1->get_this_ptr();
    cout<<sp2.use_count()<<endl; //1

//    class has destroyed
//    class has destroyed
}
void test06(){
    //通过模板类解决重复销毁的问题
//    C++11中为我们提供了一个模板类叫做std::enable_shared_from_this<T>，
//    这个类中有一个方法叫做shared_from_this()，
//    通过这个方法可以返回一个共享智能指针，
//    在函数的内部就是使用weak_ptr来监测this对象，
//    并通过调用weak_ptr的lock()方法返回一个shared_ptr对象。
    class Test:public std::enable_shared_from_this<Test>{
    public:
        shared_ptr<Test> get_this_ptr(){
            return shared_from_this();
        }
        ~Test(){
            cout<<"class has destroyed"<<endl;
        }
    };
    shared_ptr<Test> sp1(new Test);
    cout<<sp1.use_count()<<endl;
    shared_ptr<Test> sp2=sp1->get_this_ptr();
//    cout<<sp1.use_count()<<endl;
    cout<<sp2.use_count()<<endl;
    //class has destroyed 对象只销毁一次
}

void test07(){
    //使用weak_ptr避免循环调用
    struct Pa;
    struct Pb;
    struct Pa{
//        shared_ptr<Pb> bptr;
        weak_ptr<Pb> bptr;
        ~Pa(){
           cout<< "class<Pa> is destroyed"<<endl;
        }
    };
    struct Pb{
        shared_ptr<Pa> aptr;
        ~Pb(){
            cout<< "class<Pb> is destroyed"<<endl;
        }
    };
    shared_ptr<Pa> S_Pa(new Pa);
    shared_ptr<Pb> S_Pb(new Pb);
    cout<<S_Pa.use_count()<<" "<<S_Pb.use_count()<<endl;// 1 1
//    class<Pb> is destroyed
//    class<Pa> is destroyed
    S_Pa->bptr=S_Pb;
    S_Pb->aptr=S_Pa;
    cout<<S_Pa.use_count()<<" "<<S_Pb.use_count()<<endl; //2 2
    //循环调用 导致share_ptr指针无法归零 无法调用析构函数
    //解决方法 share_ptr->weak_ptr
//    cout<<S_Pa.use_count()<<" "<<S_Pb.use_count()<<endl;
//    2 1
//    class<Pb> is destroyed
//    class<Pa> is destroyed
    }
int main(){
//    test01();
//    test02();
//test03();
//test05();
//test06();
test07();
}
