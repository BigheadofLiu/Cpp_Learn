//
// Created by ZYB on 2024/10/22.
//

#include <fstream>
#include "student.h"

student::student() {

}

student::student(int id,string name, string password) {
    this->s_id=id;
    this->name=name;
    this->password=password;
    this->init_computerRoom();
}
void student::main_menu() {
    {
        cout << "欢迎学生： " << this->name << "登陆！" << endl;
        cout << "\t\t ----------------------------------\n";
        cout << "\t\t |                                |\n";
        cout << "\t\t |           1.申请预约           |\n";
        cout << "\t\t |                                |\n";
        cout << "\t\t |           2.查看自身           |\n";
        cout << "\t\t |                                |\n";
        cout << "\t\t |           3.查看所有           |\n";
        cout << "\t\t |                                |\n";
        cout << "\t\t |           4.取消预约           |\n";
        cout << "\t\t |                                |\n";
        cout << "\t\t |           0.注销登陆           |\n";
        cout << "\t\t |                                |\n";
        cout << "\t\t ----------------------------------\n";
        cout << "请输入您的选择" << endl;
    }
}

void student::apply_order() {
    cout<<"==============================="<<endl;
    cout<<"开放预约日为周一至周五"<<endl;
    cout<<"请选择需要预约的时间"<<endl;
    cout<<"1.周一"<<endl;
    cout<<"2.周二"<<endl;
    cout<<"3.周三"<<endl;
    cout<<"4.周四"<<endl;
    cout<<"5.周五"<<endl;
    cout<<"==============================="<<endl;
    int time_week;
    int time_day;
    int room_id;
    while(true) {
        cin>>time_week;
        if(time_week>=1&&time_week<=5){
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;
    }
    cout<<"请选择需要的时间"<<endl;
    cout<<"1.上午"<<endl;
    cout<<"2.下午"<<endl;
    while(true) {
        cin>>time_day;
        if(time_day==1||time_day==2){
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;
    }
    cout<<"请选择机房"<<endl;
    for(int i=0;i<v_computer.size();i++){
        cout<<v_computer[i].com_id<<"号机房容量为:"<<v_computer[i].com_max_num<<endl;
    }
    while (true){
        cin>>room_id;
        if (room_id>=1&&room_id<=v_computer.size()){
            break;
        }
        cout<<"输入有误重新选择机房！"<<endl;
    }
    cout<<"预约成功，等待审核！"<<endl;

    fstream fst1;
    //写入预约文件
    fst1.open(ORDER_FILE,ios::in|ios::app);
    fst1<<"time_week:"<<time_week<<" ";
    fst1<<"time_day:"<<time_day<<" ";
    fst1<<"stu_id:"<<this->s_id<<" ";
    fst1<<"stu_name:"<<this->name<<" ";
    fst1<<"room_id:"<<room_id<<" ";
    fst1<<"state:"<<1<<endl;
    fst1.close();
    system("pause >nul");
    system("cls");
}

void student::cancel_order() {
    order cancel_order;
    if (cancel_order.order_num == 0) {
        cout << "当前无预约记录！" << endl;
        system("pause >nul");
        system("cls");
        return;
    }
    bool flag = 0;
    vector<int> cancel_v;
    int index = 1;
    cout << "以下已预约或已审核记录可取消：" << endl;
    for (int i = 0; i < cancel_order.order_num; i++) {
        if (atoi(cancel_order.order_map[i]["stu_id"].c_str()) == this->s_id) {
            if (cancel_order.order_map[i]["status"] == "1" || cancel_order.order_map[i]["status"] == "2") {
                flag = 1;
                cancel_v.push_back(i);
                cout << index++ << ":" << endl;
                cout << "预约时间（周）:" << cancel_order.order_map[i]["time_week"];
                cout << "预约时间（天）:" << (cancel_order.order_map[i]["time_day"] == "1" ? "上午" : "下午");
                cout << "机房号：" << cancel_order.order_map[i]["room_id"];
                string status = "状态：";
                if (cancel_order.order_map[i][status] == "1") {
                    status += "审核中";
                } else {
                    status += "已预约";
                }
                cout << status << endl;
            }
        }
    }
    if (flag == 0) {
        cout << "当前暂无可取消预约" << endl;
        system("pause >nul");
        system("cls");
        return;
    }
    int select;
    while (true) {
        cout << "输入需要取消的预约编号：" << endl;
        cout << "输入0取消本次操作：" << endl;
        cin >> select;
        if (select == 0) {
            cout << "本次操作已取消" << endl;
            break;
        }else if (select>0&&select<index){
            cancel_order.order_map[cancel_v[select-1]]["status"]="0";
            cancel_order.update_order();
            cout<<"取消成功！"<<endl;
            break;
        }else{
            cout<<"输入有误，重新选择需要取消的预约"<<endl;
            system("pause >nul");
            system("cls");
            continue;
        }
    }
    system("pause >nul");
    system("cls");
    return;
}

void student::show_my_order() {
    order my_order;
    if(my_order.order_num==0){
        cout<<"当前无预约记录"<<endl;
        return;
    }
    int flag;
    for(auto i=1;i<=my_order.order_num;i++){
        if(atoi(my_order.order_map[i]["stu_id"].c_str())==this->s_id){
            flag=1;
            std::cout<<"预约时间："<<my_order.order_map[i]["time_week"];
            std::cout<<"预约时间段："<<my_order.order_map[i]["time_day"];
            std::cout<<"预约人id："<<my_order.order_map[i]["stu_id"];
            std::cout<<"预约人姓名："<<my_order.order_map[i]["stu_name"];
            std::cout<<"预约机房id："<<my_order.order_map[i]["room_id"];
            /*std::cout<<"预约状态："<<my_order.order_map[i]["state"];*/
            string status="状态:";
            if(my_order.order_map[i]["state"]=="1"){
                status+="审核中";
            }else if(my_order.order_map[i]["state"]=="2"){
                status+="已审核，预约成功";
            }else if(my_order.order_map[i]["state"]=="3"){
                status+="已取消";
            }else if(my_order.order_map[i]["state"]=="4"){
                status+="审核失败，已拒绝";
            }
            std::cout<<status<<endl;
        }
        if(flag==0){
            cout<<"未找到"<<this->name<<"的预约记录"<<endl;
            system("pause >nul");
            system("cls");
            return;
        }
    }
}
void student::show_all_order() {
    order all_order;
    if(all_order.order_num==0){
        cout<<"当前无预约记录"<<endl;
        system("pause >nul");
        system("cls");
        return;
    }
    for(auto i=1;i<=all_order.order_num;i++){
        cout<<"第"<<i<<"条预约记录"<<endl;
        std::cout<<"预约时间："<<all_order.order_map[i]["time_week"];
        std::cout<<"预约时间段："<<all_order.order_map[i]["time_day"];
        std::cout<<"预约人id："<<all_order.order_map[i]["stu_id"];
        std::cout<<"预约人姓名："<<all_order.order_map[i]["stu_name"];
        std::cout<<"预约机房id："<<all_order.order_map[i]["room_id"];
        string statue="状态:";
        if(all_order.order_map[i]["state"]=="1"){
            statue+="审核中";
        }
        else if(all_order.order_map[i]["state"]=="2"){
            statue+="已审核，预约成功";
        }
        else if(all_order.order_map[i]["state"]=="3"){
            statue+="已取消";
        }
        else if(all_order.order_map[i]["state"]=="4"){
            statue+="审核失败，已拒绝";
        }
        std::cout<<statue<<endl;
    }
}

void student::init_computerRoom() {
    fstream fst;
    fst.open(COMPUTER_FILE,ios::in);
    computer_room com1;
    while(fst>>com1.com_id && fst>>com1.com_max_num){
        this->v_computer.push_back(com1);
    }
    fst.close();
}
