#include<iostream>
using namespace std;
//友元：使其他地方能够访问到private属性
/*
1.全局函数作为友元
2.类作为友元
3.成员函数作为友元
*/
class home{
    friend void visitroom(home &h1); //全局函数设置为友元 
    public:
    string keting;
    private:
    string bath_room;
};
void visitroom(home &h1){
    h1.bath_room=1;//访问失败 设置为友元之后支持访问private类
    cout<<h1.bath_room<<"访问成功"<<endl;
}
void fun1(){
    home h1;
    visitroom(h1);

}
int main(){
    fun1();
}