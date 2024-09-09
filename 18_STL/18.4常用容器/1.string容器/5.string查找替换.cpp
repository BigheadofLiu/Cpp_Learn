/*string 查找和替换
*/
#include<iostream>
using namespace std;
void test(){
    string str1="我是丁真，你是芝士雪豹！我在无中生有，你在最高峰理塘！";
    int pos1=str1.find("芝士雪豹");
    if(!pos1){
        cout<<"未找到"<<endl;
    }else{
        cout<<"pos="<<pos1<<endl;
    }
    int pos2=str1.rfind("芝士雪豹");
    if(!pos2){
        cout<<"未找到"<<endl;
    }else{
        cout<<"pos="<<pos2<<endl;
    }
}
void test01(){
    string str1="我是丁真，你是芝士雪豹！我在无中生有，你在最高峰理塘！";
    str1.replace(1,5,"我是你爸爸！");
    cout<<str1<<endl;
}
int main(){
    test();
    test01();
}
