#include<iostream>  
using namespace std;
//赋值运算符重载
//c++初始化类内四个函数
/*
1.默认构造函数（无参、无返回值）
2.默认析构函数（无参、无返回值）
3、默认拷贝构造函数（对属性值进行拷贝、浅拷贝）
4、默认运算符 operator=（对属性值进行拷贝）
*/
class Person{
    public:
    friend void  fun1();
    Person(string name,int age){
        this->name=new string(name);  //解决浅拷贝带来的问题
        this->age=age;
    }

    //默认的类内赋值操作 提供的是浅拷贝
    // Person& operator=(Person p1){      
    // this->age=p1.age;
    // this->name=p1.name;
    // return *this;
    // }

    //operator=重载
    Person& operator=(Person p1){      
    // this->age=p1.age;
    // this->name=p1.name;
    // return *this;
    //1.首先释放类内已经占用的堆区内存
    if (name!=NULL)
    {
        delete name;
        name=NULL;
    }
    this->name=new string(*p1.name);  //开辟新的堆区内存（深拷贝）
    this->age=p1.age;
    return *this;
    }

    ~Person(){
        if (this->name!=NULL)
        {
            delete name;
            name=NULL;
        }
        
    }
    private:
    string *name;
    int age;

};

void  fun1(){
    Person p1("坤坤",20);
    Person p2("1",0);
    Person p3("1",0);
    p3=p2=p1;  //支持链式赋值法

    // cout<<p2.age<<endl;
    // cout<<*p2.name<<endl;  //重载的赋值函数内 传入的对象 堆区的数据会被释放 所以无法输出
    cout<<p3.age<<endl;
    cout<<*p3.name<<endl;


}
int main(){
fun1();
}
/*
2.31 
     ---第一天---   
     上午：10:45飞机落地 11:00上地铁 首都机场线->2号线 
           12:00 到达天安门 参观打卡拍照
           13:00 吃饭
           14:00 地铁8号线->天坛
           14:30 到达天坛 参观打卡
           16:00 出天坛
           17:00 找旅馆放东西
           17:30 吃饭
           18:00 出发打卡水立方+鸟巢
           22:00 前返回睡觉


*/