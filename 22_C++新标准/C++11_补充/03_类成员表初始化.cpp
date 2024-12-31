#include <iostream>
using namespace std;
class a{
public:
    a(int x,int y,int z):b(x),c(y),d(z){}

    //c++11允许非静态变量类内初始化
    int b{1};
    int c=2;
    int d=3;
};
int main(){
    a m(10,20,30);
    cout<<m.b<<" "<<m.c<<" "<<m.d<<endl;
}