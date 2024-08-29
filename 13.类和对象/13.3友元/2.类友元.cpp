#include<iostream>
using namespace std;
//类作为友元
class home{
friend class classmate;   //把Classmate设置为类内友元
public:
home();
string h_name;
private:
string h_bathroom;  
};

class classmate{
public:
classmate();
void visit();
string c_name;
home *h1; //待访问类的指针
};

home::home(){    //声明作用域 类为写函数的实现
    this->h_name="刘大头";
    this->h_bathroom="刘大头的浴池";
};

classmate::classmate(){
    this->c_name="坤坤";
    this->h1=new home; //用指针接收堆区创建的数据

}
void classmate::visit(){
    cout<<this->c_name<<"访问了"<<h1->h_bathroom;
}
int main(){
    classmate c1;
    c1.visit();
    delete c1.h1; //释放堆区数据
}
