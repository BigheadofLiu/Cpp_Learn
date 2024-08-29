#include"iostream"
using namespace std;
#include"string.h"
#define MAX_SIZE 1000   //define 的数据后面不需要跟 ; 不然会报错
#pragma execution_character_set("utf-8")  

struct person{
	string p_name;
	int p_sex;
	int p_age;
	long long p_number;
    string p_address;
};
struct person_manager{
    person p_list[MAX_SIZE]; // 
    int p_size;

};
void showmenu();
void addperson(person_manager *);
void showperson(person_manager *);
void deleteperson(person_manager *);
void modifyperson(person_manager *);
void searchperson(person_manager *);
int is_exist(person_manager *,string);
void delete_all_person(person_manager *);


int main(){
    int select=0;
    person_manager pm;
    pm.p_size=0; 

    while (true)
    {
    showmenu();
    cin>>select;
      //初始化数量

    switch(select){
        case 1:addperson(&pm);  break;
        case 2:showperson(&pm); break;
        case 3:deleteperson(&pm);  break;
        case 4:modifyperson(&pm);  break;
        case 5:searchperson(&pm);  break;    
        case 6:delete_all_person(&pm);  break;
        case 0:cout<<"退出通讯录系统"<<endl;
        cout<<"按任意键退出"<<endl;
        system("pause >nul");
        return 0;break;
        default:system("cls");cout<<"输入有误，重新输入！"<<endl;
        break;
}
}
}
void showmenu(){
    system("color 25");
    cout<<"*********************************************"<<endl;
    cout<<"************欢迎使用通讯录管理系统***********"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*************1.添加联系人********************"<<endl;
    cout<<"*************2.显示联系人********************"<<endl;
    cout<<"*************3.删除联系人********************"<<endl;
    cout<<"*************4.修改联系人********************"<<endl;    
    cout<<"*************5.查询联系人********************"<<endl;   
    cout<<"*************6.清空联系人********************"<<endl;
    cout<<"*************0.退出系统**********************"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"请选择功能：";
}
void addperson(person_manager *pm){
    system("cls");
    if (pm->p_size==MAX_SIZE)
    {
        cout<<"通讯录已满，无法添加"<<endl;
        return;
       
    }else{
    string name="";
    cout<<"请输入名字："<<endl;
    cin>>name;
    // cin >> pm->p_list[pm->p_size]->name;  //无法直接cin结构体变量
    pm->p_list[pm->p_size].p_name=name;
    system("cls");

    cout<<"请输入性别："<<endl;
    cout<<"1.男"<<endl;
    cout<<"2.女"<<endl;
    int sex=0;
    while (true)
    {
    cin>>sex;
    if (sex==1||sex==2)
    {
        pm->p_list[pm->p_size].p_sex=sex;
        break;
    }else{
        cout<<"输入错误，请重新输入"<<endl;
        // continue;        
    }
   

    }
    system("cls");

    int age=0;
    cout<<"请输入年龄："<<endl;
    cin>>age;
    pm->p_list[pm->p_size].p_age=age;
    system("cls");

    long long number=0;
    cout<<"请输入电话号码："<<endl;
    cin>>number;
    pm->p_list[pm->p_size].p_number=number;
    system("cls");

    string addr="";
    cout<<"请输入通讯地址："<<endl;
    cin>>addr;
    pm->p_list[pm->p_size].p_address=addr;
    system("cls");

    pm->p_size++;
    
    }

    cout<<"添加成功"<<endl;
    cout<<"按任意键退出"<<endl;
    system("pause >nul");
    system("cls");
}
void showperson(person_manager *pm){
    // cout<<pm->p_size<<endl;
    while (pm->p_size==0)
    {
        cout<<"还没有联系人，请添加后查看！";
        cout<<"按任意键退出"<<endl;
        system("pause >nul");
        system("cls");
        return;
        // break;
        /* code */
        
    }
    // cout<<"序号"<<"\t|"<<"姓名"<<"\t|"<<"性别    "<<"\t|"<<"年龄    "<<"\t|"<<"电话    "<<"\t|"<<"地址    "<<endl;
    for (int i = 0; i < pm->p_size; i++)
    {
        // cout<<"第"<<i+1<<"个联系人信息如下："<<endl;
        cout<<"序号："<<i+1<<"\t|"<<"姓名:"<<pm->p_list[i].p_name<<"\t|"<<"性别："<<(pm->p_list[i].p_sex==1?"男":"女")<<"\t|"<<"年龄："<<pm->p_list[i].p_age<<"\t|"<<"电话:"<<pm->p_list[i].p_number<<"\t|"<<"地址:"<<pm->p_list[i].p_address<<"\t|"<<endl;
        // pm->p_size++;        
        /* code */
        //注意三目运算符的应用  (条件1?结果1:结果2) 用()括起来！！！
    }
    cout<<"全部联系人信息已显示"<<endl;
    cout<<"按任意键退出"<<endl;
    system("pause >nul");
    system("cls");
    
    
    
}
int isexist(person_manager *pm,string name){
   
    for(int i=0;i<pm->p_size;i++){
        if(pm->p_list[i].p_name==name){
            return i;
            break;
        }
        }
    // cout<<"查无此人"<<endl;
    return -1;
            
        }

