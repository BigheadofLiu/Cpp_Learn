/*
vector赋值
1.vector v1=v2 函数原型：vector& operator=(const vector &vec);
2.assign(beg,end) vector v2;v2.assign(v1.begin(),v1.end());
3.assign(n,elem) vector v3;v3.assign(10,10);
*/
#include"string"
using namespace std;
#include<iostream>
#include<vector>
void print_vector(vector<int>& v){
    for(vector<int>::iterator i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}
int main(){
vector<int> v1;
for(int i=0;i<10;i++){
    v1.push_back(i);
}
print_vector(v1);
vector<int> v2(v1);  //简写v2=v1
print_vector(v2);
vector<int> v3;v3.assign(v2.begin(),v2.end());
print_vector(v3);
vector<int> v4;v4.assign(10,'c');print_vector(v4);
}

