/*
set/multiset Ԫ�ز���ʱ�ᱻ�Զ�����
�ײ��Ƕ�����
set����������ظ���Ԫ��
multiset��������ظ���Ԫ��
1.set �����븳ֵ
set<T> st; Ĭ�Ϲ���
set(const set& st) ��������
set& operator=(const set& st) ��������ظ�ֵ

2.�����ɾ��
insert()  //������Զ�����
clear()
erase(pos)
erase(beg,end)
erase(elem)

3.��С�ͽ���
size()
empty()
swap(set)

4.���Һ�ͳ��
fing(key)  //����ֵΪ���������� set<int>::iterator pos=s1.find(30) ���δ�ҵ��򷵻�s1.end()
cout(key) �����0��1

5.set/multiset
set�߲���߷��ز����� ��������ظ����������ʧ��
multiset������м�� �����������ظ�����

6.pair����
pair<T,T> p(value1,value2)
pair<T,T>=make_pair(value1,value2);

7.set����Ĭ�ϴ�С����
  1.������������
  2.�Զ���������

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
        cout<<"����ɹ�"<<endl;
    }else{
        cout<<"����ʧ��"<<endl;
    }
    p=lst1.insert(1);  //�ڶ��β���ʧ��
    if(p.second){
        cout<<"����ɹ�"<<endl;
    }else{
        cout<<"����ʧ��"<<endl;
    }

    multiset<int> mul1;
    mul1.insert(1);
    mul1.insert(1);  //���ξ�����ɹ�
    for (multiset<int>::iterator i = mul1.begin(); i !=mul1.end(); i++)
    {
        cout<<*i<<" ";
        /* code */
    }
    cout<<endl;
}
void test06(){
    pair<string,int> p=make_pair("����",88);
    cout<<p.first<<" "<<p.second<<endl;
}
class Mycompare{  //�º����Զ����������
    public:
    bool operator()(int v1,int v2){
        return v1>v2; //�Ӵ�С����
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
    print_set(set1); //Ĭ�ϴ�С����

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
    public:  //�º����Զ����������
    bool operator()(const Person& p1,const Person& p2){   //����ֵ��bool operator()
        return p1.age>p2.age;
    }
};
void test07_2(){
    //�Զ���������������
    set<Person,Mycompare2> set1;
    Person p1("����",18);
    Person p2("����",20);
    Person p3("����",19);
    Person p4("����",17);
    Person p5("Ǯ��",21);
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