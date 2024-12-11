#include <iostream>
#include <typeinfo> //using typeid
#include <vector> //using vector
//using  namespace  std;
/*
 * auto关键字用来自动推导变量类型
 * 语法： auto name=value;
 * 
 */
void test1();
template<class T>
void test2(T){
}

void fun01() {
    //单独定义
    auto a = 1.1;
    auto b = "hello auto!";
    //连续定义多个
//  auto c=&a,d=&b; //error:多个auto变量声明推导 类型要相同(避免出现二义性)
    auto c = a, d = 9.9; //success
    std::cout << typeid(a).name() << std::endl;  //d
    std::cout << typeid(b).name() << std::endl;  //Pkc(point const char) const char* 常量指针型
    std::cout << typeid(c).name() << std::endl;  //d
    std::cout << typeid(d).name() << std::endl;  //d
//使用 auto 类型推导的变量必须马上初始化
//auto e; error
}
void fun02(){
    //auto高级用法(混合使用)
    auto f=0;
    auto g_1=&f;
    auto* g_2=&f;
    auto h_1=f;
    auto& h_2=f;

    std::cout<< typeid(g_1).name()<<std::endl;  //pi
    std::cout<< typeid(g_2).name()<<std::endl;  //pi
    std::cout<< typeid(h_1).name()<<std::endl;  //i
    std::cout<< typeid(h_2).name()<<std::endl;  //i
}
void fun03() {
    //auto与const配合使用
    int a = 0; //a为int
    const auto b = a;      //b为const int ,auto推导为int
    auto c = b;                //b为const int, auto推导为(const) int (const属性被抛弃)
    auto c_1 = &b;       //const int*(cosnt保留了下来)
    const auto &d = c;   //const int &
    const auto &d_1 = &c; //int *const &
    const auto d_2 = &c;   //int *const
    auto &e = d;          //cosnt int &

    std::cout << typeid(a).name() << std::endl;  //i
    std::cout << typeid(b).name() << std::endl;  //i
    std::cout << typeid(c).name() << std::endl;  //i
    std::cout << typeid(d).name() << std::endl;  //i
    std::cout << typeid(d_1).name() << std::endl; //PI
    std::cout << typeid(d_2).name() << std::endl; //PI
    std::cout << typeid(e).name() << std::endl;  //i

    //关于auto与const的保留
    //当类型为引用时(左值或右值),auto推导结果会包含const关键字
    //当类型为非引用时,auto推导结果将不包含const关键字
}
    void fun04(){
    //auto 的限制
    //1.定义变量时必须初始化
//    auto a; //Error:Declaration of variable 'a' with deduced type 'auto' requires an initializer

    //2.不能作为函数的形参
//    test(auto a){} //error:'auto' not allowed in function prototype
    //3.不能用于类的非静态成员变量
//    class A{
//    public:
//        auto  a_1=1; //error:'auto' not allowed in non-static class member
//
//    };

    //4.不能用于定义数组
//    auto a[3]={1,2,3}; //Cannot deduce actual type for variable 'a' with type 'auto[3]' from initializer list

    //5.不能用于模板参数
//        test2(auto a);  //Error:Expected '(' for function-style cast or type construction

    //auto主要用途
    //1.用于定义迭代器
    std::vector<int> v;
    v.assign(10,1);
    for(auto i=v.begin();i!=v.end();i++){
    }
    //2*.用于泛型编程
    //略(wdnmd神马是泛型编程)
    }

int main(){
//fun01();
//fun02();
//fun03();
//fun04();
}