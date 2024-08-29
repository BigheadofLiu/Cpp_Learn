//容器嵌套
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void print_vector(vector<int>&);
void print(int);
void test01(){
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for(int i=0;i<4;i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for_each(v.begin(),v.end(),print_vector); //单层循环垃圾

}
void print_vector(vector<int> &v){
    for_each(v.begin(),v.end(),print);
    cout<<endl;
}
void print(int val){
    cout<<val<<endl;
}
int main(){
    test01();
    return 0;
}