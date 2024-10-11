//
// Created by ZYB on 2024/10/11.
//

#include "order.h"
void login_in(string file_name,int type){
    person *person=NULL;
    fstream fst1(file_name,ios::in);
    if(!fst1.is_open()){
        std::cout<<"文件打开失败"<<endl;
        fst1.close();
        return;
    }
    //用于接收输入数据
    int id=0;
    string name;
    string pwd;

    if (type==1){
        cout<<"请输入学号："<<endl;
        cin>>id;
    }else if(type==2){
        cout<<"请输入职工编号："<<endl;
        cin>>id;
    }
    cout<<"请输入用户名："<<endl;
    cin>>name;
    cout<<"请输入密码："<<endl;
    cin>>pwd;

    if(type==1){
        //学生身份认证
        //用于获取来自文件的数据
        int s_id;
        string s_name;
        string s_pwd;
        while(fst1>>s_id&&fst1>>s_name&&fst1>>s_pwd){
            if(s_id==id&&s_name==name&&s_pwd==pwd){
                cout<<"身份验证成功"<<endl;
                system("pause >nul");
                system("cls");
                person=new student(id,name,pwd);
                return;
            }
        }


    }else if(type==2){
        //教职工身份认证
        int s_id;
        string s_name;
        string s_pwd;
        while(fst1>>s_id&&fst1>>s_name&&fst1>>s_pwd){
            if(s_id==id&&s_name==name&&s_pwd==pwd){
                cout<<"身份验证成功"<<endl;
                system("pause >nul");
                system("cls");
                person=new teacher(id,name,pwd);
                return;
            }
        }
    }else if(type==3){
        //管理员身份认证
        // int s_id;
        string s_name;
        string s_pwd;
        while(fst1>>s_name&&fst1>>s_pwd){
            if(s_name==name&&s_pwd==pwd){
                cout<<"身份验证成功"<<endl;
                system("pause >nul");
                system("cls");
                person=new admin(id,name,pwd);
                return;
            }
        }

    }
    cout<<"验证登录失败"<<endl;
    system("pause >nul");
    system("cls");
    return;

}

