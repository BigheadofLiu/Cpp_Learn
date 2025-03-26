/*stack
栈 先进后出 //filo
push 进栈
pop  出栈
*/
#include<iostream>
#include<stack>
using namespace std;

/*stack构造函数
1.stack<T> stk;  默认构造
2.stack(const stack &sta) 拷贝构造*/
void test(){
    stack<int> stk1;
    for(int i=0;i<10;i++){
        stk1.push(i);
    }
    stack<int> stk2(stk1);   //stk1(stk2)
    stack<int> stk3=stk2;  //operator=重载
}




/*赋值
1.stack& operator=(const stack &stk)
*/
void test1(){
/**/
}


/*存取
1.stack.push() 栈顶添加
2.stack.pop()  栈顶移除
3.stack.top()  返回栈顶元素
*/
void test2(){
    stack<int> stk1;
    for(int i=0;i<10;i++){
        stk1.push(i);
    }
    // stack<int> stk2(stk1);   //stk1(stk2)
    // stack<int> stk3=stk2;  //operator=重载
    cout<<stk1.top()<<endl;
    stk1.push(10);
    cout<<stk1.top()<<endl;
    stk1.pop();
    stk1.pop();
    cout<<stk1.top()<<endl;
    cout<<stk1.size()<<endl<<stk1.empty()<<endl;
}



/*大小
1.empty()
2.size()
*/
void test3(){

}
int main(){
test();
test2();
}



