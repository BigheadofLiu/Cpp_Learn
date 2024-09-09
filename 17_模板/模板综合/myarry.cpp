#include"myarry.hpp"
#include<iostream>
//打印数组元素
// template<typename T>
/* void print_arr(myarry<T> &arr){
    for(int i=0;i<arr.get_size();i++){
        
        cout<<arr[i]<<endl;
        

    }
} */
void print_arr(myarry<int> &arr){
    for(int i=0;i<arr.get_size();i++){
        cout<<arr[i]<<endl;
    }
}
//内置数据类型
void test01(){
    myarry<int> arr1(10); //普通构造
    for (int i = 0; i < arr1.get_capacity(); i++)
    {
        arr1.end_ins(i);
    }
    print_arr(arr1);
    cout<<arr1.get_size()<<endl;
    cout<<arr1.get_capacity()<<endl;
    cout<<"------------------------"<<endl;
    myarry<int> arr2(arr1); //拷贝构造
    arr2.end_del();
    print_arr(arr2);
    cout<<arr2.get_capacity()<<endl;
    cout<<arr2.get_size()<<endl;
}
//自定类型
class Person{
    public:
    Person(){
        //必不可少 用于初始化空对象
        
    }
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
    public:
    string name;
    int age;
};
void print_arr_person(myarry<Person> &arr){
    for(int i=0;i<arr.get_size();i++){
       cout<<arr[i].name<<" "<<arr[i].age<<endl;
    }
}
void test03(){
    myarry<Person> arr(10);
    Person p1("张三",18);
    Person p2("李四",19);
    Person p3("王五",20);
    Person p4("赵六",21);
    Person p5("钱七",22);
    Person p6("孙八",23);
    Person p7("周九",24);
    Person p8("吴十",25);
    arr.end_ins(p1);
    arr.end_ins(p2);
    arr.end_ins(p3);
    arr.end_ins(p4);
    arr.end_ins(p5);
    arr.end_ins(p6);
    arr.end_ins(p7);
    arr.end_ins(p8);
    print_arr_person(arr);
    cout<<arr.get_size()<<endl;
    cout<<arr.get_capacity()<<endl;
}
int main(){
    test01();
    test03();
    return 0;
}
