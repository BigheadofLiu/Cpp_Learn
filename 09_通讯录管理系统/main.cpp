#include"iostream"
using namespace std;
#include"string.h"
#define MAX_SIZE 1000   //define �����ݺ��治��Ҫ�� ; ��Ȼ�ᱨ��
// #pragma execution_character_set("GBK")  

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
      //��ʼ������

    switch(select){
        case 1:addperson(&pm);  break;
        case 2:showperson(&pm); break;
        case 3:deleteperson(&pm);  break;
        case 4:modifyperson(&pm);  break;
        case 5:searchperson(&pm);  break;    
        case 6:delete_all_person(&pm);  break;
        case 0:cout<<"�˳�ͨѶ¼ϵͳ"<<endl;
        cout<<"��������˳�"<<endl;
        system("pause >nul");
        return 0;break;
        default:system("cls");cout<<"���������������룡"<<endl;
        break;
}
}
}
void showmenu(){
    system("color 25");
    cout<<"*********************************************"<<endl;
    cout<<"************��ӭʹ��ͨѶ¼����ϵͳ***********"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*************1.�����ϵ��********************"<<endl;
    cout<<"*************2.��ʾ��ϵ��********************"<<endl;
    cout<<"*************3.ɾ����ϵ��********************"<<endl;
    cout<<"*************4.�޸���ϵ��********************"<<endl;    
    cout<<"*************5.��ѯ��ϵ��********************"<<endl;   
    cout<<"*************6.�����ϵ��********************"<<endl;
    cout<<"*************0.�˳�ϵͳ**********************"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"��ѡ���ܣ�";
}
void addperson(person_manager *pm){
    system("cls");
    if (pm->p_size==MAX_SIZE)
    {
        cout<<"ͨѶ¼�������޷����"<<endl;
        return;
       
    }else{
    string name="";
    cout<<"���������֣�"<<endl;
    cin>>name;
    // cin >> pm->p_list[pm->p_size]->name;  //�޷�ֱ��cin�ṹ�����
    pm->p_list[pm->p_size].p_name=name;
    system("cls");

    cout<<"�������Ա�"<<endl;
    cout<<"1.��"<<endl;
    cout<<"2.Ů"<<endl;
    int sex=0;
    while (true)
    {
    cin>>sex;
    if (sex==1||sex==2)
    {
        pm->p_list[pm->p_size].p_sex=sex;
        break;
    }else{
        cout<<"�����������������"<<endl;
        // continue;        
    }
   

    }
    system("cls");

    int age=0;
    cout<<"���������䣺"<<endl;
    cin>>age;
    pm->p_list[pm->p_size].p_age=age;
    system("cls");

    long long number=0;
    cout<<"������绰���룺"<<endl;
    cin>>number;
    pm->p_list[pm->p_size].p_number=number;
    system("cls");

    string addr="";
    cout<<"������ͨѶ��ַ��"<<endl;
    cin>>addr;
    pm->p_list[pm->p_size].p_address=addr;
    system("cls");

    pm->p_size++;
    
    }

    cout<<"��ӳɹ�"<<endl;
    cout<<"��������˳�"<<endl;
    system("pause >nul");
    system("cls");
}
void showperson(person_manager *pm){
    // cout<<pm->p_size<<endl;
    while (pm->p_size==0)
    {
        cout<<"��û����ϵ�ˣ�����Ӻ�鿴��";
        cout<<"��������˳�"<<endl;
        system("pause >nul");
        system("cls");
        return;
        // break;
        /* code */
        
    }
    // cout<<"���"<<"\t|"<<"����"<<"\t|"<<"�Ա�    "<<"\t|"<<"����    "<<"\t|"<<"�绰    "<<"\t|"<<"��ַ    "<<endl;
    for (int i = 0; i < pm->p_size; i++)
    {
        // cout<<"��"<<i+1<<"����ϵ����Ϣ���£�"<<endl;
        cout<<"��ţ�"<<i+1<<"\t|"<<"����:"<<pm->p_list[i].p_name<<"\t|"<<"�Ա�"<<(pm->p_list[i].p_sex==1?"��":"Ů")<<"\t|"<<"���䣺"<<pm->p_list[i].p_age<<"\t|"<<"�绰:"<<pm->p_list[i].p_number<<"\t|"<<"��ַ:"<<pm->p_list[i].p_address<<"\t|"<<endl;
        // pm->p_size++;        
        /* code */
        //ע����Ŀ�������Ӧ��  (����1?���1:���2) ��()������������
    }
    cout<<"ȫ����ϵ����Ϣ����ʾ"<<endl;
    cout<<"��������˳�"<<endl;
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
    // cout<<"���޴���"<<endl;
    return -1;
            
        }

