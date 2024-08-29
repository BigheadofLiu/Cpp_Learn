/*
list 链表（双向循环链表）
和vector一样是最常用的容器 链式存储 节点（数据域+指针域）
1.构造函数
list<T> list
list(beg,end)
list(n,elem)
list(const list& list) 拷贝构造函数

2.赋值和交换
asign(beg,end)
assign(n,elem)
list& operator=(const list& list) 运算符重载
swap(lst) 

3.大小操作
size()
empty()
resize(num)
resize(num,elem)

4.插入和删除
push_back(elem) 尾插
pop_back() //尾删
push_front(elem) 头插
pop_front 头删
insert(pos,elem) 插入
insert(pos,n,elem)
insert(pos,beg,end)
clear() 清空
erase(beg,end) 擦除
erase(pos)
remove(elem) 删除所有值匹配为elem的元素

5.数据存取
list.front()
list.back()

6.反转和排序
reverse() 反转
sort() 排序
*/
#include<list>
#include<iostream>
using namespace std;


void print_list(const list<int> &L){  //打印
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++){
       cout << *it << " ";    
    }
    cout<<endl;
}
bool sortlist(int val1,int val2){  //自定排序(大到小)
     return val1>val2;
}

void test06(){
    list<int> lst1;
    for(int i=0;i<8;i++){
        lst1.push_back(i);
    }
    print_list(lst1);
    // lst1.sort(sortlist);
    lst1.reverse(); //反序
    print_list(lst1);


}
int main(){
    test06();

}