//
//  Created by ZYB on 2024/12/31.
//
//  语法：[capture](params) opt -> ret {body;};
//  其中capture是捕获列表，params是参数列表，opt是函数选项，ret是返回值类型，body是函数体。
//  捕获列表[]: 捕获一定范围内的变量
//  参数列表(): 和普通函数的参数列表一样，如果没有参数参数列表可以省略不写。
//  opt 选项， 不需要可以省略
//          mutable: 可以修改按值传递进来的拷贝（注意是能修改拷贝，而不是值本身）
//          exception: 指定函数抛出的异常，如抛出整数类型的异常，可以使用throw();
//  返回值类型：在C++11中，lambda表达式的返回值是通过返回值后置语法来定义的。
//  函数体：函数的实现，这部分不能省略，但函数体可以为空。

//  捕获列表
//  [] - 不捕捉任何变量
//  [&] - 捕获外部作用域中所有变量, 并作为引用在函数体内使用 (按引用捕获)
//  [=] - 捕获外部作用域中所有变量, 并作为副本在函数体内使用 (按值捕获)
//  拷贝的副本在匿名函数体内部是只读的
//  [=, &foo] - 按值捕获外部作用域中所有变量, 并按照引用捕获外部变量 foo
//  [bar] - 按值捕获 bar 变量, 同时不捕获其他变量
//  [&bar] - 按引用捕获 bar 变量, 同时不捕获其他变量
//  [this] - 捕获当前类中的this指针

#include "iostream"
#include <functional>
void test01() {
    int a, b;
//    auto a1 = [] { return a + b;};  //捕获失败
    auto a2 = [&] { return a + b; };
    auto a3 = [=] { return a + b; };
    auto a4 = [&a]{return a++;};
//    auto a5=[=]{return a++;};  //以值拷贝捕获（值拷贝捕获在匿名函数内部为只读）所以return a++失败
    auto a6=[&a,b]{return a+b;};
    auto a7=[=,&b]{return b++;}; //只有b可写
}
class demo{
public:
    int number=100;
    void output(int x,int y){
//        auto x1=[]{return x+y;}; //error
        auto x2=[&]{return x+y;};
        auto x3=[=]{return x+y;};
        auto x4=[this]{return number++;};
//        auto x5=[this]{return number+x+y;}; //error
        auto x6=[this,x,y]{return number+x+y;};
    }
};
void test02(){
//    在匿名函数内部，需要通过lambda表达式的捕获列表控制如何捕获外部变量，
//    以及访问哪些变量。默认状态下lambda表达式无法修改通过复制方式捕获外部变量，
//    如果希望修改这些外部变量，需要通过引用的方式进行捕获。
}
void test03(){
    //返回值
    auto a1=[](int a) ->int{
        return a++;
    };
    auto a2=[](int b){
        //根据return自动推导返回值类型
        return b++;
    };
    auto a3=[]() {
        //不能根据列表初始化方式自动推导
        return 1;
//      return {1,3}; //error
    };
}
void test04(){
int a=100;
//    auto b=[=](){return a++;}; //error:按值捕获为只读
      auto b=[=]() mutable {return a++;}; //使用mutable取消cosnt属性从而使按值捕获到的变量可读可写
}
void test05(){
    //因为lambda表达式在C++中会被看做是一个仿函数，
    //因此可以使用std::function和std::bind来存储和操作lambda表达式：
    std::function<int(int)> f1=[](int a){return a;};
    std::function<int(int)> f2=std::bind([](int a){return a;},std::placeholders::_1);

    //函数调用
    std::cout<<f1(100)<<std::endl;
    std::cout<<f1(250)<<std::endl;
}
void test06(){
    //对于没有捕获任何变量的lambda表达式，还可以转换成一个普通的函数指针：
    using func_ptr = int(*)(int);  //起别名
    func_ptr f=[](int a){
        return  a;
    };
    f(1314);
}
int main(){
//test05();
test06();
}
