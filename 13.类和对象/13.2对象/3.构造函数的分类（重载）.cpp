#include<iostream>
using namespace std;
/*构造函数的分类（重载）
1.有参构造-无参构造（默认构造）
2.普通构造-拷贝构造
*/
class student{
    public:
    //无参构造
    student(){
        cout<<"我是无参构造函数"<<endl;
    }
   
    //有参构造
    student(int a){
        cout<<"我是有参构造函数"<<endl;
    }

    //拷贝构造 语法：类名（const 类名 &对象名）
    student(const student &p1){
    age=p1.age;
    cout<<"我是拷贝构造函数"<<endl;
    }

    /*析构函数不能含有参数 不能发生重载*/
    // ~student(int a){
    //     cout<<"我是有参析构函数"<<endl;
    // }

     ~student(){
        cout<<"我是唯一的析构函数"<<endl;
    }

    // private:
    int age;
    string name;
};
/*无参构造函数的调用*/
void func1(){
    student st1;
    // student st1(); 错误写法 编译器会认为这是一个自定义的函数
}
/*有参构造函数的调用*/
void func2()
{ 
    /*1.括号法*/
    student st2(10);
    // student st3(st2); //error:并没有被执行  拷贝构造函数不能初始化匿名对象 所以拷贝构造函数要用显式或者隐式

    /*显式法*/
    student st4=student(10);
    student st5=student(st4);
    //student(10)单独写是匿名对象 当行结束 当行释放

    /*隐式法*/
    student stu6=10; //等价于student stu6(10)
    student stu7=stu6; 
    
}
int main(){
    // student stu1;//不指定参数 默认调用无参（默认）构造函数
    // stu1.age=18;
    // student stu2(10);
    // student stu3(stu1);
    // cout<<stu3.age<<endl; //对象属性拷贝成功
    // system("pause"); 
    // func1();
    func2();


}