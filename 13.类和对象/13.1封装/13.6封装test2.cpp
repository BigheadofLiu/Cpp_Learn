#include<iostream>
#include<math.h>
#include<time.h>
#include<stdio.h>
//在一个cpp中判断
//也可通过多文件的方式进行判断
//多文件类的封装的编写
//类的声明写在头文件中
/*include:point.h(包含类的成员与方法,方法不需要实现) 类似于声明
主函数的同一目录下需要新建point.cpp,里面写方法的实现（方法需要继承于类point::void set_x(int y)）
主函数中直接调用头文件即可使用该类成员与方法
*/
using namespace std;
class point{
    public:
    void set_x(int x){
    p_x=x;

    }
    void set_y(int y){
    p_y=y;
    }
    int get_x(){
    return p_x;

    }
    int get_y(){
    return p_y;
    }

    private:
    int p_x;
    int p_y;

};
class circle{
    public:
    void set_c(point c){
    c_c=c;
    }
    void set_r(int r){
    c_r=r;
    }
    
    point get_c(){
        return c_c;
    }

    int get_r(){
        return c_r;
    }
    private:
    point c_c;
    int c_r;
};
void is_in_cricle(circle &,point &);
int main(){
    point p1,p2;
    int x1,x2,y1,y2,r1;
    cout<<"输入点1的x坐标："<<endl;
    cin>>x1;
    cout<<"输入点1的y坐标："<<endl;
    cin>>y1;

    cout<<"输入圆心x坐标："<<endl;
    cin>>x2;
    cout<<"输入圆心y坐标："<<endl;
    cin>>y2;

    cout<<"输入圆半径："<<endl;
    cin>>r1;


    p1.set_x(x1);
    p1.set_y(y1);

    p2.set_x(x2);
    p2.set_y(y2);

    circle c1;
    c1.set_c(p2);
    c1.set_r(2);
    // cout<<c1.get_c().get_x()<<endl;
    // cout<<c1.get_c().get_x()<<endl;
    is_in_cricle(c1,p1);

}
void is_in_cricle(circle &c,point &p){
    double distance=sqrt(pow((p.get_x()-c.get_c().get_x()),2)+pow((p.get_y()-c.get_c().get_y()),2));
    // cout<<distance<<endl;
    // cout<<c.get_r()<<endl;
    if (distance>double(c.get_r()))
    {
    cout<<"点在圆外"<<endl;
    }else{
        cout<<"点在圆内"<<endl;
    }
}

