#include "iostream" 
using namespace std;
int main(){
    int arr[2][3]={1,2,3,4,5,6};
    int arr1[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int arr2[][3]={1,2,3,4,5,6};
    int arr3[][3]={1,2,3,4,5,6};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
cout<<"------------------------"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<sizeof(arr)<<endl;   //数组大小
    cout<<sizeof(arr1[0])<<endl; //行大小
    cout<<sizeof(arr[0][0])<<endl;  //元素大小
    cout<<arr<<endl;   //二维数组的首地址
    cout<<&arr[0][1]<<endl; //输出某个元素的地址
    // cout<<sizeof(arr[0])<<endl; //输出数组中单行占用空间大小
    cout<<sizeof(arr)/sizeof(arr[0][0])<<endl;;  //输出数据元素个数
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;  ; //输出行
    cout<<sizeof(arr[0])/sizeof(arr[0][0])<<endl; //输出列


    return 0;
}
