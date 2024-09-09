#include<iostream>
using namespace std;
//使用指针遍历数组
int main(){
    int a[5] = {1,2,3,4,5};
    int *p=a;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        cout<<*p<<endl;
        p++;
        /* code */
    }
    
}