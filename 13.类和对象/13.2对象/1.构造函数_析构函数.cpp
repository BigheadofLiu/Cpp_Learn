#include<iostream>
using namespace std;
//对象的初始化与回收
//初始化：构造函数 语法 类名（）{} 作用：创建对象时为对象属性赋予初值
//回收：析构函数  语法 ~类名（）{} 作用：对象销毁前自动调用，执行清理的操作
//构造函数 析构函数由编译器自动调用，完成对象的初始化与清理操作
//如果类内不提供 编译器会提供构造函数与析构函数的空实现
class student{
    /*构造函数 没有返回值 不用写void
              可以有参数 可以发生重载
              构造函数被自动调用 且只调用一次
              可以定义类内的的属性初始值
              */
    public:
    student(){
        age=11;
        name="张三";
        gread=8;
        cout<<"我是类内的构造函数，我被自动调用了"<<endl;
    }
    
/*析构函数不能含有参数 不能发生重载*/
    ~student(){
        cout<<"我是类内的析构函数，我被自动调用了"<<endl;
    }

    // private:
    int age;
    string name;
    int gread;
    
};
void func1(){
    //函数调用 存在栈区 执行完毕即回收
    student stu2;
}

int main(){
    student stu1;
    cout<<stu1.name<<endl;  //构造函数初始化类内属性
    // func1();
    system("pause");
    /*主函数区在 全局区 程序结束之后才会调用析构函数*/
}
