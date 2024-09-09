#include<iostream>
using namespace std;
//使用private  
// 1.控制类内成员变量的访问权限 可读可写 只读 只写(类外不能访问，可以通过类内方法进行修改)
// 2.对于写权限 可以验证数据的合法性
class person{
    
    private:
    string name;
    int age;
    string idol;

    public:
    //name 写函数（写权限）
    void set_name(string s_name){
    name=s_name;
    }
    //name 读权限
    void get_name(){
    cout<<name<<endl;
    }

    void set_age(int s_age){
    if(s_age<0||s_age>110){ //检查输入是否合法
        cout<<"年龄输入非法"<<endl;
        return;
    }
    age=s_age;

    }

    void set_idol(string s_idol){
        idol=s_idol;
    }

    
};
int main(){
    person p1;
    p1.set_name("毛毛");
    p1.get_name();

    p1.set_age(160);
    p1.set_idol("坤坤");
    
}