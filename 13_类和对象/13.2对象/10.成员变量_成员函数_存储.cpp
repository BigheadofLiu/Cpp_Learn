#include "iostream"
using namespace std;
//成员变量和成员函数分开存储
class Person{
    public:
    int p_age; //sizeof(int)=4
    string p_name; //sizeof(string)=36

    static int p_id;  //静态成员属性不占用类内空间
    
    void fun1(){
        cout<<"我是类内成员方法"<<endl;
        
    }

    static void fun2(){
        cout<<"我是类内静态方法"<<endl;
        
    }


};

int main(){
    Person p;
    Person p1;
    cout<<sizeof(p)<<endl;  // 1.空白的对象默认大小为1 占用一个字节的空间 用于与其他空对象区分
                            // 2.非空对象的大小为属性值占用的空间（除静态属性）
                            // 3.静态成员函数与普通成员函数都不占用类的空间
    cout<<&p<<endl;  // 空对象地址
    cout<<&p1<<endl;  // 空对象地址
  
    // p.fun1(); 

}