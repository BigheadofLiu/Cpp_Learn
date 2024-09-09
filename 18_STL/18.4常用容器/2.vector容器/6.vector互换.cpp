/*
v1.swap(v2)*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    vector<int> v2;
    for(int i=10;i<20;i++){
        v2.push_back(i);
    }
    cout<<"before:"<<endl;
    for(int i=0;i<10;i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<v2.at(i)<<" ";
    }
    cout<<endl;
    v1.swap(v2);
    cout<<"after:"<<endl;
    for(int i=0;i<10;i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<v2.at(i)<<" ";
    }


}