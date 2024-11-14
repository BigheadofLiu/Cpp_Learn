#include<iostream>  
using namespace std;
int main(){
    //数组变量逆置
    int a[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int begin=0;
    int end=sizeof(a)/sizeof(a[0])-1;
    while(begin<end){
        int temp=a[begin];
        a[begin]=a[end];
        a[end]=temp;
        begin++;
        end--;
    }
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        cout<<a[i]<<" ";
    }
}