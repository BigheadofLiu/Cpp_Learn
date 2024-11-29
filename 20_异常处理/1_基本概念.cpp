/*
异常的抛出和捕获
语法格式 throw（抛出）/try catch（抛出并捕获）
throw xxx;  抛出异常（不处理） 支持抛出字符串（const char*） 数字（int double等）

try{  
    代码块(包含抛出的异常)
}
catch(异常类型1){
异常处理或提醒1
}catch(异常类型2){
异常处理或提醒2
}catch(xxx){
...
}

try catch可以嵌套使用
try{

}catch{
    try{

    }catch{

    }
}catch{

}

如果异常被抛出 没有被捕获处理 程序会引发未处理异常错误（中断结束程序）

*/



#include<iostream>
using namespace std;
#include<typeinfo>
int devided(int a,int b){
    if (b==0)
    {
        throw 1/* "ZERO AS DEVIDED" */;
    }else if(typeid(a)!=typeid(int)||typeid(b)!=typeid(int))
    {   
        throw 2/* "TYPE ERROR" */;
        /* code */
    }else
    {   
        throw 3 /* "success" */;
    }   
    return (a-b);
}

int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    // cout<<typeid(a).name()<<endl;
    // cout<<typeid(b).name()<<endl;
    // system("pause");
    try{
    c=devided(a,b);
    }catch(int e){
        if(e==1){
            cerr<<"ZERO AS DEVIDED"<<endl;
            exit(0);
        }else if(e==2){ 
            cerr<<"TYPE ERROR"<<endl;
            exit(0);
        }/* else{
            cout<<"success"<<endl;
        } */
    }
    cout<<c<<endl;
}

    

    // if(b==0){
    //     /* throw "ZERO AS DEVIDED";  */  //只抛出异常没有捕获输出： terminate called after throwing an instance of 'char const*'

    //     /* try{
    //         throw "ZERO AS DEVIDED";
    //     }catch(const char* e){
    //         cerr<<"error message:"<<e<<endl;
    //     } */                              //抛出异常并捕获

    //     //多种类型异常抛出

    // }
    // c=a/b;
    // cout<<c<<endl;

// }