#include<iostream>
using namespace std;
#include<string.h>
#include<ctime>
struct human
{
   string name;
   int damge;
    /* data */
};
void printf_h(human *hero,int len );
void bubblesort(human *hero,int len);
int main(){
    struct human hero[4]={
        {"关羽",90},
        {"吕布",100},
        {"张飞",80},
        {"司马懿",60},
    };
    int len=sizeof(hero)/sizeof(hero[0]);
    bubblesort(hero,len);
    printf_h(hero,len);



}
void bubblesort(human *hero,int len){

    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(hero[j].damge<hero[j+1].damge){
                human temp;  //创建临时结构体变量 用于临时存储
                temp=hero[j];
                hero[j]=hero[j+1];
                hero[j+1]=temp;
            }
        }
    }
}
void printf_h(human *hero,int len ){
    for(int i=0;i<len;i++){
        cout<<"名字:"<<hero[i].name<<"\t"<< "攻击力:"<<hero[i].damge<<endl;
    }
}
        
