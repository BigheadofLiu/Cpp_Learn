#include<iostream>
using namespace std;
#include<list>
#include <string>
/*�Զ����������͵����� ��Ҫָ���������*/
class person{
    public:
    person(string name,int age,int height){
    this->name=name;
    this->age=age;
    this->height=height;
    }
    public:
    string name;
    int age;
    int height;
};
void print_list(const list<person> &L){  //��ӡ
    for(list<person>::const_iterator it=L.begin();it!=L.end();it++){
       cout << it->name<< " "<<it->age<<" "<<it->height<<" ";
    }
    cout<<endl;
}
bool sort_list(person& p1, person& p2){
    if(p1.age==p2.age){
        return p1.height>p2.height; //���������ͬ �������߽�������
    }else{
        return p1.age<p2.age; //������������
    }
}
int main(){
    list<person> lst1;
    person p1("����",55,180);
    person p2("����",45,170);
    person p3("�ŷ�",40,190);
    person p4("�ܲ�",60,175);
    person p5("��Ȩ",50,165);
    person p6("���",35,160);
    person p7("���",30,170);
    lst1.push_back(p1);
    lst1.push_back(p2);
    lst1.push_back(p3);
    lst1.push_back(p4);
    lst1.push_back(p5);
    lst1.push_back(p6);
    lst1.push_back(p7);
    print_list(lst1);
    // lst1.sort(); //Ĭ��������� ���Զ���������Ч
    // print_list(lst1);
    lst1.sort(sort_list);
    print_list(lst1);

}
