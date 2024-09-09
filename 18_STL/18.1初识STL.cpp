//容器<-->迭代器<-->算法
//STL六大组件：容器、算法、迭代器、仿函数、适配器、空间配置器
//容器：各种数据结构，如vector、list、deque、set、map等
//迭代器：用于遍历容器中的元素，提供一种统一访问容器中元素的方式
//算法：对容器中的元素进行操作，如排序、查找、复制等
//容器分为：顺序容器、关联容器
//算法分为：质变算法、非质变算法
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
void print(int val){
cout<<val<<endl;
}
void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    //遍历vector
    //1.自建遍历
    vector<int>::iterator begin=v.begin();
    while(begin!=v.end()){  //（v.begin()！=v.end()为啥就不行？）
    print(*begin);
    begin++;
    }
    printf("-----------------------------\n");
    //2.内置算法遍历
    for_each(v.begin(),v.end(),print);
}
int main(){
    test01();
}

