#include<iostream>  
using namespace std;
//类中的属性和行为 统称为成员
//属性 成员属性 成员变量
//行为 成员函数 成员方法

class student{
    public: //访问权限

    int age;  //属性
    string name;
    int gread;

    //方法（函数）
    void showstu(){
        cout<<age<<endl<<name<<endl<<gread;
    }

    //形参传入实参 （函数）
    void setstu(int this_age,string this_name,int this_gread){
        age=this_age;
        name=this_name;
        gread=this_gread;
    }
};

int main(){
    student s1; //继承
    s1.setstu(18,"张三",20); //使用方法
    s1.showstu();    //使用方法
}