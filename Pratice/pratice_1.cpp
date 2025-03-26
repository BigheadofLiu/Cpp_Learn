#include <cstdlib>
#include<iostream>
#include<ctime>
#include <iterator>
#include <ostream>
using namespace std;
//结构体的应用
struct student{
    string name;
    // int age;
    int score;
};
struct teacher
{
    student stu[5];
    string name;
    /* data */
};
void scanf_info(teacher arr_t[],int len){
    string str1="ABCDE";
//    srand(time(0));
    for(int i=0;i<len-1;i++){

        arr_t[i].name="teacher_";
        arr_t[i].name+=str1[i];
        for(int k=0;k<5;k++){

            arr_t[i].stu[k].name="student";
            arr_t[i].stu[k].name+=str1[k];
            arr_t[i].stu[k].score=(rand()%60+40);
        }
    }
}
void print_info(teacher *p,int len){
    for(int i=0;i<len-1;i++){
        cout<<p->name<<":"<<endl;
        for(int k=0;k<5-1;k++){
            cout<<p->stu[k].name<<" "<<p->stu[k].score<<endl;
        }
    }
}
int main(){
    srand(time(NULL)); //初始化随机数种子
    teacher t1[5];
     int len=std::size(t1); //cpp17用法
//    int len=sizeof(t1)/sizeof(t1[0]); //旧
    scanf_info(t1,len);
    print_info(t1,len);
}






