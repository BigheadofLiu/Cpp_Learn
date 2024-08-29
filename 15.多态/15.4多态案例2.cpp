#include<iostream>  
using namespace std;
class base_drink{
    public:
    virtual void step_1()=0;
    virtual void step_2()=0;
    virtual void step_3()=0;
    virtual void step_4()=0;
    virtual void dowork()=0;

};
class kunkun :public base_drink{
     void step_1(){
    cout<<"唱"<<endl;
     }
     void step_2(){
    cout<<"跳"<<endl;
     }
     void step_3(){
    cout<<"rap"<<endl;
     }
     void step_4(){
    cout<<"篮球"<<endl;
     }

     void dowork(){
        step_1();
        step_2();
        step_3();
        step_4();
     }

};
class dingzhen : public base_drink{
void step_1(){
    cout<<"一眼丁真，鉴定为纯纯的智障"<<endl;
     }
     void step_2(){
    cout<<"一眼丁真，鉴定为纯纯的牛马"<<endl;
     }
     void step_3(){
    cout<<"一眼丁真，鉴定为纯纯的王八"<<endl;
     }
     void step_4(){
    cout<<"一眼丁真，鉴定为纯纯的犊子"<<endl;
     }
    void dowork(){
        step_1();
        step_2();
        step_3();
        step_4();
     }
};
void dowork(base_drink * b){
b->dowork();
delete b; //防止出现野指针
}
void test(){
    dowork(new kunkun);
    dowork(new dingzhen);

};
int main(){
    test();

}
