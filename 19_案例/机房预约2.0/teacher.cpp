//
// Created by ZYB on 2024/10/22.
//

#include "teacher.h"
#include <vector>

teacher::teacher() {

}

teacher::teacher(int t_id, string name, string pwd) {
    this->t_id=t_id;
    this->name=name;
    this->password=pwd;
}

void teacher::main_menu() {
    cout<<"欢迎"+this->name<<"老师进入系统"<<endl;
    cout<<"============================"<<endl;
    cout<<"选择需要进行的操作"<<endl;
    cout<<"      1.查看预约      "<<endl;
    cout<<"                    "<<endl;
    cout<<"      2.审核预约      "<<endl;
    cout<<"                    "<<endl;
    cout<<"      3.退出登录      "<<endl;
    cout<<"                    "<<endl;
    cout<<"============================"<<endl;
    cout<<"输入功能序号："<<endl;
}

void teacher::show_all_order() {
    order all_order;
    if (all_order.order_num==0){
        cout<<"当前无预约记录"<<endl;
        return;
    }
    for(int i=0;i<=all_order.order_num;i++){
        cout<<"预约时间（周）:"<<all_order.order_map[i]["time_week"]<<" ";
        cout<<"预约时间（天）:"<<(all_order.order_map[i]["time_day"]=="1" ? "上午":"下午")<<" ";
        cout<<"预约人（姓名）："<<all_order.order_map[i]["stu_name"]<<" ";
        cout<<"预约人（ID）:"<<all_order.order_map[i]["stu_id"]<<" ";
        string status;
        if (all_order.order_map[i]["status"]=="1"){
            status+="待审核";
        }else if(all_order.order_map[i]["status"]=="2"){
            status+="已审核";
        }else if(all_order.order_map[i]["status"]=="3"){
            status+="审核未通过";
        }else if (all_order.order_map[i]["status"]=="4"){
            status+="已取消";
        }
        cout<<status<<endl;
    }
    system("pause");
    system("cls");
    return;
}

void teacher::valid_order() {
    order valid_order;
    if (valid_order.order_num == 0) {
        cout << "当前无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    int flag=0;
    int index=1;
    int select;
    vector<int> v;
    cout<<"待审核预约记录如下:"<<endl;
    for(auto i=1;i<=valid_order.order_num;i++) {
        if (valid_order.order_map[i]["status"] == "1") {
            flag = 1;
            v.push_back(i);
            cout << "第" << index++ << "条记录" << endl;
            std::cout << "预约时间：" << valid_order.order_map[i]["time_week"];
            std::cout << "预约时间段：" << valid_order.order_map[i]["time_day"];
            std::cout << "预约人id：" << valid_order.order_map[i]["stu_id"];
            std::cout << "预约人姓名：" << valid_order.order_map[i]["stu_name"];
            std::cout << "预约机房id：" << valid_order.order_map[i]["room_id"];
            /*std::cout<<"预约状态："<<my_order.order_map[i]["state"];*/
            string status = "状态:审核中";
            std::cout << status << endl;
        }
        if (flag == 0) {
            cout << "未找到未审核的预约记录" << endl;
            system("pause >nul");
            system("cls");
            return;
        }
    }
    while(true){
        cout<<"输入要审核的记录序号"<<endl;
        cout<<"0.取消审核"<<endl;
        cin>>select;
        if (select == 0) {
            system("cls");
            break;
        }
        else if(select>0&&select<=index){
            int choice;
            while(true) {
                cout << "输入审核结果" << endl;
                cout << "1.审核通过" << endl;
                cout << "2.审核不通过" << endl;
                cin >> choice;
                if (choice == 1) {
                    valid_order.order_map[v[select - 1]]["status"] = "2";  //状态更改为已审核
                    valid_order.update_order(); //更新预约记录
                    cout << "审核成功" << endl;
                    break;
                } else if (choice == 2) {
                    valid_order.order_map[v[select - 1]]["status"] = "3";  //状态更改为审核未通过
                    valid_order.update_order(); //更新预约记录
                    cout << "审核成功" << endl;
                    break;
                } else {
                    cout << "输入有误，请重新输入" << endl;
                    system("pause >nul");
                    system("cls");
                    continue;
                }
            }
        }else{
            cout<<"输入有误，请重新输入"<<endl;
            system("pause >nul");
            system("cls");
            continue;
        }
    }
    system("pause >nul");
    system("cls");
    return;
}


