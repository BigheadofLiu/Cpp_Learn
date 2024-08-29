#include<iostream>  
using namespace std;
/*
多态 1.静态多态 2.动态多态
1.静态多态：函数重载、运算符重载、函数名复用 | 函数地址早绑定、编译阶段确定函数地址。
2、动态多态：派生类、虚函数 | 函数地址晚绑定、运行阶段确定函数地址。
3、动态多态需要满足的条件：（1）有继承关系
                        （2）子类（重写)父类虚函数  重写：函数名相同、函数参数也相同       
                    应用：（1）父类的指针或者引用 指向子类对象时使用
                         （2）略                  
*/

class animal{
    public:
    void speak(){
        cout<<"动物在说话"<<endl;       
    }

};

class cat:public animal{
    public:
    void speak(){
        cout<<"cat在说话"<<endl;
    }
};

void speak(animal &a1){
a1.speak();
}

void test(){
    cat c1;
    speak(c1); //out为动物在说话，为什么不是cat在说话？ 用virtual绑定speak之后 地址晚绑定 成功输出动物在说话
}

int main(){
    test();
}

/*
带virtual
##virtual animal
class animal    size(4):
        +---
 0      | {vfptr} //vfptr 虚拟指针表
        +---

animal::$vftable@:  //虚表
        | &animal_meta
        |  0
 0      | &animal::speak  //虚方法

animal::speak this adjustor: 0

##virtual cat
class cat       size(4):
        +---
 0      | +--- (base class animal)
 0      | | {vfptr}
        | +---
        +---

cat::$vftable@:
        | &cat_meta
        |  0
 0      | &cat::speak  //虚方法重写

 不带virtual
class animal    size(1):
        +---
        +---

class cat       size(1):
        +---
 0      | +--- (base class animal)
        | +---
        +---   没有重写speak方法，也没有使用虚函数指针s
*/
