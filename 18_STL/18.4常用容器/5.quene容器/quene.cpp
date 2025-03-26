#include<iostream>
#include<queue>
using namespace std;
/*quene队列 先进先出*/ //fifo
/*
1.基本构造:quene<T> qu,quene(const quene& qu)
2.赋值:quene operator=(const quene &que)
3.存取：push()
        pop()
        back()
        front()
4.大小操作
empty()
size()
*/
void test01(){
    queue<int> qu1;
    for(int i=0;i<10;i++){
    qu1.push(i);
    }
    queue<int> qu2(qu1);
    queue<int> qu3=qu2;
    cout<<qu1.front()<<endl;
    cout<<qu1.back()<<endl;
    cout<<qu1.size()<<endl;
    cout<<qu1.empty()<<endl;
}
int main(){
    test01();
    
}