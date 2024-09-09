#include<iostream>
using namespace std;
//自增重载 前置&后置
class MyInteger{
    public:
    friend ostream& operator<<(ostream &out,MyInteger m1);
    MyInteger(int a){
        this->Inter=a;
    }
    MyInteger operator++(){
        //++i 前置加
        this->Inter++;
        return *this;
    }
    MyInteger operator++(int){  //int作为参数占位符 是区分前置与后置的标志
        //i++ 后置加 麻烦一点
       //1 
       MyInteger temp=*this;  //记录 等待返回
       //2
        this->Inter++; //+1
       //3 
        return temp; //返回+之前的数据 达到后置+的效果

    }
    private:
    int Inter;
};
ostream& operator<<(ostream &out,MyInteger m1){
    cout<<m1.Inter<<endl;
}
void fun1(){
    MyInteger m1(20);
    cout<<++m1<<endl;
    cout<<m1<<endl;
}
void fun2(){
    MyInteger m2(10);
    cout<<m2++<<endl;
    cout<<m2<<endl;
}
int main(){
    fun1();
    fun2();
}



