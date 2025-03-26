#include "iostream"
using namespace std;
//深拷贝与浅拷贝
//浅拷贝 问题：堆区内存的重复释放 用深拷贝来解决
//栈区  p2先释放 p1 p2指向对一个堆区的p_high p2释放后 p1再访问就会出现异常
//一个类的默认拷贝函数即为浅拷贝
class Person{
    public:
    Person(int age,int high){
        p_age=age;
        p_high=new int(high);  //开辟堆区空间  深拷贝
    }
    
    //默认拷贝函数  浅备份 有报错
    // Person(const Person &p){
    //     p_age=p.p_age;
    //     p_high=p.p_high;
    // }

    //自定义拷贝构造函数(深备份) 无报错
     Person(const Person &p){
        p_age=p.p_age;
        //p_high=p.p_high;
        p_high=new int(*(p.p_high)); //开辟另外一块堆区内存 深拷贝重点  只开辟一个成员属性的值即可 开辟对象的成员属性均会存储在堆区
        cout<<"我是自定义拷贝函数"<<endl;
    }
    int p_age;
    int* p_high;
    ~Person(){
    //在析构函数中对申请的堆区的内存进行释放
    if(p_high!=NULL){
    delete p_high;
    p_high=NULL; //指针置空 防止野指针出现
    }
    cout<<"析构函数调用"<<endl;
}
};
void fun1(){
Person p1(10,180);
Person p2(10,190);
Person p3(10,200);
p3=p2=p1;
cout<<p1.p_age<<" "<<*(p1.p_high)<<endl; 
cout<<p2.p_age<<" "<<*(p2.p_high)<<endl;  //*用于解地址
cout<<p2.p_age<<" "<<*(p3.p_high)<<endl;
};
int main(){
    fun1();
    // getchar();
    return 0;
} 
