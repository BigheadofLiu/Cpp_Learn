/*
 * C++ 11 标准发布之前，函数模板和类模板只能设定固定数量的模板参数。
 * C++11 标准对模板的功能进行了扩展，允许模板中包含任意数量的模板参数，这样的模板又称可变参数模板。
 *
 *
 *  使用 … 可变参数的过程中，需注意以下几点：
 *… 可变参数必须作为函数的最后一个参数，且一个函数最多只能拥有 1 个可变参数。
 *  可变参数的前面至少要有 1 个有名参数（例如上面例子中的 count 参数）；
 * 当可变参数中包含 char 类型的参数时，va_arg 宏要以 int 类型的方式读取；
 *当可变参数中包含 short 类型的参数时，va_arg 宏要以 double 类型的方式读取。
 * 将容纳多个参数的可变参数称为参数包
 */
#include "iostream"
//1.函数模板可变参数
template<class... T> //T为模板参数包
void wait_fun(T...args){ //为啥要用args 这里就为函数参数包
}
void fun1(){
    wait_fun(1,"wdnmd");
    wait_fun("hello",1.1,'c');  //可变参数传入函数参数包
}
//参数包解包：
//1.递归方式解包 看不懂啊
//2.非递归方式解包 也是看不懂

//递归方式(无形参，无函数体，作为递归出口)  //函数重载
void digui(){
}
template <class T_1,class... T_2>
void digui(T_1 a,T_2...b) {
    std::cout<<a<<std::endl;
    digui(b...);  //每次获取到一个参数，剩余的参数包参与递归
}
void fun2(){
    digui(1,"www.zuoyebang.cc");
}
//非递归方式
template <class T>
void display(T t){
    std::cout<<t<<std::endl;
}
template <class... A>
void vir_fun(A...B ){
//  int arr[]={(display(B),0)...};  //等价于以下
    int arr[]= { (display(1),0), (display("http://www.biancheng.net"),0), (display(2.34),0) };
}
void fun3(){
    vir_fun(1, "http://www.biancheng.net", 2.34);
    return ;
}

//2.类模板可变参数
//声明模板类demo(看不懂)
template<typename... Values> class demo;
//继承式递归的出口
template<> class demo<> {};
//以继承的方式解包
template<typename Head, typename... Tail>
class demo<Head, Tail...>
        : private demo<Tail...>
{
public:
    demo(Head v, Tail... vtail) : m_head(v), demo<Tail...>(vtail...) {
        dis_head();
    }
    void dis_head() { std::cout << m_head << std::endl; }
protected:
    Head m_head;
};
void fun4(){
    demo<int, float, std::string> t(1, 2.34, "http://www.biancheng.net");
    return;
}
int main(){
//fun2();
//fun3();
fun4();
}