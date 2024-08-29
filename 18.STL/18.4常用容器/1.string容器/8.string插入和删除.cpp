#include<iostream>
using namespace std;
#include<string>
int main(){
string s1="abcdefghijklmn";
string s2="wdnmd";
// s1.insert(1,"wdnmd");
// s1.insert(1,s2);
s1.insert(1,5,'c');
cout<<s1<<endl;
s1.erase(1,5);
cout<<s1<<endl;
}