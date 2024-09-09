#include<iostream>
using namespace std;
//char demo
int main(){
    char a='a'; //可以单引号直接赋值
    char b=97; //可以直接赋ASCII码值
    cout<<a<<endl;
    cout<<(int)a<<endl; //输出对应字符的ASCII码值
    cout<<sizeof(b)<<endl; //字符型变量占用内存大小为1个字节（1B）
    cout<<b<<endl;

}

