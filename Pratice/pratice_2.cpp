//
// Created by ZYB on 2025/3/25.
//
//结构体案例2复习
#include "iostream"
#include<string>
struct human{
    std::string name;
    int damge_power;
};
void print_human(human*,int);
void bubble_sort(human*,int);
int main(){
    human h1[4]={
            {"刘备",80},
            {"关羽",99},
            {"吕布",100},
            {"貂蝉",66}
            };
    int len=std::size(h1);
    print_human(h1,len);
    bubble_sort(h1,len);
    print_human(h1,len);
    }

void print_human(human *h,int len){
    for(int i=0;i<len;i++){
        std::cout<<"name:"<<h[i].name<<"damge:"<<h[i].damge_power<<std::endl;
    }
    std::cout<<"==================================================="<<std::endl;
}
void bubble_sort(human *h,int len){
for(int i=0;i<len-1;i++){  //比较趟数
    for(int k=0;k<len-1-i;k++){
        if(h[k].damge_power>h[k+1].damge_power){
            human hum_temp;
            hum_temp=h[k];
            h[k]=h[k+1];
            h[k+1]=hum_temp;
        }
    }
}
}