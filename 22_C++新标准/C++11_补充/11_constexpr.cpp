//
// Created by ZYB on 2024/12/31.
//
#include "iostream"
#include "assert.h"
// C++11之前 const关键字表示： 只读 常量
// 变量只读并不等价于常量
// C++11中推出constexpr用于对const功能做分割：const表示只读 constexpr表示常量
// 这个关键字是用来修饰常量表达式的。所谓常量表达式，
// 指的就是由多个（≥1）常量（值不会改变）组成并且在编译过程中就得到计算结果的表达式。

// 常量表达式和非常量表达式的计算时机不同，
// 非常量表达式只能在程序运行阶段计算出结果，
// 但是常量表达式的计算往往发生在程序的编译阶段，
// 这可以极大提高程序的执行效率，<关键>

void test01(const int num1){
    const int num2=24;
//  num1++;             //error:num1只读
    int array_1[num1];  //为毛我成功了
    int array_2[num2];

    int a1=1314;
    int a2=520;
    const int& b=a1;
//    b=a2; //error &被修饰相当于常量指针常量
    a1=1111;
    std::cout<<sizeof(array_1)/sizeof(array_1[0])<<" ";
    std::cout<<sizeof(array_2)/sizeof(array_2[0])<<" ";
    std::cout<<b<<" ";
}

// 常量表达式函数：普通函数/类成员函数、构造函数、模板函数
// 1.普通函数
// (1)必须有返回值 并且返回值必须是常量表达式
// (2)使用之前必须先定义（声明没用0.0）
// (3)整个函数的函数体中，不能出现非常量表达式之外的语句（using 指令、typedef
//    语句以及 static_assert 断言、return语句除外）。

constexpr int test02(/*constexpr*/ int num1){ //Function parameter cannot be constexpr constexpr不能用于函数形式参数
//  constexpr int num2; //constexpr修饰的变量必须是常量表达式 不能为空值
    constexpr int num2=1;
    constexpr int num3=num2+2;

    const int num4=num3+1;
    return num4;
}

/*constexpr*/ class demo{ //constexpr无法修饰自定义类型
public:
    int  a;
    int  b;
};
void test03(){
    constexpr demo d1{1,2}; //success
    constexpr int id=d1.a;
    constexpr int num=d1.b;

/*  d1.b++; //error   常量实例化对象属性也为常量
    d1.a++; //error
*/
}

int main(){
    test01(10);  //constexpr variable 'num2' must be initialized by a constant expression
}

constexpr int test04(){
    //普通常量函数内部无法使用常规语句（using typedef static_assert return）
    constexpr int num1=10087459;
    constexpr int num2=171164251;
    for (int i=1;i<100;i++){
        //c++17之后可以出现for循环
//        std::cout<<num1<<" "<<num2<<std::endl;  // <<无法出现在普通常量函数
    }
    if(true){
        //if语句可以出现
    }
   /* while(true){
        //while语句不可以出现
    }*/
    using int_64=int;  //using可以出现
    typedef int int_32; //typedef可以使用
    static_assert(sizeof(int)==4);//static_assert可以使用
/*    assert(sizeof(int)==4); //为啥assert可以使用？*/
    return num1+num2;
}
class demo2{
public:
/*    constexpr int a; 类内成员属性不可以使用constexpr*/
      int a;
      int b;
      constexpr int/*auto*/ fun1(){ //害得是auto(使用auto类方法调用出错了）
          constexpr int ce1=100;
          return ce1;
      }
};
void test5(){
    //constexpr修饰类内成员函数
    demo2 d1;
    /*auto  ce1=d1.fun1();*/
    constexpr int ce1=d1.fun1();
}

template<class T1>
//模板使用constexpr有时会不生效
constexpr T1 display(T1 t1){
    return t1;
}
void test6(){
    //constexpr修饰模板函数
    demo2 d1{100,200};
    /*constexpr*/ demo2 d2= display(d1); //传入的d1为变量 模板函数中constexpr没有生效
    constexpr demo2 d3{111,222};
    constexpr demo2 d4= display(d3); //传入常量 识别成功
    constexpr int i1= display(100);
}

//constexpr修饰构造函数
class demo3{
public:
    constexpr demo3(const int id,const int score):a(id),b(score){
    }

    int a;
    int b;
};
void demo4(){
constexpr demo3 d1(10,20);
//d1.a++;
//d1.b++; 常量构造函数参数无法修改
std::cout<<d1.a<<" "<<d1.b<<std::endl;
}


