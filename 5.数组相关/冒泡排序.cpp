#include<iostream>  
using namespace std;
//冒泡排序 每次比较都会有一个元素的位置被确定
int main(){
    int arr[5]={100,34,22,178,40};
    // int arr[6]={};
    int size=sizeof(arr)/sizeof(arr[0]);
    // cout<<"请输入任意六个数字"<<endl;
    // for (int i = 0; i < size-1; i++)
    // {

    //  cin>>arr[i]<<endl;
    // }
    int *p1,*p2;
   
    // cout<<size<<endl;
    int flag=size-1;  //设置最大比较趟数=元素个数
    while(flag){
    for (int i = 0; i <size -1; i++)
    {
        p1=&arr[i];
        p2=&arr[i+1];
        // cout<<int(p1)<<endl;
        if (*p1>*p2)
        {      
            //交换
            int temp=*p1;
            *p1=*p2;
            *p2=temp;
                      
        } 
       
        // cout<<"我执行了"<<count<<"次"<<endl;
             
        // cout<<flag<<endl;      
    }
    flag--;
    }
    //输出
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
        
    }
    return 0;
}


