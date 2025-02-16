//
// Created by ZYB on 2025/2/6.
//
#include "iostream"
#include "vector"
using namespace std;
// 1.move 使用std::move方法可以将左值转换为右值。
// 使用这个函数并不能移动任何东西，而是和移动构造函数一样都具有移动语义，
// 将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存拷贝。
// 拷贝构造--深拷贝
// 移动构造--资源转移
// 浅拷贝--仅复制指针
class A{
public:
    A(){};
};
void test01(){
    A a;
//    A&& b=a; //error:Rvalue reference to type 'A' cannot bind to lvalue of type 'A'
    A&& c=move(a); //success
}

void test02(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
//    vector<int> v2=v1; //开销大（拷贝构造：深拷贝）
    vector<int> v3= std::move(v1); //开销小：（移动构造函数） 移动之后v1还存在吗？
    cout<<v3.size()<<endl; // 10
    cout<<v1.size()<<endl; // 0
    for(auto i:v3){
        cout<<i<<endl;
    }//0

    for(auto i:v1){
    cout<<i<<endl;
    }//0~9
}

/*std::forward<T>(t);
 * 使用forward用于保留参数的（左/右）值属性
 * 函数原型：
 * template <typename T>
 * T&& forward(T& x) {  // x 是左值
 * return static_cast<T&&>(x);
   }
   当T为左值引用类型时，t将被转换为T类型的左值
   当T不是左值引用类型时，t将被转换为T类型的右值

   std::forward<T>(x) 用于完美转发，保持左值/右值的原始属性。
   std::move(x) 强制变为右值，适用于不再使用的对象。
   */
template <class T>
void get_vaule(T&){
cout<<"l vaule"<<endl;
}

template <class T>
void get_vaule(T&&){
cout<<"r value"<<endl;
}
template <class T>
void fun1(T&& t){
//    get_vaule(t);
    get_vaule(std::forward<T>(t)); //用于保留参数t的（左/右）值属性
}
void test03(){
    int a=10;
    int&& b=20;
    fun1(1);   // l vaule
    fun1(a);  // l vaule
    fun1(b);  // l vaule
    fun1(move(b)); //l vaule  why?

//    fun1(std::forward<>())
}
int main(){
//    test02();
test03();
}