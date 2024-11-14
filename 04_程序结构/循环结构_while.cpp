#include"iostream"
#include"math.h"
#include<ctime>
using namespace std;
//猜数字游戏 使用while嵌套if
int main(){
    srand(time(0));    //初始化随机数种子，避免生成伪随机数
    int a = rand() % 100 + 1; //随机生成1-100内的数字
    cout<<a<<endl;
    int b;
    bool tag=true;
    while(tag){
    cout<<"enter your number"<<endl;
    cin>>b;
    if(b<a)
    {
        cout<<"猜小了"<<endl;
        continue;
        /* code */
    }else if(b>a){
        cout<<"猜大了"<<endl;
        continue;
        
    }else{
        cout<<"猜对了"<<endl;
        tag=false;
    }
    }
    return 0;
}