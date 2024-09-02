/*
for_each(v.beg(),v.end(),_fun_)  遍历容器  fun可以是普通函数（不带括号） 也可以是函数对象（带括号）
transform(v1.beg(),v1,end(),v2.beg(),_fun_)  容器间搬运 搬运前需要
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class my_print{
    void operator()(int val){
        cout<<val<<" ";
    }
};
void my_print(int val){
    cout<<val<<" ";

}
void test01(){
    

}
void test02(){

}