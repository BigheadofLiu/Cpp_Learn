#include<iostream>
using namespace std;
#include<string.h>
#include<ctime>
//结构体的综合运用
struct student{
    string name;
    int score;
};
struct teacher
{
    student stu[5];
    string name;
    /* data */
};
void scanfinfo(teacher arr_t[],int);
void printinfo(teacher *p,int);
int main(int argc, char const *argv[]){
    srand(time(NULL));
    teacher t[3];
    int len=sizeof(t)/sizeof(t[0]);
    scanfinfo(t,len);
    printinfo(t,len);
    return 0;
}
void scanfinfo(teacher arr_t[],int len){  //结构体数组 初始化的函数 不要使用指针
for (int i = 0; i < len; i++)
{
    string t1="ABCDE";
    arr_t[i].name="teacher_";
    arr_t[i].name+=t1[i];
    for (int j = 0; j < 5; j++)
    {
        string t2="12345";
        arr_t[i].stu[j].name="stu_";
        arr_t[i].stu[j].name+=t2[j];
        arr_t[i].stu[j].score=rand()%100;
        /* code */
    }
    /* code */
}

}
void printinfo(teacher *p,int len){
    for (int i = 0; i < len; i++)
    {
        cout<<p[i].name<<endl;
        for (int j = 0; j < 5; j++)
        {
            cout<<"\t"<<p[i].stu[j].name<<" "<<p[i].stu[j].score<<endl;
            /* code */
        }
        /* code */
    }
}