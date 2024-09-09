#include<iostream>
#include <string>
using namespace std;
/*运算符重载
string& operator=(const char* s)   string s1="hello world"
string& operator=(const string& s) string s2=s1
string& operarot=(char c)          string s3='c'

string& assign(const char* s)      string s4="hello world"
string& assign(const char* s,int n)string s5=("hello world!",3)
string& assign(const string &s)    string s6=s5
string& assign(int b,char c)       string s7=(5,'c')
*/
int main(){
string s1="hello world";
cout<<s1<<endl;
string s2=s1;
cout<<s2<<endl;
string s3;  
s3='a';   //直接使用string s3='a'报错 属于初始化变量 不能调用操作符重载来进行隐式转换
cout<<s3<<endl;
std::string s4;s4.assign("hello C++");
cout<<s4<<endl;
std::string s5;s5.assign("hello world!",5);
cout<<s5<<endl;
string s6;s6.assign(s5);
cout<<s6<<endl;
string s7;s7.assign(5,'c');
cout<<s7<<endl;
}