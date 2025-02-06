//
//  Created by ZYB on 2025/1/8.
//  转自：https://subingwen.cn/cpp/rvalue-reference/#3-%E7%9A%84%E7%89%B9%E6%80%A7
//  C++11 增加了一个新的类型，称为右值引用（ R-value reference），标记为 &&。在介绍右值引用类型之前先要了解什么是左值和右值：
//  lvalue 是loactor value的缩写，rvalue 是 read value的缩写
//  左值是指存储在内存中、有明确存储地址（可取地址）的数据；
//  右值是指可以提供数据值的数据（不可取地址）；
//  通过描述可以看出，区分左值与右值的便捷方法是：可以对表达式取地址（&）就是左值，否则为右值 。所有有名字的变量或对象都是左值，而右值是匿名的。

//  C++11 中右值可以分为两种：一个是将亡值（ xvalue, expiring value），另一个则是纯右值（ prvalue, PureRvalue）：
//  纯右值：非引用返回的临时变量、运算表达式产生的临时变量、原始字面量和 lambda 表达式等
//  将亡值：与右值引用相关的表达式，比如，T&&类型函数的返回值、 std::move 的返回值等。

//  无论声明左值引用还是右值引用都必须立即进行初始化，
//  因为引用类型本身并不拥有所绑定对象的内存，只是该对象的一个别名。
//  通过右值引用的声明，该右值又“重获新生”，其生命周期与右值引用类型变量的生命周期一样，
//  只要该变量还活着，该右值临时量将会一直存活下去。
#include <iostream>

//int& value_2=520; //error:Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
//引用无法接收右值
using namespace std;

int&& value_1=520;
class A{
public:
    A(){
        cout<<"构造函数：i'm tom!"<<endl;
    }
    A(const A& a){
        cout<<"拷贝构造：i'm jerry"<<endl;
    }
};
A get_obj_1(){
    A a1;
//    return a1;
    return A();
//    return A(a1);
}
void test01(){
//    int&& a=100;
//    a=200;
int a1;
//int&& a2=a1; //error a1为左值
//A& a3=get_obj(); //error get_obj()返回值为右值（将亡值）（无内存地址 无法用引用接收）
A&& a4=get_obj_1(); //发生深拷贝
//const A& a5=get_obj_1();  //可以用常量引用接收右值
}
// 性能优化
/* 在C++中在进行对象赋值操作的时候，
 * 很多情况下会发生对象之间的深拷贝，
 * 如果堆内存很大，这个拷贝的代价也就非常大，
 * 在某些情况下，如果想要避免对象的深拷贝，
 * 就可以使用右值引用进行性能的优化。
 * */
class B{
public:
    B():num(new int(100)){
        cout<<"construct:i`m your dad"<<endl;
    }
    B(const B& b):num(new int(*b.num)){
        cout<<"copy construct:i`m your father"<<endl;
    }
    ~B(){
        delete num;
    }
    int *num;
};
B get_obj_2(){
    B b;
//    return B();
    return  b;
}
void test02(){
    B b=get_obj_2(); //这里为什么没有调用拷贝构造函数？：deepseek：编译器应用了RVO优化？
    cout<<"b.num:"<<*b.num<<endl;

    /*右值引用具有移动语义，移动语义可以将资源（堆、
    系统对象等）通过浅拷贝从一个对象转移到另一个对
    象这样就能减少不必要的临时对象的创建、拷贝以及
    销毁，可以大幅提高C++应用程序的性能。
     */
}

/*右值引用具有移动语义，移动语义可以将资源（堆、系统对象等）通过
浅拷贝从一个对象转移到另一个对象这样就能减少不必要的临时对象的
创建、拷贝以及销毁，可以大幅提高C++应用程序的性能。*/

class C{
public:
    C():num(new int(100)){
        cout<<"construct:i`m your dad"<<endl;
    }
    C(const B& c):num(new int(*c.num)){  //(深复制）
        cout<<"copy construct:i`m your father"<<endl;
    }
    C(C&& c):num(c.num){ //移动构造函数（浅复制）
    c.num= nullptr;
    cout<<"move construct:i`m your dad!"<<endl;
    }
    ~C(){
        delete num;
        cout<<"destruct"<<endl;
    }
    int *num;
};
C get_obj_3(){
    C c;
//    return  c;
    return std::move(c); //显式地告诉编译器将c视为右值 从而避免rvo
}
void test03(){
  C&& c=get_obj_3();  //为什么这里没有发生移动构造？
  cout<<"c.num:"<<*c.num<<std::endl;
}

/*template <class T1>
void fun_1(T1&& param);

template<class T2>
void fun_2(const T2&& param);

void test04(){
    fun_1(10); //传入右值
    int x=10;
    fun_1(x); //传入左值
    fun_2(10); //传入右值
//    fun_2(x); //传入左值:error
}*/

/*
 * &&的特性
 * 如果是模板参数需要指定为T&&，如果是自动类型推导需要指定为auto &&，
 * 在这两种场景下 &&被称作未定的引用类型。另外还有一点需要额外注意const T&&表示一个右值引用，不是未定引用类型。
 * 未定型引用：可推导为右值&左值引用
 * 通过右值推导 T&& 或者 auto&& 得到的是一个右值引用类型
 * 通过非右值（右值引用、左值、左值引用、常量右值引用、常量左值引用）
 * 推导 T&& 或者 auto&& 得到的是一个左值引用类型
 *
 */
void test05(){
    int&& x1=10; //右值引用
    auto &&a1=x1; //右值引用推导为左值引用
    auto &&a2=10;  //右值推导为右值引用
    int x2=10;
    auto&& a3=x2; //左值推导为左值引用
}

void print_vaule(int& a){
cout<<"l vaule"<<endl;
}
void print_vaule(int&& a){
cout<<"r vaule"<<endl;
}
/*void print_vaule(int a){
cout<<
}*/
void get_vaule(int&& a){
    print_vaule(a);
}
void test06(){
    int a=10;
    int&& b=20;
    print_vaule(a);
    print_vaule(b);
    print_vaule(1314);
    get_vaule(100);
}
/*
 * 左值和右值是独立于他们的类型的，右值引用类型可能是左值也可能是右值。
   编译器会将已命名的右值引用视为左值，将未命名的右值引用视为右值。
   auto&&或者函数参数类型自动推导的T&&是一个未定的引用类型，它可能是左值引用也可
   能是右值引用类型，这取决于初始化的值类型（上面有例子）。
   通过右值推导 T&& 或者 auto&& 得到的是一个右值引用类型，其余都是左值引用类型。
   */
int main(){
//    test01();
//    构造函数：i'm tom!
//    构造函数：i'm tom!

//test02();
//    construct:i`m your dad
//    b.num:100

//    test03();
//test06();
/*  l vaule
    l vaule
    r vaule
    l vaule
*/
    return 0;
}