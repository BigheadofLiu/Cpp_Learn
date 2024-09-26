/* // sort //对容器内元素进行排序
// random_shuffle //洗牌 指定范围内的元素随机调整次序
// merge  // 容器元素合并，并存储到另一容器中
// reverse // 反转指定范围的元素 */
/*排序 对容器内的元素进行排序*/

//1.sort默认从小到大排序

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
    bool operator()(int val1,int val2){  //bool operator()固定格式
        return val1>val2;
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
    std::sort(v1.begin(),v1.end()); //默认排序
    std::cout<<"\n";
    std::for_each(v1.begin(),v1.end(),my_print());
    std::cout<<"\n";
    std::sort(v1.begin(),v1.end(),my_sort()); //自定排序 使用谓词
    std::for_each(v1.begin(),v1.end(),my_print());
}
void test02(){
    std::vector<int> v1;
    creat_vector(v1);
    std::for_each(v1.begin(),v1.end(),my_print());
    std::cout<<"\n";
    std::random_shuffle(v1.begin(),v1.end());
    std::for_each(v1.begin(),v1.end(),my_print());
    std::cout<<"\n";
    std::sort(v1.begin(),v1.end());
    std::for_each(v1.begin(),v1.end(),my_print());
    std::cout<<"\n";
    std::reverse(v1.begin(),v1.end());
    std::for_each(v1.begin(),v1.end(),my_print());
}
int main(){
    srand(time(0));
    // test01();
    test02();
}
