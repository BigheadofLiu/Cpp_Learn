#include<iostream>
using namespace std;
//成员函数作为友元
class Room;   //提前声明 防止编译器无法识别
class Gay{   //作为友元的函数需要写在被友元的函数前面
    public:
    Gay();
    // ~Gay();
    void visit1();
    void visit2();
    string G_name;
    private:
    Room *r1;
};

class Room{
    // friend class Gay;
    friend void Gay::visit1();
    // friend void Gay::visit2();
    public:
    Room();
    // ~Room();
    string R_room;
    private:
    string R_bedroom;
};

Room::Room(){
    this->R_room="客厅";
    this->R_bedroom="卧室";
}
Gay::Gay(){
    this->r1=new Room;
    this->G_name="坤坤";
}
void Gay:: visit1(){
    cout<<this->G_name<<"访问"<<r1->R_room<<endl;
    cout<<this->G_name<<"访问"<<r1->R_bedroom<<endl;
}
void Gay::visit2(){
    cout<<this->G_name<<"访问"<<this->r1->R_room<<endl;
    // cout<<this->G_name<<"访问"<<this->r1->R_bedroom<<endl; //没有设置为友元函数，访问失败
}
int main(){
 Gay g1;
 g1.visit1();
 g1.visit2();   

}
