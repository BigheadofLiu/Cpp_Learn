//找出1-500内的水仙花数
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
int a,b,c;
for(int i=100;i<1000;i++)
{
    a=i/100;  //百位
    b=(i/10)%10;  //十位
    c=i%10;   //个位
    // cout<<a<<endl;
    // cout<<b<<endl;
    // cout<<c<<endl;
    if(i==a*a*a+b*b*b+c*c*c){
    cout<<i<<endl;
    }
}
// i=398;
// a=i/100;//百位
// b=(i/10)%10;//十位
// c=i%10; //个位
// cout<<a<<endl;
// cout<<b<<endl;
// cout<<c<<endl;
return 0;
}