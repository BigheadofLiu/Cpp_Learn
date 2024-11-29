#include<iostream>
using namespace std;
void test1(){
throw 1;
throw "c";
//可以抛出任意类型异常
}

// void test2() throw(int,char){  
//     //只能抛出特定异常类型(已废弃)
//     throw 3;
//     throw 'c';
//     throw"hello world";
// }

// 不能抛出异常的两种写法
//旧标准
void test3() throw(){
throw 1;
}
//新标准
void test4() noexcept(true){
throw 'c';
}

int main(){
    try{
        test3();
    }catch(int){
        cout<<"捕获到test3异常"<<endl;  //因为定义异常无法抛出 所以捕获不到异常
    }catch(const char*){
        cout<<"捕获到test4异常"<<endl;
    }
}
