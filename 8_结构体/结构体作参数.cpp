#include<iostream>
using namespace std;
//结构体作为参数
struct Student{
        int age;
        int score;
    };

void print1(Student stu);
void print2(Student *p);

int main(){
    
    Student stu;
    stu.age=10;
    stu.score=90;
    
    // print1(stu);
    Student *p=&stu;
    print2(p);
    cout<<"主函数中："<<stu.age<<" "<<stu.score<<endl;
}

// void print1(Student stu){
//     stu.age=12;
//     stu.score=80;
//     cout<<"调用函数中："<<stu.age<<" "<<stu.score<<endl;
// }

void print2(Student *p){
    p->age=12;
    p->score=80;
    cout<<"调用函数中："<<p->age<<" "<<p->score<<endl;
    // cout<<"调用函数中："<<stu.age<<" "<<stu.score<<endl;
}
