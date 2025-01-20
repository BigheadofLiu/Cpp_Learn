//
// Created by ZYB on 2025/1/8.
//
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
int&& value_1=520;
//int& value_2=520; //error:Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
//引用无法接收右值
using namespace std;
class A{
public:
    A(){
        cout<<"i'm tom!"<<endl;
    }
    A(const A& a){
        cout<<"i'm jerry"<<endl;
    }
};
A get_obj(){
    return A();
}
int main(){


}