#include "iostream"
using namespace std;
//this指针的使用
//this指针指向被调用的成员函数所述的对象
//this指针不需要定义 可以直接使用
//作用：1.成员函数形参和成员变量同名，用this来区分
     //2.类内非静态成员函数中返回对象本身 可以使用return *this（this是一个指针 *用于解指针）
class Person{
    public:
    int age;
    Person(int age){
        this->age=age;
    }
    void fun1(){
        cout<<age<<endl;
    }
    Person& Addage(Person &p){   //返回的是一个引用的形式才可以执行链式的累加算法
        this->age+=p.age;
        return *this;
    }
};
void fun1(){
    Person p1(18);  //没有使用this指针 输出为0  使用this后输出正确
    p1.fun1();
}

void fun2(){
    Person p2(20);
    Person p3(20);
    p2.Addage(p3).Addage(p3).Addage(p3).Addage(p3);  //链式法则 怎么实现？
    cout<<p2.age<<endl;
}

int main(){
// fun1();
fun2();
}
