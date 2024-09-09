#include<iostream>
using namespace std;

//分别通过（类内）成员函数（方法）和全局函数判断两个立方体是否一致
class cube{
    public:
    //开启类内的读写权限

    float Set_L(float l){
     Cube_L=l;
    //  return Cube_L;
    }
    float Set_W(float w){
    Cube_W=w;
    // return Cube_W;
    }
    float Set_H(float h){
    Cube_H=h;
    // return Cube_H;
    }

    float Get_L(){
     
    return Cube_L;
    }
    float Get_W(){
    
    return Cube_W;
    }
    float Get_H(){
    
    return Cube_H;
    }
    
    

    float Caculate_C(){
    return 4*Cube_L*Cube_H+2*Cube_L*Cube_W;
    }

    float Caculate_V(){
    return Cube_L*Cube_W*Cube_H;
    }

    //通过内部函数判断两个立方体是否相同
    void duibicube(cube &c){
        if(Cube_H==c.Get_H()&&Cube_L==c.Get_L()&&Cube_W==c.Get_W()){
            cout<<"两个立方体相同"<<endl;
        }
        else{
            cout<<"两个立方体不同"<<endl;
        }

    }

    private:
    float Cube_L;
    float Cube_W;
    float Cube_H;
};
// bool duibicube(cube & ,cube &);
int main(){
    int l,w,h;
    int l_2,w_2,h_2;
    cout<<"请输入立方体1的长宽高"<<endl;
    cin>>l;
    cin>>w;
    cin>>h;
    cout<<"请输入立方体2的长宽高"<<endl;
    cin>>l_2;
    cin>>w_2;
    cin>>h_2;
    cube c1;
    cube c2;
    c1.Set_H(l);
    c1.Set_L(h);
    c1.Set_W(w);
    c2.Set_H(l_2);
    c2.Set_L(h_2);
    c2.Set_W(w_2);
    cout<<"立方体1表面积："<<c1.Caculate_C()<<endl;
    cout<<"立方体1体积："<<c1.Caculate_V()<<endl;
    cout<<"立方体2表面积："<<c2.Caculate_C()<<endl;
    cout<<"立方体2体积："<<c2.Caculate_V()<<endl;
    c1.duibicube(c2);

    // bool ret=false;
    // ret=c1.duibicube(c2);
    // ret=duibicube(c1,c2);
    // if (ret)
    // {
    //     cout<<"两个立方体一致";
    //     /* code */
    // }else{
    //     cout<<"两个立方体相同";
    // }
}

    //全局函数判断两个立方体是否一致
    // bool duibicube(cube &c1,cube &c2){
    //     if (c1.Get_H()==c2.Get_H()&&c1.Get_L()==c2.Get_L()&&c1.Get_W()==c1.Get_W())
    //     {
    //         return true;
    //         /* code */
    //     }
    //     return false;
    // }
