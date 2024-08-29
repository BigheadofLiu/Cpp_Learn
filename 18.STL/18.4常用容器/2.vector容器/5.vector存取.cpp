#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
vector存取
1.vector.at()
2.vector operator[]
3.vector.front()
4.vector.back()
*/
int main(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    //1.
    for(int i=0;i<10;i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    //2.
    for(int i=0;i<10;i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    //3.获取首尾
    cout<<v1.front()<<" "<<v1.back();
}