#include<iostream>
#include<string.h>
#include"fstream"
using namespace std;
class person{
    public:
    // person(int age,string name){
    // this->age=age;
    // this->name=name;
    // }
    int age;
    string name;
};
void test(){
    //写二进制文件
    // person p1={18,"kunkun"};
    // fstream fst1;
    // fst1.open("test01.txt",ios::out | ios::binary); 
    // fst1.write((const char *)&p1,sizeof(p1));
    // fst1.close();

    //读二进制文件
    fstream fst2;
    fst2.open("test01.txt",ios::in|ios::binary);
    if (!(fst2.is_open()))
    {
        cout<<"打开失败"<<endl;
        return;
    }
    
    person p2;  //创建一个空对象 用于接收读取的二进制数据
    fst2.read((char *)&p2,sizeof(p2));
    fst2.close();
    cout<<p2.age<<p2.name<<endl;
    
    

}
int main(){
    test();
}