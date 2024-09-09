#include<iostream>  
using namespace std;
//左移运算符重载 作用：可以输出自定义的数据类型

//1.
// class Person{
//     friend ostream& operator<<(ostream& cout,Person& p);
// public:
//     Person(string name,int age){
//         this->m_Name = name;
//         this->m_Age = age;
//     }
//     string m_Name;
//     int m_Age;
// };

// //重载左移运算符
// ostream& operator<<(ostream& out,Person& p){
//     out << "name: " << p.m_Name<< endl << " age: " << p.m_Age;
//     return out;
// }

// void test01(){
//     Person p("Tom",18);
//     // cout << p << endl; //等价于
//     operator<<(cout,p)<<endl;
// }

// int main(){
//     test01();
//     return 0;
// }
class Person{
    public:
    friend ostream& operator<<(ostream &cout,Person &p1);
    //左移运算符只有全局函数可以重载 成员函数无法重载左移运算符
    Person(int age,string name){
    this->m_age=age;
    this->m_name=name;
    }
    private:
    int m_age;
    string m_name;
};
ostream& operator<<(ostream &cout,Person &p1){  //cout必须使用引用 cout只用一个
    cout<<p1.m_age<<" "<<p1.m_name;
}
void fun1(){
    Person p1(22,"坤坤");
    // operator<<(cout,p1)<<endl;
    cout<<p1<<endl;  //等价于以上的语句

}
int main(){
    fun1();
}
