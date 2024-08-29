#include<iostream>
using namespace std;
//打印乘法口诀
int main()
{
// for(int i=1;i<=9;i++)  //行
// {
//     for(int j=1;j<=i;j++)  //列
//     {
//     cout<<j<<"*"<<i<<"="<<i*j<<"\t";
//     }
//     cout<<endl;
// }
for (int i = 1; i <=9; i++)
{
    for (int j = 1; j <= i; j++)
    {
        cout << j << "*" << i << "=" << i * j << "\t";
        /* code */
    }
    cout << endl;
    
    /* code */
}

return 0;
}