#include<iostream>  
using namespace std;
#define PI 3.14
//类的定义、封装、继承
//在我看来 类似与结构体

class yuan{
    //访问权限
    public:

    //属性
    int yuan_r;

    //方法
    void Caculate_C(){
        float C=2*PI*yuan_r;
        cout<<"该圆的周长为："<<C;
    }
};

class student{
    public:
    string name;
    float hight;
    int gread;
    
};

int main(){
    // yuan y1; //继承
    // y1.yuan_r=4;
    // y1.Caculate_C();
    student s1;
    cin>>s1.name;
    cin>>s1.hight;
    cin>>s1.gread;

    cout<<s1.name<<endl;
    cout<<s1.hight<<endl;
    cout<<s1.gread<<endl;
}