#include<iostream>
using namespace std;

template<class T>
void m_swap(T &b,T &a){
    T temp;
    temp=b;
    b=a;
    a=temp;
}

template<class T>
void arr_sort(T arr[],int len){
    for (int i = 0; i < len; i++)
    {
        int max=i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[max]<arr[j])
            {

                max=j;
                /* code */
            }
            /* code */
        }
        if (max!=i)
        {
            m_swap(arr[max],arr[i]);
            /* code */
        }
        /* code */
    }
}

template<class T>
void arr_printf(T arr[],int len){
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<endl;
        /* code */
    }
}

void test01(){ //测试char数组
    char arr[]="ghjdkngjhr";
    int len=sizeof(arr)/sizeof(arr[0]);
    arr_sort(arr,len);
    arr_printf(arr,len);
}

void test02(){ //测试int数组
    int arr[]={20,59,89,77,60,46};
    int len=sizeof(arr)/sizeof(arr[0]);
    arr_sort(arr,len);
    arr_printf(arr,len);
}

int main(){
    test01();
    test02();
}



