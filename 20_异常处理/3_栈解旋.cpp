#include<iostream>
using namespace std;
class Data{
    private:
    int m_data;
    public:
    Data(int data){
    this->m_data=data;
    cout<<"data构造函数"<<endl;
    }
    ~Data(){
    cout<<"data析构函数"<<endl;
    }
};
int main(){
    // data d1,d2,d3;
    try{
        Data d1(100);
        Data d2(200);
        Data d3(300);
        throw 3;
    }catch(int e){
        cout<<"整型异常"<<endl;
    }catch(char e){
        cout<<"字符型异常"<<endl;
    }catch(...){
        cout<<"其他异常"<<endl; 
    }
    return 0;
}
/*
data构造函数
data构造函数
data构造函数
data析构函数
data析构函数
data析构函数
整型异常

异常抛出后，栈上构造的所有对象，被自动析构

*/