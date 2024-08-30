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
    string name="员工";int salary=0;
    for(int i=0;i<NameSeed.size();i++){
        name+=NameSeed[i];
        salary=rand()%10000+1000;
        Worker worker(name,salary);
        v.push_back(worker);
    }
}
void Set_Group(vector<Worker>& v,multimap<int,Worker>& m){
    for (auto i = v.end(); i != v.end(); i++)
    {
        int Part_Id=rand()%3;
        m.insert(make_pair(Part_Id,*i));
        /* code */
    }  
}
void Print_Worker_Group(multimap<int,Worker>& m){
    int i;
    cout<<"输入你想查看的部门人员名单:"<<endl;
    cout<<"1.策划"<<endl;
    cout<<"2.美术"<<endl;
    cout<<"3.研发"<<endl;

    cout<<"策划部门名单如下："<<endl;
    auto pos=m.find(CeHua);
    auto count=m.count(CeHua);
    auto index=0;
    for(;pos!=m.end()&&index<count;pos++,index++){  //双指针
        cout<<pos->second.name<<" "<<pos->second.salary<<endl;
    }

    
}

void test01(){
    auto a=8;
}

int main(){

}   