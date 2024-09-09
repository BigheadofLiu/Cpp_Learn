/*字符串比较*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";
    string s3 = "hello world";
    string s4 = "hello";
    string s5 = "hello world";
    string s6 = "hello world!";
    
    int ret=s1.compare(s2);
    if(ret==0){
        cout<<"="<<endl;
    }else{
        cout<<"不相等"<<endl;
    }
    
    int ret1=s1.compare("hello");
    if(ret1==0){
        cout<<"="<<endl;
    }else{
        cout<<"不相等"<<endl;
    }
    
    // ==, !=, <, <=, >, >=
    
}