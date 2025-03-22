#include<iostream>
using namespace std;
//数组的本质是一片连续的内存空间使用指针
void bubblesort (int *,int);
void printfarr(int *,int);
int main(){
    int arr[]={4,2,5,7,9,3,6,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,len);
    printfarr(arr,len);

}
void bubblesort(int *arr,int len){
int *p1,*p2;
   
    // cout<<size<<endl;
    int flag=len-1;  //设置最大比较趟数=元素个数
    while(flag){
    for (int i = 0; i <len -1; i++)
    {
        p1=&arr[i];
        p2=&arr[i+1];
        // cout<<int(p1)<<endl;
        if (*p1<*p2)
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

}
void printfarr(int *arr,int len){
 for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<endl;
        
    }
}