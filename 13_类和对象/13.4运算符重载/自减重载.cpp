#include<iostream>
using namespace std;
//自减重载 前置&后置
class MyInteger{
    friend  ostream& operator<<(ostream &out,MyInteger m);
    public:
    MyInteger(int inter){
    this->m_inter=inter;
    }
    MyInteger operator--(){
        //前置自减
        m_inter--;
        return *this;

    }
    MyInteger operator--(int){
        //后置自减
        MyInteger temp=*this;
        this->m_inter--;
        return temp;

    }
    private:
    int m_inter;
};
ostream& operator<<(ostream &out,MyInteger m){
    cout<<m.m_inter<<endl;
}
void fun1(){
    MyInteger m1(10);
    cout<<m1--;
    cout<<m1<<endl;

}
void fun2(){
    MyInteger m2(10);
    cout<<--m2;
    cout<<m2<<endl;
}
int main(){
    fun1();
    fun2();
}