#include<iostream>  
using namespace std;
//函数调用重载（仿函数）
//重载的（）运算符
class Add_num{
    public:
   int operator()(int a,int b){
        cout<<a+b<<endl;
        return a+b;
    }
   
};
void fun1(){
    Add_num add;
    // a1.operator()(10,20);
    //等价于
    add(10,20);
}

void add(int a,int b){
    cout<<a+b<<endl;
}
int main(){
    fun1();
    add(10,20);  //(仿函数的由来)

   int ret=Add_num()(10,10);  //初始化匿名对象 本行后会被释放
   cout<<ret<<endl;
    // a1.operator()(10,20);

}