/*双端队列
1.头端可以进行插入删除操作
2.构造函数：
        deque<T> deq;
        deque(beg,end);
        deque(n,elem);
        deque(const deque &deq) 拷贝构造
3.赋值操作
        deque& operator=(const deque& de1);
        assign(beg,end)
        assign(n,elem) 
4.大小
        deque.size()
        deque.empty()
        deque.resize(num)
        deque.resize(num,elem)
5.插入删除
        push_back(elem)
        push_front(elem)
        pop_back()
        pop_front()

        insert(pos,elem)
        insert(pos,n,elem)
        insert(pos,beg,end)
        clear();
        erase(beg,end);
        erase(pos);
6.数据存取
        at[i]
        operator[]
        front()
        back()
7.排序
        sort(iterator beg,iterator end)
*/
#include<iostream>
#include<deque>
using namespace std;
void print_deque(const deque<int>&);

void test01(){
    deque<int> deq1;
    deque<int> deq2(0,9);
    deque<int> deq3(10,1);
    deque<int> deq4(deq3);

    deq1=deq2;
    deque<int> deq5;
    deq5.assign(100,110);
    deque<int> deq6;
    deq6.assign(10,888);

    print_deque(deq1);
    print_deque(deq2);
    print_deque(deq3);
    print_deque(deq4);
    print_deque(deq5);
    print_deque(deq6);




}
void print_deque(const deque<int>& deq){
for (int i = 0; i < deq.size(); i++)
{
    cout<<deq.at(i)<<" "<<endl;
    /*cout<<deq[i]<<" "endl;*/
    /* code */
}
cout<<endl;
}
int main(){
    test01();

}