void deleteperson(person_manager *pm){
    string name1;
    cout<<"������Ҫɾ������ϵ������:"<<endl;
    cin>>name1;
    int i=isexist(pm,name1);
    if(i==-1){
        cout<<"���޴���"<<endl;
        system("pause >nul");
        system("cls");
        return;
    }
    for(int j=i;j<pm->p_size-1;j++){
        pm->p_list[j]=pm->p_list[j+1];
    }
    pm->p_size--;
    cout<<"ɾ���ɹ�"<<endl;
    system("pause >nul");
    system("cls");
}
void modifyperson(){}
void searchperson(person_manager *pm){
    string name2;
    cout<<"��ѡ����Ҫ���ҵ���ϵ������"<<endl;
    cin>>name2;
    for (int i = 0; i < pm->p_size; i++)
    {
        if (pm->p_list[i].p_name==name2)
        {
            cout<<"��ѯ��������Ϣ��"<<endl;
            cout<<"��ţ�"<<i+1<<"\t|"<<"����:"<<pm->p_list[i].p_name<<"\t|"<<"�Ա�"<<(pm->p_list[i].p_sex==1?"��":"Ů")<<"\t|"<<"���䣺"<<pm->p_list[i].p_age<<"\t|"<<"�绰:"<<pm->p_list[i].p_number<<"\t|"<<"��ַ:"<<pm->p_list[i].p_address<<"\t|"<<endl;
            cout<<"�����������"<<endl;
            system("pause >nul");
            system("cls");
            return;
            /* code */
        }
        /* code */
    }
    cout<<"δ�ҵ�ָ����ϵ��"<<endl;
    system("pause >nul");
    system("cls");
}
void modifyperson(person_manager *pm){
    string name3;
    cout<<"��������Ҫ�޸���Ϣ�˵����֣�";
    cin>>name3;
    for (int i = 0; i < pm->p_size; i++)
    {
        if (pm->p_list[i].p_name==name3)
        {
            cout<<"�Ѷ�λ��"<<name3<<endl;
            cout<<"��ʼ�޸������Ϣ"<<endl;
            int tag=0;
            int age=0;
            cout<<"�Ƿ���Ҫ�޸����䣿"<<endl;
            cout<<"1.�޸�"<<endl;
            cout<<"2.���޸�"<<endl;
            cin>>tag;
            if(tag==1){
            cout<<"���������䣺"<<endl;
            cin>>age;
            pm->p_list[i].p_age=age;
            cout<<"�����޸ĳɹ�"<<endl;
            system("cls");
            }   
            cout<<"�Ƿ���Ҫ�޸ĵ绰��"<<endl;
            cout<<"1.�޸�"<<endl;
            cout<<"2.���޸�"<<endl;
            cin>>tag;
            if(tag==1){
            long long number=0;
            cout<<"������绰���룺"<<endl;
            cin>>number;
            pm->p_list[i].p_number=number;
             cout<<"�绰�޸ĳɹ�"<<endl;
            system("cls");
            }
            cout<<"�Ƿ���Ҫ�޸ĵ�ַ��"<<endl;
            cout<<"1.�޸�"<<endl;
            cout<<"2.���޸�"<<endl;
            cin>>tag;
            if(tag==1){
            string addr="";
            cout<<"������ͨѶ��ַ��"<<endl;
            cin>>addr;
            pm->p_list[i].p_address=addr;
            cout<<"ͨѶ��ַ�޸ĳɹ�"<<endl;
            system("cls");
            }
            return;
          /* code */
        }
        
        /* code */
    }
    cout<<"δ�ҵ�ָ����Ա��Ϣ"<<endl;
    system("pause");
    return;
}
void delete_all_person(person_manager *pm){
    pm->p_size=0;
    cout<<"ɾ���ɹ�"<<endl;
    system("pause >nul");
    return;
}
