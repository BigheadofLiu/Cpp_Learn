#include<iostream>
#include"string.h"
using namespace std;
/*非多态计算器*/
class calculator{
    public:
    int m_a;
    int m_b;
    
    int m_calculator(string m_operator){
    if (m_operator=="+")
    {
        /* code */
        return m_a+m_b;
    }else if (m_operator=="-")
    {
        /* code */
        return m_a-m_b;
    }else if (m_operator=="*")
    {
        /* code */
        return m_a*m_b;
    }else if (m_operator=="/")
    {
        /* code */
        return m_a/m_b;
    }
    
    }

};

/*多态计算器
优点：
     组织结构清晰
     可读性强
     拓展性、维护性强
*/
class base_calculator{
    public:
    int m_a;
    int m_b;
    virtual int calculator(){

    }
};
class calculatorJia:public base_calculator{
int calculator(){ //重写基类虚方法
    return m_a+m_b;
}
};
class calculatorJian:public base_calculator{
int calculator(){ //重写基类虚方法
    return m_a-m_b;
}
};
class calculatorCheng:public base_calculator{
int calculator(){ //重写基类虚方法
    return m_a*m_b;
}
};
class calculatorChu:public base_calculator{
int calculator(){ //重写基类虚方法
    return m_a/m_b;
}
};


void fun1(){
    // calculator c1;
    // cin>>c1.m_a;
    // cin>>c1.m_b;
    // cout<<c1.m_calculator("+")<<endl;
    // cout<<c1.m_calculator("-")<<endl;
    // cout<<c1.m_calculator("*")<<endl;
    // cout<<c1.m_calculator("/");
    base_calculator *b=new calculatorJia; //虚基类的使用场景
    cin>>b->m_a;
    cin>>b->m_b;
    cout<<b->calculator()<<endl;
    delete b;  //防止出现空指针（使用完new 一定要使用delete）
    
    


};
int main(){
    fun1();


}