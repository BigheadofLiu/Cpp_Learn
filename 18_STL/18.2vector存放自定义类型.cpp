#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace  std;
template<class T1,class T2>
class Person{
public:
Person(T1 name,T2 age){
this->age=age;
this->name=name;
}
public:
T1 name;
T2 age;    
};
void print_vector_1(Person<string,int> p){
        cout<<p.age<<p.name<<endl;
}
void print_vector_2(Person<string,int> &p){
        cout<<p.age<<p.name<<endl;
}
//测试存放对象
void test01(){
        vector<Person<string,int>> v;
        v.push_back(Person<string,int>("张三",18));
        v.push_back(Person<string,int>("李四",19));
        v.push_back(Person<string,int>("王五",20));
        v.push_back(Person<string,int>("赵六",21));
        v.push_back(Person<string,int>("钱七",22));
        v.push_back(Person<string,int>("孙八",23));
        for_each(v.begin(),v.end(),print_vector_1);
}
//测试存放指针
void test02(){
        vector<Person<string,int>*> v;
        Person<string,int> p1("张三",18);
        Person<string,int> p2("李四",19);
        Person<string,int> p3("王五",20);
        Person<string,int> p4("赵六",21);
        Person<string,int> p5("钱七",22);
        Person<string,int> p6("孙八",23);
        v.push_back(&p1);
        v.push_back(&p2);
        v.push_back(&p3);
        v.push_back(&p4);
        v.push_back(&p5);
        v.push_back(&p6);
        vector<Person<string,int>*> ::iterator it=v.begin();
        for(;it!=v.end();it++){
                cout<<(*it)->age<<(*it)->name<<endl;
        }
}
int main(){
        test01();
        test02();
}
