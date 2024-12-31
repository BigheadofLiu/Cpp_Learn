#include<iostream>
#include "vector"
#include <map>
#include <set>
#include <utility>
/*
 *
for (declaration : expression)
{
    // 循环体
}
在上面的语法格式中declaration表示遍历声明，在遍历过程中，
当前被遍历到的元素会被存储到声明的变量中。expression是要遍历的对象，
它可以是表达式、容器、数组、初始化列表等。
*/
void test01(){
    std::vector<int> v1{1,2,3,4,5,6,7,8};
    for (auto i=v1.begin();i!=v1.end();i++){
        std::cout<<*i<<" ";
    }
}
void test02(){
    std::vector<int> v2{1,2,3,4,5,6,7,8};
    for (auto i:v2) {  //只能遍历(读),无法写。
        std::cout<<i<<" ";
    }
}

void test03(){
    std::vector<int> v3{1,2,3,4,5,6,7,8};
    for (auto &i:v3) {  //通过引用修改
        i=10086;
    }
    for(auto k:v3){
        std::cout<<k<<" ";
    }
}

void test04(){
    //提升遍历速度 const auto&
    std::vector<int> v4{1,2,3,4,5,6,7,8};
    for(const auto& k:v4){
        std::cout<<k<<" ";
    }
}

void test05(){
    std::map<int,std::string> m1 {{1,"丁真"},{2,"王源"},{3,"芝士雪豹"},{4,"giao"}};
    for(auto& i:m1){   //auto推导为：pair类型
        std::cout<<i.first<<" "<<i.second<<" "<<std::endl;
    }

    for (auto j=m1.begin();j!=m1.end();j++) {
        //auto推导为pair的迭代器类型
        std::cout<<j->first<<" "<<j->second<<std::endl;
    }
}
void test06(){
    //元素只读（set或替他关联性容器）
    std::set<std::pair<int,std::string>> s1{{1,"丁真"},{2,"王源"},{3,"芝士雪豹"},{4,"giao"}};
    for(auto& i:s1){  //i推导为const pair& 原因：set容器中数据不可修改
        std::cout<<i.first<<" "<<i.second<<" ";
    }
}

std::vector<int> v1{1,2,3,4,5,6,7,8};
 auto print(){
    std::cout<<"this`s my print"<<std::endl;
     return v1;
}
void test07(){
    for(auto i:print()){
        //print()被执行了一次
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
int main(){
//test01();
//test02();
//test03();
//test04();
//test05();
//test06();
test07();
}