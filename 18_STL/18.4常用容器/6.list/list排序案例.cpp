#include<iostream>
using namespace std;
#include<list>
#include <string>
/*自定义数据类型的排序 需要指定排序规则*/
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
void print_list(const list<person> &L){  //打印
    for(list<person>::const_iterator it=L.begin();it!=L.end();it++){
       cout << it->name<< " "<<it->age<<" "<<it->height<<" ";
    }
    cout<<endl;
}
bool sort_list(person& p1, person& p2){
    if(p1.age==p2.age){
        return p1.height>p2.height; //如果年龄相同 按照升高降序排列
    }else{
        return p1.age<p2.age; //年龄升序排列
    }
}
int main(){
    list<person> lst1;
    person p1("刘备",55,180);
    person p2("关羽",45,170);
    person p3("张飞",40,190);
    person p4("曹操",60,175);
    person p5("孙权",50,165);
    person p6("孙策",35,160);
    person p7("周瑜",30,170);
    lst1.push_back(p1);
    lst1.push_back(p2);
    lst1.push_back(p3);
    lst1.push_back(p4);
    lst1.push_back(p5);
    lst1.push_back(p6);
    lst1.push_back(p7);
    print_list(lst1);
    // lst1.sort(); //默认排序规则 对自定义类型无效
    // print_list(lst1);
    lst1.sort(sort_list);
    print_list(lst1);

}
