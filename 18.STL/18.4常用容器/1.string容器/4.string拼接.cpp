#include<iostream>
using namespace std;
/*
string 拼接字符串
1.重载+=
string& operator+=(const char* s)     s1+="hello world"
string& operator+=(const string& s)   s2+=s1
string& operator+=(const char c)      s3+='c'

2.append
string& append(const char* s)         s1.append("hello world")
string& append(const char* s,int n)   s2.append("hello world",4)
string& append(const string& s)       s3.append(s2)
string& append(const string& s,int pos,int n) s4.append(s3,3,3)
*/
int main(){
    std::string s1;
    s1+="hello world";
    std::cout<<s1<<endl;
    string s2="wdnmd";
    s2+=s1;
    cout<<s2<<endl;
    string s3;
    s3+="s";
    cout<<s3<<endl;
    string s4;
    s4.append("hello world");
    cout<<s4<<endl;
    string s5;
    s5.append(s4);
    string s6;
    s6.append("hello world",4);
    cout<<s6<<endl;
    string s7;
    s7.append(s5,4);
    cout<<s7<<endl;
    string s8;
    s8.append("hello world!",2,5);  //字符串下标从0开始计数
    cout<<s8<<endl;
}