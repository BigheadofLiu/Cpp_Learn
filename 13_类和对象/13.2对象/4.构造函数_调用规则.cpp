#include "iostream"
using namespace std;
/*构造函数的使用规则
1.默认情况下创建一个类 编译器会自动生成 
（1）默认构造函数（默认无参）
（2）默认拷贝构造函数（默认无参,对属性值进行拷贝）
（3）默认析构函数（默认无参）

2.如果定义了有参构造函数，则编译器不会自定生成默认构造（无参）函数，会提供拷贝构造函数
3.如果自定义了拷贝构造函数 其他构造函数均不会再提供
*/
class Person {

public:
//无参构造
// Person() {
//     cout << "无参构造函数" << endl;
// }
//有参构造

Person(int age) {
    this->age = age;
    cout << "有参构造函数" << endl;
}

//拷贝构造
Person(const Person &p) {
    this->age = p.age;
    cout << "拷贝构造函数" << endl;
}
//析构函数
~Person() {
    cout << "析构函数" << endl;
}
private:
    int age;
};
int main() {
    // Person p1;// 调用无参构造 如果类内定义了有参构造 调用失败
    Person p2(10);// 调用有参构造
    Person p3(p2);// 调用拷贝构造
}