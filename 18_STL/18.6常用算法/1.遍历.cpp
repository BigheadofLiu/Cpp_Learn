/*
for_each(v.beg(),v.end(),_fun_)  遍历容器  fun可以是普通函数（不带括号） 也可以是函数对象（带括号）
transform(v1.beg(),v1,end(),v2.beg(),_fun_)  容器间搬运 搬运前需要
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class my_print01{
    public:
    void operator()(int val){
        cout<<val<<" ";
    }
    
};
void my_print02(int val){
    cout<<val<<" ";
}
int get_val(int val){
    return val;
}
void creat_vector(vector<int>& v){
for(int i=0;i<10;i++){
    v.push_back(rand()%100+1);
}
}
void test01(){
    vector<int> v1;
    creat_vector(v1);
    for_each(v1.begin(),v1.end(),my_print02);
    cout<<endl;
    for_each(v1.begin(),v1.end(),my_print01());  //函数对象不能与普通函数同名（重载）
    cout<<endl;
    vector<int> v2;
    v2.resize(v1.size());  //transform之前需要分配空间
    transform(v1.begin(),v1.end(),v2.begin(),get_val);
    for_each(v2.begin(),v2.end(),my_print01());
    cout<<endl;
    for_each(v1.begin(),v1.end(),my_print02);
    cout<<endl;
}
void test02(){

}
int main(){
    test01();
}