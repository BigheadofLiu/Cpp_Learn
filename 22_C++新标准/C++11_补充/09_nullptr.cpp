#include "iostream"
using namespace std;
//NULL定义
//#ifndef NULL
//#ifdef __cplusplus
//#ifndef _WIN64
//#define NULL 0
//#else
//#define NULL 0LL
//#endif  /* W64 */
//#else
//#define NULL ((void *)0)
//#endif
//#endif
//旧版本中 NULL和0是等价的

using  namespace std;
void test(char* p){
    cout<<"test(char*)"<<endl;
}
void test(int p){
    cout<<"test(int p)"<<endl;
}

int main(){
//    auto a=NULL;
//    test(a); //NULL被解析为NULL OLL
//    // test(NULL); //Call to 'test' is ambiguous
//    test(250);
    test(250);
    test(nullptr); //调用char * 成功
}
//nullptr 无法隐式转换为整形，但是可以隐式匹配指针类型。
// 在 C++11 标准下，相比 NULL 和 0，使用 nullptr
// 初始化空指针可以令我们编写的程序更加健壮。
