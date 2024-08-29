//普通函数与模板函数的区别
//1.普通函数可以进行隐式转换，模板函数不会自动进行隐式转换（手动指定类型后可以）
//2.调用规则；优先调用普通函数，可以设置空模板参数列表强制调用函数模板，函数模板可以更好匹配参数则优先调用函数模板
            //函数模板可以发生重载

#include<iostream>
using namespace std;

void temp(int a,int b){
    cout<<"普通函数"<<endl;
}

template <class T>
void temp(T a,T b){
    cout<<"函数模板"<<endl;
}

template<class T>  //函数模板可以发生重载
void temp(T a,T b,T c){
    cout<<"函数模板重载"<<endl;
}

int main(){
int a=100,b=102,c=103;
// temp(a,b); //优先匹配普通函数
temp<>(a,b);  //空指定会优先调用(跳过普通函数)
temp(a,b,c);

char d='c',e='k';
temp(d,e); //优先更为匹配的函数模板
return 0;

}

//使用函数模板最好就不要再使用普通函数 容易产生歧义