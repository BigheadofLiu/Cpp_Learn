//
// Created by ZYB on 2025/2/11.
//
#include "iostream"
using namespace std;
/*
 * c++ 11中friend的改进
 * 1.不需要再写class（可以使用类的别名）
 * 2.类模板声明友员
 * 3.
 * 4.
 * */
class a;
using c=a;
class b{
public:
    friend c;
private:
    int num=100;
};
class a{
    /*a(){
        b1=new b;
    }*/
    int num;
    b* b1;
public:
    void shownum();
    ~a(){
        if (b1!= nullptr){
            delete b1;
        }
    }
};
void a::shownum() {
    this->b1=new b;
    cout<<b1->num<<endl;
}
void test01(){
a a1;
a1.shownum();
}

//2.模板类友员
template<class T>
class person{
    friend  T;
public:
    person(){
        cout<<"模版类友员"<<endl;
    }
};
class chinese{

};
void test02(){
    person<chinese> p1;
    person<int> p2; //int同样可以传入

//    模版类友员
//    模版类友员
}

int main(){
//    test01();
    test02();
}