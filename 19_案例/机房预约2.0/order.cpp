//
// Created by ZYB on 2024/10/24.
//

#include "order.h"
using namespace std;

void divide_string(string str,map<string,string> &m)  {
    string key,value;
    int pos= str.find(":");
    if(pos!=-1){
        key=str.substr(0,pos);
        value=str.substr(pos+1,str.length()-1);
        m.insert(make_pair(key,value));
    }
}
order::order() {
    fstream  fst;
    //读取预定记录
    fst.open(ORDER_FILE,ios::in);
    string time_week,time_day,room_id,state,stu_id,stu_name;
    this->order_num=0;
    while (fst>>time_week&&fst>>time_day&&fst>>room_id&&fst>>stu_id&&fst>>stu_name&&fst>>state){
        map<string,string> m;
        divide_string(time_week,m);
        divide_string(time_day,m);
        divide_string(room_id,m);
        divide_string(stu_id,m);
        divide_string(stu_name,m);
        divide_string(state,m);
        this->order_map.insert(make_pair(++this->order_num,m));
//        this->order_num++;
    }
    fst.close();
}

void order::update_order() {
    if (this->order_num==0){
        return;
    }
    fstream fst;
    //将本地map容器写入order文件
    fst.open(ORDER_FILE,ios::out|ios::trunc);
    if (!fst.is_open()){
        return;
    }
    for(auto i=1;i<=this->order_num;i++){
        fst<<"week_time:"<<this->order_map[i]["week_time"]<<" ";
        fst<<"week_day:"<<this->order_map[i]["week_day"]<<" ";
        fst<<"room_id:"<<this->order_map[i]["room_id"]<<" ";
        fst<<"stu_id:"<<this->order_map[i]["stu_id"]<<" ";
        fst<<"stu_name:"<<this->order_map[i]["stu_name"]<<" ";
        fst<<"state:"<<this->order_map[i]["state"]<<endl;
    }
    fst.close();
}
