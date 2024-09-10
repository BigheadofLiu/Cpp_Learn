// copy // 容器内指定范围的元素拷贝到另一容器中
// replace // 将容器内指定范围的旧元素修改为新元素
// replace_if  // 容器内指定范围满足条件的元素替换为新元素
// swap // 互换两个容器的元素
#include<iostream>
#include<vector>
#include<random>
#include<time.h>
#include<algorithm>
void creat_vector(std::vector<int>& v){
for(int i=0;i<10;i++){
    v.push_back(rand()%100+1);
}
}
class my_sort{
    public:
    bool operator()(int val1){  //bool operator()固定格式
        return val1>50;
    }
};
class my_print{
    public:
    void operator()(int val){  //bool operator()固定格式
        std::cout<<val<<" ";
    }
};
void test01(){
    std::vector<int> v1;
    creat_vector(v1);
    std::for_each(v1.begin(),v1.end(),my_print());
    std::cout<<"\n";
    std::vector<int> v2;
    v2.resize(v1.size()); //copy前先分配空间
    std::copy(v1.begin(),v1.end(),v2.begin());
    std::for_each(v2.begin(),v2.end(),my_print());
    std::cout<<"\n";
    std::replace(v2.begin(),v2.end(),79,88);
    std::for_each(v2.begin(),v2.end(),my_print());
    std::cout<<"\n";
    std::replace_if(v2.begin(),v2.end(),my_sort(),88);
    std::for_each(v2.begin(),v2.end(),my_print());
    std::cout<<"\n";
    std::swap(v1,v2);
    std::for_each(v1.begin(),v1.end(),my_print());
    std::cout<<"\n";
    std::for_each(v2.begin(),v2.end(),my_print());
    std::cout<<"\n";
}
int main(){
    // srand(time(0));
    test01();
    }