#include<iostream>  
using namespace std;
/*
虚析构-纯虚析构
问题背景：使用多态时，如果子类中有属性开辟到堆区，父类指针释放时无法调用到子类的析构代码。
1.可以解决父类指针释放子类对象开辟在堆区的数据
2.需要有具体的函数实现（纯虚析构也需要写实现）。
3.拥有纯虚析构的类属于抽象类，同样也无法实例化对象
4.
语法：
虚析构：virtual ~类名（）{}
纯虚析构：virtual ~类名（）=0；（*）
         类名：：~类名（）{}
*/
class base{
    public:
    base(){
    cout<<"base的无参构造"<<endl;
    }
    // virtual ~base(){
    // cout<<"base的析构函数"<<endl;
    // }
    virtual ~base()=0; //纯虚析构 报错 基类的析构函数必须有函数体
                       //所以纯虚析构需要写在类外

};
class kunkun:public base{
    public:
    kunkun(int skill){
        this->skill=new int(skill);
        cout<<"kunkun的无参构造"<<endl;
    }
    ~kunkun(){
        if (this->skill!=NULL)
        {
            delete this->skill;
            this->skill=NULL;
            /* code */
        }
        
    cout<<"kunkun的析构函数"<<endl;
    }
    int *skill; //自定义指针型类型 用于接受new关键字开辟的堆区数据

};
base::~base(){
cout<<"base的纯虚析构函数"<<endl;
}
void test1(){
   base *b1=new kunkun(4);  //堆区申请的内存都需要手动释放（delete）
   delete b1;
   b1=NULL;
//    base b1; //不允许使用抽象类类型 "base" 的对象
};
int main(){
    test1();
}

/*总结
虚函数或纯虚函数用于 通过父类指针释放子类开辟在堆区的数据
如果子类没有开辟在堆区的数据 可以不写虚析构
拥有纯虚析构的对象也属于抽象类 无法实例化具体的对象
*/