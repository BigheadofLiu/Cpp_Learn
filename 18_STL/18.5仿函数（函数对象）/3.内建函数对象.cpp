/*
STL内建的函数对象（自带） //标准库
算术仿函数
关系仿函数
逻辑仿函数

头文件：#include<functional>
1.算术仿函数
template<class T> T plus<T> //加法仿函数
template<class T> T minus<T> //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T> //除法仿函数
template<class T> T modulus<T> //取模仿函数
template<class T> T negate<T> //取反仿函数

2.关系仿函数(谓词)
template<class T> bool equal_to<T> //等于
template<class T> bool not_equal_to<T> //不等于
template<class T> bool greater<T> //大于
template<class T> bool greater_equal<T> //大于等于
template<class T> bool less<T> //小于
template<class T> bool less_equal<T> //小于等于

3.逻辑仿函数（谓词）
template<class T> bool logical_and<T> //逻辑与
template<class T> bool logical_or<T> //逻辑或
template<class T> bool logical_not<T> //逻辑非

*/
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
using namespace std;

void print_vector(vector<int>& v){
for (auto i = v.begin(); i!=v.end(); i++)
{   
    cout<<*i<<" ";
}
cout<<endl;
}
void creat_vector(vector<int>& v){
for(int i=0;i<10;i++){
    v.push_back(rand()%100+1);
}
}
void sort_vector(vector<int>& v){
    sort(v.begin(),v.end(),greater<int>());
}

void test01(){
    vector<int> v1;
    creat_vector(v1);
    print_vector(v1);
    sort_vector(v1);
    print_vector(v1);

}

void test02(){
    negate<int> ne;
    cout<<ne(50)<<endl;

    plus<int> p1;
    cout<<p1(50,1000)<<endl;

    
}

int main(){
    // srand(static_cast<unsigned int>(time(nullptr)));
    srand(time(0));
    // test01();
    test02();
}

