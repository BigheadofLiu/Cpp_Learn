#include<iostream>  
using namespace std;
//菱形继承 虚继承
//继承--基类
//虚继承-虚基类
class grandfather{
    public:
    string first_name="liu";
};
class dad1:virtual public grandfather{

};
class dad2:virtual public grandfather{

};
class son:public dad1, public dad2{

};
void test01(){
    son s1;
    // s1.first_name="liu"; //error:"son::first_name" 不明确 菱形继承带来的问题 空间浪费 需要用虚继承来解决

    s1.dad1::first_name="刘";
    s1.dad2::first_name="张";   //菱形继承如果出现同名成员属性 需要加上作用域加以区分
    s1.first_name="刘";         //虚继承访问成功 只需进行一个赋值操作

    cout<<s1.dad1::first_name<<endl;
    cout<<s1.dad2::first_name<<endl;

}

int main(){
    test01();
}

//菱形继承
/*
class son       size(64):
        +---
 0      | +--- (base class dad1)
 0      | | +--- (base class grandfather)
 0      | | | ?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@ first_name
        | | +---
        | +---
32      | +--- (base class dad2)
32      | | +--- (base class grandfather)
32      | | | ?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@ first_name
        | | +---
        | +---
        +---
*/

/*
虚继承 vbptr--virtual base priter 虚拟基类指针（通过本地地址+偏移地址）
class son       size(48):
        +---
 0      | +--- (base class dad1)
 0      | | {vbptr}
        | +---
 8      | +--- (base class dad2)
 8      | | {vbptr}
        | +---
        +---
        +--- (virtual base grandfather)
16      | ?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@ first_name
        +---

son::$vbtable@dad1@:
 0      | 0
 1      | 16 (sond(dad1+0)grandfather)  ----偏移量

son::$vbtable@dad2@:
 0      | 0
 1      | 8 (sond(dad2+0)grandfather)  ----偏移量
vbi:       class  offset o.vbptr  o.vbte fVtorDisp
     grandfather      16       0       4 0
*/