#include<string.h>
#include<iostream>
using namespace std;
int main(){
    //c语言风格，使用字符型数组
    char str1[]="你好 世界";
    // cin>>str1;
    
    //cpp风格
    string str2="";
    cin>>str2;
    cout<<str1<<endl;
    cout<<str2<<endl;
}