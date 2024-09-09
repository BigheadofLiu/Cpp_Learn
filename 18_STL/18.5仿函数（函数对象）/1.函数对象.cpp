#include<string>
using namespace std;
#include<iostream>
class MyAdd{
    public:
    int operator()(int a,int b){
        return a+b;
    }
};
/**1.函数对象在使用时，可以像普通函数一样 有参数有返回值 */
void test01(){
    MyAdd myadd;
    cout<<myadd(10,20)<<endl;
}
class MyPrint{
    public:
    MyPrint(){
        count=0;
    }
    void operator()(string test){
        cout<<test<<endl;
        count++;
    }
    int count;  //2.函数对象内部可以有自己的参数
};
void test02(){
    MyPrint my;
    my("hello world");
    my("hello world");
    my("hello world");
    my("hello world");
    cout<<my.count<<endl;
}   
/*函数对象可以作为参数传递*/
void Do_Print(MyPrint &mp,string test){
    mp(test);
}
void test03(){
    MyPrint mp1;
    Do_Print(mp1,"Hello C++");
}
int main(){
    // test01();
    // test02();
    test03();
}
