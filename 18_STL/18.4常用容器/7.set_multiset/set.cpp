/*
set/multiset 元素插入时会被自动排序
底层是二叉树
set不允许存在重复的元素
multiset允许存在重复的元素
1.set 构造与赋值
set<T> st; 默认构造
set(const set& st) 拷贝构造
set& operator=(const set& st) 运算符重载赋值

2.插入和删除
insert()  //插入后自动排序
clear()
erase(pos)
erase(beg,end)
erase(elem)

3.大小和交换
size()
empty()
swap(set)

4.查找和统计
fing(key)  //返回值为迭代器类型 set<int>::iterator pos=s1.find(30) 如果未找到则返回s1.end()
cout(key) 结果是0或1

5.set/multiset
set边插入边返回插入结果 如果存在重复数据则插入失败
multiset不会进行检测 因此允许存在重复数据

6.pair对组
pair<T,T> p(value1,value2)
pair<T,T>=make_pair(value1,value2);

7.set排序（默认从小到大）
  1.内置类型排序
  2.自定类型排序

*/

#include<iostream>
using namespace std;
#include<set>
#include <string>

void test05(){
    set<int> lst1;
    pair<set<int>::iterator,bool> p;
    p=lst1.insert(1);
    if(p.second){
        cout<<"插入成功"<<endl;
    }else{
        cout<<"插入失败"<<endl;
    }
    p=lst1.insert(1);  //第二次插入失败
    if(p.second){
        cout<<"插入成功"<<endl;
    }else{
        cout<<"插入失败"<<endl;
    }

    multiset<int> mul1;
    mul1.insert(1);
    mul1.insert(1);  //两次均插入成功
    for (multiset<int>::iterator i = mul1.begin(); i !=mul1.end(); i++)
    {
        cout<<*i<<" ";
        /* code */
    }
    cout<<endl;
}
void test06(){
    pair<string,int> p=make_pair("丁真",88);
    cout<<p.first<<" "<<p.second<<endl;
}
class Mycompare{  //仿函数自定义排序规则
    public:
    bool operator()(int v1,int v2){
        return v1>v2; //从大到小排序
    }
};
void print_set(set<int>& s){
    for (set<int>::iterator i = s.begin(); i!=s.end(); i++)
    {
        cout<<*i<<" ";
        /* code */
    }
    cout<<endl;
}

void test07_1(){
    set<int> set1;
    for(int i=10;i<20;i++){
        set1.insert(i);
    }
    print_set(set1); //默认从小到大

    set<int,Mycompare> set2;
    for(int i=10;i<20;i++){
        set2.insert(i);
    }
    for(set<int,Mycompare>::iterator i = set2.begin(); i!=set2.end(); i++)
    {
        cout<<*i<<" ";
        /* code */
    }
    cout<<endl;
}
class Person{
    public:
    string name;
    int age;
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
};
class Mycompare2{
    public:  //仿函数自定义排序规则
    bool operator()(const Person& p1,const Person& p2){   //返回值：bool operator()
        return p1.age>p2.age;
    }
};
void test07_2(){
    //自定义数据类型排序
    set<Person,Mycompare2> set1;
    Person p1("张三",18);
    Person p2("李四",20);
    Person p3("王五",19);
    Person p4("赵六",17);
    Person p5("钱七",21);
    set1.insert(p1);
    set1.insert(p2);
    set1.insert(p3);
    set1.insert(p4);
    set1.insert(p5);
    for (set<Person,Mycompare2>::iterator i = set1.begin(); i !=set1.end(); i++)
    {
        cout<<i->name<<" "<<i->age<<endl;
        /* code */
    }
}
int main(){
    // test05();
    // test06();
    // test07_1();
    test07_2();


}