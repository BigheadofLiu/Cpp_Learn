#include<iostream>
using namespace std;
void bubble(int *,int );
void printf(int *,int);
int main(){
    int arr[5]={1,4,3,2,5};
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<"请输入第"<<i<<"个数："<<endl;
    //     cin>>arr[i];
    //     /* code */
    // }
    int len=sizeof(arr)/sizeof(arr[0]);
    
    bubble(arr,len);
    printf(arr,len);
}
void bubble(int arr[],int len){
for (int i = 0; i < len-1; i++)
{
    for (int j = 0; j < len-1-i; j++)
    {
        if(arr[j]<arr[j+1]){
        
        int temp=arr[j];
        
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        /* code */
        }
    }   
    /* code */
}
}

void printf(int arr[],int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }
    cout<<endl;
}