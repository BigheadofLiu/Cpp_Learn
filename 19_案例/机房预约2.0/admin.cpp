//
// Created by ZYB on 2024/10/23.
//

#include "admin.h"
void print_order_student(student& s){
    cout<<"学号："<<s.s_id<<" "<<" 姓名："<<s.name<<" "<<" 密码："<<s.password<<endl;
}

void print_order_teacher(teacher& t){
    cout<<"工号："<<t.t_id<<" "<<" 姓名："<<t.name<<" "<<"密码："<<t.password<<endl;
}
void print_computer_room(computer_room &c){
    cout<<"机房编号："<<c.com_id<<"最大容量为："<<c.com_max_num<<endl;
}
admin::admin() {
    /*this->init_computer();*/ //初始化机房信息
    //如果写了有参构造函数，默认构造函数不会执行
}

admin::admin(string name, string pwd) {
    this->name=name;
    this->password=pwd;
    this->init_vector();
    this->init_computer();
}

void admin::main_menu() {
    cout << "欢迎管理员： "<< this->name<<"登陆！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |           1.添加账号           |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |           2.查看账号           |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |           3.查看机房           |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |           4.清空预约           |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t |           0.注销登陆           |\n";
    cout << "\t\t |                                |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请输入您的选择" << endl;
}

void admin::add_order_id() {
    cout << "==请输入添加账号的类型==" << endl;
    cout<<"              "<<endl;
    cout << "1、添  加  学  生" << endl;
    cout<<"              "<<endl;
    cout << "2、添  加  老  师" << endl;
    cout<<"              "<<endl;
    cout << "====================" << endl;
    int select=0;
    string file_name;
    int id;
    string name;
    string psd;
    fstream fst1;
    string tip;
    string errorTip;
    cin>>select;
    if(select==1){
        file_name=STUDENT_FILE;
        tip = "请输入学号： ";
        errorTip = "学号重复，请重新输入";
    }else{
        file_name=TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工号重复，请重新输入";
    }
    fst1.open(file_name,ios::out|ios::app);
    if(!fst1.is_open()){
        cout<<"文件打开失败"<<endl;
        fst1.close();
        return;
    }
    cout<<tip<<endl;
    while (true){
        cin>>id;
        /*bool ret=admin::admin::check_order(id,select);*/
        bool ret=this->check_order(id,select);
        if(ret){
            cout<<errorTip<<endl;
        }else
        {
            break;
        }
    }
    cout<<"请输入姓名："<<endl;
    cin>>name;
    cout<<"请输入密码"<<endl;
    cin>>psd;
    fst1<<id<<" "<<name<<" "<<psd<<endl;//写入文件
    cout<<"添加成功"<<endl;
    this->init_vector(); //更新容器
    system("pause >nul");
    system("cls");
    fst1.close();
}


void admin::show_order() {
    std::cout<<"----   查看预约    ----"<<endl;
    std::cout << "1、查看所有学生" << endl;
    std::cout << "2、查看所有老师" << endl;
    std::cout<<"---------------------"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        cout<<"所有学生信息如下："<<endl;
        /* for(auto i=v_stu.begin();i!=v_stu.end();i++){
            print_order_student(*i);
        } */
        for_each(v_stu.begin(),v_stu.end(),print_order_student);
    }else{
        cout<<"所有老师信息如下："<<endl;
        /* for(auto i=v_tea.begin();i!=v_tea.end();i++){
            print_order_teacher(*i);
        } */
        for_each(v_tea.begin(),v_tea.end(),print_order_teacher);
    }
}

void admin::clear_order_file() {
    fstream fst;
    fst.open(ORDER_FILE,ios ::out|ios::trunc);
    fst.close();
    cout<<"所有预约记录已清除"<<endl;
    system("pause >nul");
    system("cls");
}

bool admin::check_order(int id, int type) {
    if(type==1){
        for(auto it=v_stu.begin();it!=v_stu.end();it++){
            if(it->s_id==id){
                return true;
            }
        }
        return false;
    }else{
        for(auto it=v_tea.begin();it!=v_tea.end();it++){
            if(it->t_id==id){
                return true;
            }
        }
        return false;
    }
}
void admin::show_computer_room() {
    cout<<"====    机房信息如下    ===="<<endl;
    cout<<"机房数量为："<<v_computer.size()<<endl;
    for_each(v_computer.begin(),v_computer.end(),print_computer_room);
    cout<<"=========================="<<endl;
    system("pause >nul");
    system("cls");
}

void admin::init_vector() {
    fstream fst2;
    fst2.open(STUDENT_FILE,ios::in);
    if(!fst2.is_open()){
        cout<<"文件读取失败"<<endl;
        fst2.close();
        return;
    }
    v_stu.clear();
    student s1;
    while(fst2>>s1.s_id&&fst2>>s1.name&&fst2>>s1.password){
        v_stu.push_back(s1);
    }
    cout<<"当前学生数量为："<<v_stu.size()<<endl;
    fst2.close();

    fst2.open(TEACHER_FILE,ios::in);
    if(!fst2.is_open()){
        cout<<"文件读取失败"<<endl;
        fst2.close();
        return;
    }
    this->v_tea.clear();
    teacher t1;
    while(fst2>>t1.t_id&&fst2>>t1.name&&fst2>>t1.password){
        this->v_tea.push_back(t1);
    }
    cout<<"当前教师数量为："<<v_tea.size()<<endl;
    fst2.close();
}

void admin::init_computer() {
    fstream fst;
    fst.open(COMPUTER_FILE,ios::in);
    if(!fst.is_open()){
        cout<<"文件打开失败"<<endl;
        fst.close();
        return;
    }
    this->v_computer.clear();
    computer_room com{};
    while(fst>>com.com_id&&fst>>com.com_max_num){
        v_computer.push_back(com);
    }
    /*cout<<"当前机房数量为："<<v_computer.size()<<endl;*/
    fst.close();
    }


