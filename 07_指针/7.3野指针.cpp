#include<iostream>
using namespace std;
int main(){
    int * p=(int *)0x1100;
    cout<<*p<<endl;
    delete p;
    // cout<<*p<<endl;
}