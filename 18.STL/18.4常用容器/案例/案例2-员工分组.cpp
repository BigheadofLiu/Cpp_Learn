#include"iostream"
#include<map>
#include<string>
using namespace std;
#include<vector>
#include<ctime>

#define CeHua 0
#define MeiShu 1
#define YanFa 2

class Worker{
    public:
    string name;
    int salary;
    
    public:
    Worker(string name,int salary){
    this->name=name;
    this->salary=salary;
    }
};
void Creat_Worker(vector<Worker>& v){
    string NameSeed="ABCDEFGHI";
    string name="Ա��";int salary=0;
    for(int i=0;i<NameSeed.size();i++){
        name+=NameSeed[i];
        salary=rand()%10000+1000;
        Worker worker(name,salary);
        v.push_back(worker);
    }
}
void Set_Group(vector<Worker>& v,multimap<int,Worker>& m){
    for (auto i = v.begin(); i != v.end(); i++)
    {
        int Part_Id=rand()%3;
        cout<<"11111"<<endl;
        m.insert(make_pair(Part_Id,*i));
        /* code */
    }  
}
void Print_Worker_Group(multimap<int,Worker>& m){
    int i;
    cout<<"��������鿴�Ĳ�����Ա����:"<<endl;
    cout<<"1.�߻�"<<endl;
    cout<<"2.����"<<endl;
    cout<<"3.�з�"<<endl;
    cin>>i;
    switch(i){
        case 1:{
                cout<<"�߻������������£�"<<endl;
                auto pos=m.find(CeHua);
                int count=m.count(CeHua);
                int index=0;
                for(;pos!=m.end()&&index<count;pos++,index++){  //˫ָ��
                    cout<<pos->second.name<<" "<<pos->second.salary<<endl;
                }
                break;
                }
        case 2:{
                cout<<"���������������£�"<<endl;
                auto pos=m.find(MeiShu);
                int count=m.count(MeiShu);
                int index=0;
                for(;pos!=m.end()&&index<count;pos++,index++){  //˫ָ��
                    cout<<pos->second.name<<" "<<pos->second.salary<<endl;
                }
                break;
                }
        case 3:{
                cout<<"�з������������£�"<<endl;
                auto pos=m.find(YanFa);
                int count=m.count(YanFa);
                int index=0;
                for(;pos!=m.end()&&index<count;pos++,index++){  //˫ָ��
                    cout<<pos->second.name<<" "<<pos->second.salary<<endl;
                }
                break;
                }
    }
}

void test01(){
    vector<Worker> v1;
    multimap<int,Worker> m1;
    Creat_Worker(v1);
    Set_Group(v1,m1);
    Print_Worker_Group(m1);
}

int main(){
    srand((unsigned int)time(NULL));
    test01();
}   