void deleteperson(person_manager *pm){
    string name1;
    cout<<"请输入要删除的联系人姓名:"<<endl;
    cin>>name1;
    int i=isexist(pm,name1);
    if(i==-1){
        cout<<"查无此人"<<endl;
        system("pause >nul");
        system("cls");
        return;
    }
    for(int j=i;j<pm->p_size-1;j++){
        pm->p_list[j]=pm->p_list[j+1];
    }
    pm->p_size--;
    cout<<"删除成功"<<endl;
    system("pause >nul");
    system("cls");
}
void modifyperson(){}
void searchperson(person_manager *pm){
    string name2;
    cout<<"请选择需要查找的联系人名字"<<endl;
    cin>>name2;
    for (int i = 0; i < pm->p_size; i++)
    {
        if (pm->p_list[i].p_name==name2)
        {
            cout<<"查询到以下信息："<<endl;
            cout<<"序号："<<i+1<<"\t|"<<"姓名:"<<pm->p_list[i].p_name<<"\t|"<<"性别："<<(pm->p_list[i].p_sex==1?"男":"女")<<"\t|"<<"年龄："<<pm->p_list[i].p_age<<"\t|"<<"电话:"<<pm->p_list[i].p_number<<"\t|"<<"地址:"<<pm->p_list[i].p_address<<"\t|"<<endl;
            cout<<"按任意键继续"<<endl;
            system("pause >nul");
            system("cls");
            return;
            /* code */
        }
       
        
        /* code */
    }
    cout<<"未找到指定联系人"<<endl;
    system("pause >nul");
    system("cls");
}
void modifyperson(person_manager *pm){
    string name3;
    cout<<"请输入需要修改信息人的名字：";
    cin>>name3;
    for (int i = 0; i < pm->p_size; i++)
    {
        if (pm->p_list[i].p_name==name3)
        {
            cout<<"已定位到"<<name3<<endl;
            cout<<"开始修改相关信息"<<endl;

            int tag=0;
            int age=0;
            cout<<"是否需要修改年龄？"<<endl;
            cout<<"1.修改"<<endl;
            cout<<"2.不修改"<<endl;
            cin>>tag;
            if(tag==1){
            cout<<"请输入年龄："<<endl;
            cin>>age;
            pm->p_list[i].p_age=age;
            cout<<"年龄修改成功"<<endl;
            system("cls");
            }
            
            cout<<"是否需要修改电话？"<<endl;
            cout<<"1.修改"<<endl;
            cout<<"2.不修改"<<endl;
            cin>>tag;
            if(tag==1){
            long long number=0;
            cout<<"请输入电话号码："<<endl;
            cin>>number;
            pm->p_list[i].p_number=number;
             cout<<"电话修改成功"<<endl;
            system("cls");
            }

            cout<<"是否需要修改地址？"<<endl;
            cout<<"1.修改"<<endl;
            cout<<"2.不修改"<<endl;
            cin>>tag;
            if(tag==1){
            string addr="";
            cout<<"请输入通讯地址："<<endl;
            cin>>addr;
            pm->p_list[i].p_address=addr;
            cout<<"通讯地址修改成功"<<endl;
            system("cls");
            }

            return;


          /* code */
        }
        
        /* code */
    }
    cout<<"未找到指定人员信息"<<endl;
    system("pause");
    return;

}

void delete_all_person(person_manager *pm){
    pm->p_size=0;
    cout<<"删除成功"<<endl;
    system("pause >nul");
    return;
}
