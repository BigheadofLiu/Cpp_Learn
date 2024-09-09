#include<iostream>
using namespace std;
/*拷贝构造函数的应用
1.用一个已创建的对象初始化另外一个对象（拷贝属性）
2.用于函数形参的值传递
3.以值返回的方式返回局部对象
*/
struct Student{
int id;
int score;
Student(int i,int s){
    id=i;
    score=s;
    cout<<"我是有参构造函数，我被调用了"<<endl;
}
Student(const Student &s){
    id=s.id;
    score=s.score;
    cout<<"我是拷贝构造函数，我被调用了"<<endl;
}
~Student(){
    cout<<"我是析构函数，我被调用了"<<endl;
    }
};
/*初始化对象*/
void func1(){
    Student s1(1,100);
    Student s2=s1;//调用拷贝构造函数 等价于Student s2=Student（s1）
    cout<<s2.id<<" "<<s2.score<<endl;
}

/*函数形参值传递*/
void func2(Student s){ 
    cout<<&s<<endl;  //输出s的地址
    cout<<s.id<<" "<<s.score<<"func2"<<endl;
}
void dowork2(){
Student s3(10,100);
cout<<&s3<<endl;
func2(s3);  //相当于 student s=student s3 拷贝出来一个副本
}

/*返回局部对象*/
Student func3(){
    Student s(3,30);
    cout<<&s<<endl;
    return s;  //在这个函数结束后 s对象就会释放掉 编译器会自动创建一个s的副本
}
void dowork3(){
Student s4=func3(); //调用拷贝构造函数
cout<<&s4<<endl;
cout<<s4.id<<" "<<s4.score<<endl;
}

int main(){
//    func1();

dowork2();

// func3();
// dowork3();

}
/*我是有参构造函数，我被调用了
0x61fe18
我是析构函数，我被调用了
我是有参构造函数，我被调用了
0x61fdc8
0x61fdc8
3 30
我是析构函数，我被调用了*/