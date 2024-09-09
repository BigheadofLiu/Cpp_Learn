#include<iostream>
using namespace std;
//struct 与 class的区别
//本质没有区别 区别在于默认访问权限 struct：默认公共，class：默认私有
struct stu1{
    int age;
};
class stu2{
int age;
};
int main(){
    stu1 s1;
    stu2 s2;
    s1.age=10;
    // s2.age=100;  //访问失败


}