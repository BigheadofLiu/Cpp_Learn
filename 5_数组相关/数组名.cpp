#include<iostream>
using namespace std;
int main(){
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        /* code */
    }
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    cout<<arr<<endl;  //获取首地址
    cout<<&arr[1]<<endl; //获取第二个元素地址
    


    
    
}