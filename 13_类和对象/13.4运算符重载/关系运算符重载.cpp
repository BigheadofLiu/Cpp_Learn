#include<iostream>  
using namespace std;
//关系运算符重载：== ！= >= <=
class person{
    public:
    person(int age){
        this->age=age;
    }

    bool operator==(person &p){
        if (this->age==p.age)
        {
            return true;
        }else{
            return false;
        }
    }

    bool operator!=(person &p){
        if (this->age!=p.age)
        {
            return true;
        }else{
            return false;
        }
    }

    // bool operator>(person p){
    //     if (this->age>p.age)
    //     {
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }

    //   bool operator<(person p){
    //     if (this->age<=p.age)
    //     {
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }

    private:
    int age;

};
void fun1(){
    person p1(20);
    person p2(20);
    if (p1==p2)
    {
        cout<<"相等";
        /* code */
    }
    else
    {
        cout<<"不相等";
    }   
    // cout<<"test"<<endl;
}
int main(){ 
     fun1();
    // system("pause");
}