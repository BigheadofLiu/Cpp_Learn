#include<iostream>
using namespace std;
#include<map>
//map底层是红黑树
#include <string>
/*
map所有元素类型均为pair
pair(key,value)
按照key自动排序
关联式容器 底层使用二叉树实现
key->value
map元素不允许key重复
multimap允许key重复
1.map构造和赋值
  map<T1,T2> mp; //无参
  mp(const map& m) //拷贝构造

  map& operator=(const map& map) 运算符重载
2.map大小和交换
  size()
  empty()
  swap()
3.插入和删除
  insert(elem)
  clear()
  erase(pos)
  erase(beg,end)
  erase(key)

4.查找和统计
  find(key)  //返回值为迭代器
  cout(key)  //返回值为0或1
  
5.排序
  通过仿函数改变排序方式  默认为从小到大
  class mycompare{
  bool operator() (int val1,int val2){
  return val1>val2;
  }
  };
  //仿函数使用
  map<int,int,mycompare> m;
*/
class mycompare{
    public:
    bool operator()(int val1,int val2){
        return val1>val2;
    }
};
void print_map(map<int,int,mycompare>& m){
    for(map<int,int,mycompare>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}
void test05(){
    map<int,int,mycompare> m1;
    for(int i=1;i<10;i++){
        for(int j=10;j<19;j++){
            m1.insert(make_pair(i,j));   //map只能接收pair类型的数据
        }
    }
    // m1.insert(make_pair(10,20));
    // m1.insert(make_pair(30,40));
    // m1.insert(make_pair(50,60));
    // m1.insert(make_pair(40,80));
    // m1.insert(make_pair(90,100));
    // m1.insert(make_pair(110,120));
    
    print_map(m1);
}
int main(){
    test05();
}