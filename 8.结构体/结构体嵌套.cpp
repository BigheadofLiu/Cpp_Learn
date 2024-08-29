#include<iostream>
using namespace std;
#include<string.h>
//结构体嵌套
struct Student{
    int Grade;
    char name[20];
    int age;
};

struct Teacher{
    Student stu;
    char name[20];
    int age;
};

int main(){
Teacher t1={{80,"张三",20},"李四",30};
cout<<t1.stu.Grade<<endl;
cout<<t1.stu.name<<endl;
cout<<t1.stu.age<<endl;
cout<<t1.name<<endl;
cout<<t1.age<<endl;
return 0;


}