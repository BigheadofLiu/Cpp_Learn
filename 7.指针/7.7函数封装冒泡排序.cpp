#include<iostream>
using namespace std;
//����ı�����һƬ�������ڴ�ռ�ʹ��ָ��
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
    int flag=len-1;  //�������Ƚ�����=Ԫ�ظ���
    while(flag){
    for (int i = 0; i <len -1; i++)
    {
        p1=&arr[i];
        p2=&arr[i+1];
        // cout<<int(p1)<<endl;
        if (*p1<*p2)
        {      
            //����
            int temp=*p1;
            *p1=*p2;
            *p2=temp;
                      
        }    
        // cout<<"��ִ����"<<count<<"��"<<endl;
             
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