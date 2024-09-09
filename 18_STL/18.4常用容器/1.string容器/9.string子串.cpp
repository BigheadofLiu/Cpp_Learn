/*string子串*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1="liujunlong@zuoyebang.com";
    cout<<sizeof(s1)<<endl;
    string name=s1.substr(0,10); //截取子串
    cout<<"name:"<<name<<endl;
    // cout<<"wdnmd"<<endl;

    int pos=s1.find("@");
    cout<<pos<<endl;
    string mail=s1.substr(pos);
    cout<<"mail:"<<mail<<endl;
    return 0;
}