#include<iostream>  
using namespace std;
//继承方式有三种
//1.public 2.protected 3.private
//public继承 成员访问权限保持不变
//protected继承 protected以下权限全变protected 
//private继承 private以下全部变为private
class dad{
    public:
    int a;
    protected:
    int b;
    private:  //paivate 下的成员属性无法继承
    int C;
};
class son1:public dad{
    void fun(){
        a=100; //修改成功 public
        b=100; //修改成功 protected
        // c=100; //修改失败 private
    }

};
class son2:protected dad{
    void fun(){
        a=200; //修改成功 protected
        b=200; //修改成功 protected
        // c=100; //修改失败 private
        
    }

};
class son3:private dad{
    void fun(){
       a=300; //修改成功(内部) private
       b=300; //修改成功 private
    //    c=300; //修改失败 private
    }
};
void fun1(){
    son1 s1;
    cout<<s1.a;
    // cout<<s1.b; //访问失败（外部）protected
    // cout<<s1.c; //访问失败（外部）private
}
void fun2(){
     son2 s2;
    //  cout<<s2.a;   //访问失败（外部）protected
    // cout<<s2.b; //访问失败（外部）protected
    // cout<<s2.c; //访问失败（外部）private
}
void fun3(){
     son3 s3;
    //  cout<<s3.a;   //访问失败（外部）private
    // cout<<s3.b; //访问失败（外部）private
    // cout<<s3.c; //访问失败（外部）private
}
int main(){
    fun1();
    // fun2();
    // fun3();
}

