/*
 * 从语法上讲，noexcept 修饰符有两种形式：
简单地在函数声明后加上 noexcept 关键字
可以接受一个常量表达式作为参数，如下所示∶
double divisionMethod(int a, int b) noexcept(常量表达式);
常量表达式的结果会被转换成一个bool类型的值：
值为 true，表示函数不会抛出异常
值为 false，表示有可能抛出异常这里
不带常量表达式的noexcept相当于声明了noexcept（true），即不会抛出异常。
 */
#include "iostream"
auto test01() noexcept(false){
    throw 1;
}
auto test02() noexcept(true){
    throw 'e';
}
auto test03() throw(){
    throw 1.1;
}

int main(){
    try{
        test01();
        test02();
        test03();
    }catch(int){
        std::cout<<"int exception"<<std::endl;
    }catch(char*){
        std::cout<<"char exception"<<std::endl;
    }catch(float){
        std::cout<<"float exception"<<std::endl;
    }
    //只捕获到int异常
}