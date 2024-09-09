#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
1.empty() 判断是否为空
2.capacity() 容量
3.size()  大小
4.resize(int num) 重新定义大小
5.resize(int num,elem) 变大指定元素扩充
*/
void print(int val){
    cout<<val<<" ";
}
int main(){
    vector<int> v1;for(int i=0;i<10;i++){v1.push_back(i);}
    if(v1.empty()){
        cout<<"NULL"<<endl;
    }else{
        cout<<"capacity="<<v1.capacity()<<endl;
        cout<<"size="<<v1.size()<<endl;
    }
    v1.resize(12);cout<<"size="<<v1.size()<<endl;
    v1.resize(20,'c'); //扩容填充
    for_each(v1.begin(),v1.end(),print);
}