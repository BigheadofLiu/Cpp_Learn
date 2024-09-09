#include<iostream>  
using namespace std;
class dad{
    public:
    dad(){
        cout<<"我是dad构造"<<endl;      
    }
    ~dad(){
        cout<<"我是dad析构"<<endl;  
    }
};
class son:public dad{
    public:
    son(){
        cout<<"我是son构造"<<endl;      
    }
    ~son(){
        cout<<"我是son析构"<<endl;  
    }
};
void fun1(){
    son s1;
}
int main(){
fun1();
}

/*
我是dad构造
我是son构造
我是son析构
我是dad析构
*/