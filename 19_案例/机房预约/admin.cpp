#include "admin.h"

void  admin::admin::main_menu() {
    cout << "欢迎管理员："<<this->m_name<< "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n"; 
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

[[maybe_unused]] void admin::admin::add_order() {
    cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
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
        /* cout<<"请输入学号："<<endl;
        cin>>id; */

    }else
    {   file_name=TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入";
        /* cout<<"请输入职工编号："<<endl;
        cin>>id; */
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
    fst1<<id<<" "<<name<<" "<<psd<<" "<<" "<<endl;//写入文件
    cout<<"添加成功"<<endl;
    this->vector_init();
    system("pause");
    system("cls");
    fst1.close();
    
}

[[maybe_unused]] void admin:: admin::clear_order() {}

[[maybe_unused]] void admin:: admin::show_computer_info() {}
[[maybe_unused]] void print_order_student(student::student& s){
    cout<<"学号："<<s.m_sid<<" 姓名："<<s.m_name<<"密码："<<s.m_password<<endl;
}

[[maybe_unused]] void print_order_teacher(teacher::teacher& t){
    cout<<"工号："<<t.m_tid<<" 姓名："<<t.m_name<<"密码："<<t.m_password<<endl;
}
[[maybe_unused]] void admin:: admin::show_order() {
std::cout<<"----   查看预约    ----"<<endl;
std::cout << "1、查看所有学生" << endl;
std::cout << "2、查看所有老师" << endl;
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
/*void admin::login(string file_name,int type) {
    person *person=NULL;
    fstream fst1(file_name,ios::in);
    if(!fst1.is_open()){
        std::cout<<"文件打开失败"<<endl;
        fst1.close();
        return;
    }
    //用于接收输入数据
    int id=0;
    string name=NULL;
    string pwd="";
    // string tip="";
    // string error_tip="";
    if (type==1){
        // file_name==STUDENT_FILE;
        //  tip="请输入学号：";
        //  error_tip="学号重复，请重新输入";
        cout<<"请输入学号："<<endl;
        cin>>id;
        }
    else if(type==2){
        *//* file_name = TEACHER_FILE;
        tip = "请输入职工编号：";
        error_tip = "职工号重复，请重新输入"; *//*
       cout<<"请输入职工编号："<<endl;
       cin>>id;
    }
    *//* std::cout<<tip<<endl; *//*
    *//* while (true){
        std::cin>>id;
        bool ret=this->check_order(id,type);
        if(ret){
            cout<<error_tip<<endl;
        }else{
            cout<<"账号不存在，可以继续添加"<<endl;
            break;
        }
    } *//*
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
                person->main_menu();
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
                person->main_menu();
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
                person=new admin(name,pwd);
                // person.manager_order();  
                // person->main_menu();
                admin::manager_order(person);
                return;
            }
        }

    }
    cout<<"验证登录失败"<<endl;
    system("pause >nul");
    system("cls");
    return;
}*/

admin::admin::admin() {}

admin::admin::admin(std::string name, std::string psw) {
    this->m_name=name;
    this->m_password=psw;
    this->vector_init();
}

void admin:: admin::manager_order(person* &manager){
    while(true){
        manager->main_menu();
        admin* man=(admin*)manager;
        int select=0;
        cin>>select;
        if(select==1){
            cout<<"添加账号"<<endl;
            man->add_order();
        }else if(select==2)
        {
            cout<<"查看账号"<<endl;
            man->show_order();
            /* code */
        }else if(select==3){
            cout<<"查看机房"<<endl;
            man->show_computer_info();
        }else if(select==4){
            cout<<"清除预约"<<endl;
            man->clear_order();
        }else{
            delete manager;
            cout<<"注销成功"<<endl;
            system("pause");
            system("cls");
            return;
        } 
    }
}

bool admin:: admin::check_order(int id,int type){
    if(type==1){   
        for(auto it=v_stu.begin();it!=v_stu.end();it++){
            if(it->m_sid==id){
                return true;
            }
        }     
    }else
    {
        for(auto it=v_tea.begin();it!=v_tea.end();it++){
            if(it->m_tid==id){
                return true;
            }
        }
    }
    return false;
}

void admin:: admin::vector_init(){
    fstream fst2;
    fst2.open(STUDENT_FILE,ios::in);
    if(!fst2.is_open()){
        cout<<"文件读取失败"<<endl;
        return;
    }
    v_stu.clear();
    
    student::student s1;
//    student s1;
    while(fst2>>s1.m_sid&&fst2>>s1.m_name&&fst2>>s1.m_password){
        v_stu.push_back(s1);
    }
    cout<<"当前学生数量为："<<admin::admin::v_stu.size()<<endl;
    fst2.close();
    
    fst2.open(TEACHER_FILE,ios::in);
    if(!fst2.is_open()){
        cout<<"文件读取失败"<<endl;
        return;
    }
    this->v_tea.clear();
    teacher::teacher t1;
    while(fst2>>t1.m_tid&&fst2>>t1.m_name&&fst2>>t1.m_password){
        this->v_tea.push_back(t1);
    }
    cout<<"当前教师数量为："<<admin::admin::v_tea.size()<<endl;
    fst2.close();
}