//模板的局限性
//自定义数据类型（结构体，类）无法使用
#include<iostream>
using namespace std;

class person
{
    public:
    int age;
    string name;
    /* data */

    person(/* args */string name,int age){
        this->age=age;
        this->name=name;
    }
    ~person();
};

//普通函数模板
template<class T>
bool compare(T &a,T &b ){
    if (a==b)
    {
        return true;
        /* code */
    }else{
        return false;
    }
}

// template<person> //非类型模板参数无法作为类类型
//具体化  以template<>开头定义
template<> bool compare(person &p1,person &p2){
if (p1.age==p2.age||p2.name==p2.name)
{
    return true;
    /* code */
}else{
    return false;
}

}
void dowork01(){
    int a=10,b=23;  //内置数据类型
    int ret=compare(a,b); //调用普通函数模板
    if(ret){
        cout<<"a==b"<<endl;
    }else{
        cout<<"a!=b"<<endl;
    }

}
void dowork02(){
    person p1("蔡徐坤",18);  
    person p2("丁真",22);   //自定义数据类型
    int ret=compare(p1,p2); //调用模板具体化
    if (ret)
    {
        cout<<"="<<endl;
        /* code */
    }else
    {
        cout<<"!="<<endl;
    }
    
    

}

int main(){
    dowork01();
    dowork02();
    return 0;
}


