#include<iostream>
#include<string>
using namespace std;
/*string构造函数
原型函数：
string::string() //接收空字符创建空对象 string str; 无参构造
string::string(const char* s) //接收单个字符  char c='s';string str=s(相当于string str(&s))
string::string(const string& str) //接收字符串 string str1=str2（相当于string str1(str2))
string::string(int n,char c)  //用N个字符初始化字符串
*/
void test(){
    string str1;//string str1();

    const char* c1="hello world";
    string str2(c1); //string str2=c1

    string str3="hello world";
    string str4(str3); //string str4=str3;
    
    string str5(10,'d');

    cout<<str1<<" "<<str2<<" "<<str3<<" "<<str4<<" "<<str5<<endl;
}
int main(){
    test();
    return 0;
}
