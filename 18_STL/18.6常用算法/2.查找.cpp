/*
find(iterator beg, iterator end, value) //����Ԫ�� ����ҵ�����Ԫ�ص����� �Ҳ�������end������
find_if(iterator beg, iterator end, _Pred) //����������Ԫ�� ʹ�ú�����ν�� ����ҵ����������һ��������Ԫ�ص����� �Ҳ�������end������
adjacent_find(iterator beg, iterator end); //���������ظ�Ԫ�� ����ҵ� ���ص�һ����������ͬ��Ԫ�صĵ����� ���δ�ҵ�����end
binary_search(iterator beg, iterator end, value); //���ֲ��ҷ����������в���ʹ�ã��鵽true δ�鵽false
count(iterator beg, iterator end, value); //ͳ��Ԫ�ظ���
count_if(iterator beg, iterator end, _fun_); //������ͳ��Ԫ�ظ��� ʹ�ú�����ν��
*/
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
class Person{
    public:
    Person(std::string name,int age){
        this->m_name=name;
        this->m_age=age;
    }
    bool operator==(const Person& p){  
    //���ص�������ɶ��ģ��Ƚ�value�������д������ 
    //�����Բ�д find�����������Զ�����ıȽϷ����������������Ͱ�����
    
        if(this->m_age==p.m_age&&this->m_name==p.m_name){
            return true;
        }
        return false;
    }
    public:
    std::string m_name;
    int m_age;
};
void creat_vector(std::vector<int>& v){
for(int i=0;i<10;i++){
    v.push_back(i);
}
}
void test01(){
    std::vector<int> v1;
    creat_vector(v1);
    auto a=std::find(v1.begin(),v1.end(),5);
    if(a!=v1.end()){
        std::cout<<"���ҳɹ���"<<std::endl;
        return;
    }
    std::cout<<"����ʧ�ܣ�"<<std::endl;
    return;

}
void test02(){
    std::vector<Person> v;
    Person p1("Tom",18);
    Person p2("Jerry",19);
    Person p3("Rose",20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    auto a=std::find(v.begin(),v.end(),p1);
    if(a!=v.end()){
        std::cout<<"���ҳɹ���"<<std::endl;
        return;
    }
    std::cout<<"����ʧ��"<<std::endl;

}
class Mycompare{
    public:
    bool operator()(int val){  //bool operator()�̶���ʽ
        return val>5;
    }
};
void test03(){
    std::vector<int> v;
    creat_vector(v);
    auto a=std::find_if(v.begin(),v.end(),Mycompare());
    auto b=std::count(v.begin(),v.end(),5);
    auto c=std::count_if(v.begin(),v.end(),Mycompare());
    std::cout<<b<<" "<<c<<std::endl;
    if(a==v.end()){
        std::cout<<"����ʧ��"<<std::endl;
    }
        std::cout<<"���ҳɹ���"<<std::endl;
        std::cout<<*a<<std::endl;
    auto d=std::adjacent_find(v.begin(),v.end());
    if(d!=v.end()){
        std::cout<<"�����ظ����ҳɹ���"<<std::endl;
    }else
    {
        std::cout<<"�����ظ�����ʧ�ܣ�"<<std::endl;
    }
    auto e=std::binary_search(v.begin(),v.end(),5);
    if(e){
        std::cout<<"���ֲ���success"<<std::endl;
    }else{
        std::cout<<"���ֲ���fail"<<std::endl;
    }
    
}
void test04(){}
int main(){
    // test01();
    // test02();
    test03();
}
