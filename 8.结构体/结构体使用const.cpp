#include<iostream>
using namespace std;
#include<string.h>
//结构体中使用const

 struct student{
    int age;
    const char *name;
}s1;
void printf(const student *);

int main(){
  s1={18,"狗蛋"};
  printf(&s1);

}
void printf(const student *p){
    // p->age=100;  //const修改失败 表达式必须是可修改的左值
    cout<<p->age<<endl;
    cout<<p->name<<endl;
}