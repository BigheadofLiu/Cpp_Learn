#include"iostream"
#include"math.h"
#include<ctime>
using namespace std;
//��������Ϸ ʹ��whileǶ��if
int main(){
    srand(time(0));    //��ʼ����������ӣ���������α�����
    int a = rand() % 100 + 1; //�������1-100�ڵ�����
    cout<<a<<endl;
    int b;
    bool tag=true;
    while(tag){
    cout<<"enter your number"<<endl;
    cin>>b;
    if(b<a)
    {
        cout<<"��С��"<<endl;
        continue;
        /* code */
    }else if(b>a){
        cout<<"�´���"<<endl;
        continue;
        
    }else{
        cout<<"�¶���"<<endl;
        tag=false;
    }
    }
    return 0;
}