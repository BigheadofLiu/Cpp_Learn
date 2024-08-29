#include<iostream>
using namespace std;
#include<string.h>
struct student
{
 
 int age;
 string name;
 int grade;
};
int main(){
student s1[]={
    // (13,"刘俊龙",9), //错误写法，应该用{ }
    {13,"刘俊龙",9},
    {13,"张三",9},
    {13,"李四",9},
    {13,"王五",9},
};
for (int i = 0; i < 4; i++)
{ 
    cout<<i<<s1[i].age<<s1->grade<<s1->name<<endl;
    /* code */
}


}

