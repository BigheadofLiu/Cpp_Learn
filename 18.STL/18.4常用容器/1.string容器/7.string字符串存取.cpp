/*字符串存取*/
#include<iostream>
using namespace std;
#include<string>
void test(){
    string s1="hello world!,i am your father!";
    //str[i]
    for (int i = 0; i < s1.size(); i++)
    {
        cout<<s1[i];
        /* code */
    }
    //str.at(i)
    cout<<endl;
    for (int i = 0; i < s1.size(); i++)
    {
        cout<<s1.at(i);
        /* code */
    }
}
void test01(){
    string s1="wdnmdcnm";
    s1[2]='c';
    cout<<s1<<endl;

    s1.at(2)='x';
    cout<<s1<<endl;

}
int main(){
    test();
    test01();
}
