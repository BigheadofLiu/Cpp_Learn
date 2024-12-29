#include "cassert"
#include <iostream>
using namespace std;

int check_num( int const &a){
    assert(a>10);  //动态断言，程序运行时判断  输入小于10的数会引发程序中断
    cout<<a<<endl;
}
void check_sys(){
    static_assert(sizeof(long) == 4,"告警：非64位系统！");
    cout<<"64 bit (int*) size:"<<sizeof(int*)<<endl;
    cout<<"64 bit (int) size:"<<sizeof(int)<<endl;
    cout<<"64 bit (long) size:"<<sizeof(long)<<endl;
}
int main(){
//    int a;
//    cin>>a;
//    check_num(a);
check_sys();
}