#include<iostream>
#include<exception>
using namespace std;

/*
exception	所有标准异常类的父类
bad_alloc	当operator new and operator new[]，请求分配内存失败时
bad_exception	这是个特殊的异常，如果函数的异常抛出列表里声明了badexception异常，当函数内部抛出了异常抛出列表中没有的异常，这时调用的unexpected函数中抛出异常，不论什么类型，都会被替换成为badexception类型。
bad_typeid	使用typeid操作符，操作一个NULL指针，而该指针是带有虚函数的类，这时抛出这个异常。
bad_cast	使用dynamic_cast转换引用失败的时候。
ios_base::failure	io操作过程出现错误。
logic_error	逻辑错误，可以在运行前检测的错误。
runtime_error	运行时错误，仅在运行时才能检测的错误

logic_error的子类：
子类	                描述
std::invalid_argument	表示传递给函数的参数无效。
std::domain_error	表示一个函数或方法在一个无效的数学域（domain）上被调用。
std::length_error	表示一个操作尝试超出有效范围的长度。
std::out_of_range	表示一个索引或下标超出有效范围。
std::overflow_error	表示一个算术运算结果超出了所能表示的最大值。
std::underflow_error	表示一个算术运算结果超出了所能表示的最小值。

runtime_error的子类：

子类	            描述
std::runtime_error	表示一般的运行时错误。
std::range_error	表示一个值超出了有效范围。
std::overflow_error	表示一个算术运算结果超出了所能表示的最大值。
std::underflow_error	表示一个算术运算结果超出了所能表示的最小值。
std::logic_error	表示逻辑错误。通常不被直接使用作为子类，但可以用于表示未被其他子类覆盖的运行时错误。
std::bad_alloc	表示内存分配失败。
std::bad_cast	表示类型转换失败。
std::bad_typeid	表示typeid运算符在多态类型中失败。
std::bad_exception	表示在异常处理过程中发生了无法处理的异常。

*/
void test01(){
    throw std::out_of_range("我越界了");
}
int main(){
    try
    {
        test01();
    }
    catch(std::exception& e)
    {
        cout<<e.what()<<endl;
    }

}
