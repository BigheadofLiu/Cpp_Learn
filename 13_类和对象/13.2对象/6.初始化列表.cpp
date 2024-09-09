#include "iostream"
using namespace std;
//初始化对象属性值
//1.传统方式：有参构造
//2.初始化列表方式 语法方式：Person(int a,char b,string c...):age(a),sex(b),name(c)...
class Person{
    public:
    //传统方式 使用有参构造
    // Person(int age,int name){
    // p_age=age;
    // p_name=name;
    // }
    int p_age;
    int p_name;

    //初始化列表方式 语法

    Person(int a,int b):p_age(a),p_name(b){

    }
};
int main(){
    Person p1(10,123);  //参数传递方式一致
    cout<<p1.p_age<<" "<<p1.p_name<<endl;

}