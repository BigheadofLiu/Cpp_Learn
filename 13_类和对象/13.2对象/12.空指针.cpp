#include "iostream"
using namespace std;
//使用空指针调用成员函数
class Person{
    public:
    int age;
    void fun1(){
        cout<<"i m fun1"<<endl;

    }
    void fun2(){
        if (this==NULL)
        {
            return; //防止出现异常
        }           //this 判空
        cout<<this->age<<endl;
    }
};
void fun1(){
Person* p1=NULL;  //对象指针置空
p1->fun1();
p1->fun2();
}
int main(){
    fun1();
}