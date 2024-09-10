/*
find(iterator beg, iterator end, value) //查找元素 如果找到返回元素迭代器 找不到返回end迭代器
find_if(iterator beg, iterator end, _Pred) //按条件查找元素 使用函数或谓词 如果找到返回满足第一个条件的元素迭代器 找不到返回end迭代器
adjacent_find(iterator beg, iterator end); //查找相邻重复元素 如果找到 返回第一个相邻且相同的元素的迭代器 如果未找到返回end
binary_search(iterator beg, iterator end, value); //二分查找法（无序序列不可使用）查到true 未查到false
count(iterator beg, iterator end, value); //统计元素个数
count_if(iterator beg, iterator end, _fun_); //按条件统计元素个数 使用函数或谓词
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
    //重载的意义是啥？模拟比较value？如果不写可以吗？ 
    //不可以不写 find方法不包含自定义类的比较方法（内置数据类型包含）
    
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
        std::cout<<"查找成功！"<<std::endl;
        return;
    }
    std::cout<<"查找失败！"<<std::endl;
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
        std::cout<<"查找成功！"<<std::endl;
        return;
    }
    std::cout<<"查找失败"<<std::endl;

}
class Mycompare{
    public:
    bool operator()(int val){  //bool operator()固定格式
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
        std::cout<<"查找失败"<<std::endl;
    }
        std::cout<<"查找成功！"<<std::endl;
        std::cout<<*a<<std::endl;
    auto d=std::adjacent_find(v.begin(),v.end());
    if(d!=v.end()){
        std::cout<<"相邻重复查找成功！"<<std::endl;
    }else
    {
        std::cout<<"相邻重复查找失败！"<<std::endl;
    }
    auto e=std::binary_search(v.begin(),v.end(),5);
    if(e){
        std::cout<<"二分查找success"<<std::endl;
    }else{
        std::cout<<"二分查找fail"<<std::endl;
    }
    
}
void test04(){}
int main(){
    // test01();
    // test02();
    test03();
}
