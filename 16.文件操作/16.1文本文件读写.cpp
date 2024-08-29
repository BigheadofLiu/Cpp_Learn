#include<iostream>
#include<string.h>
#include"fstream"
using namespace std;
//写文本文件
void write_file(){
//创建流对象
fstream fst;
//指定文件名和打开方式
fst.open("test.txt",ios::out); 
//写入内容
fst<<"姓名 电话 手机\t"<<endl;
fst<<"张三 129 110\t"<<endl;
fst<<"李四 130 120\t"<<endl;
//关闭文件流对象
fst.close();
}

//读文本文件
void read_file(){
    //创建流对象
    fstream fst1;
    //指定文件的打开方式
    fst1.open("test.txt",ios::in);
    //判断文件是否打开成功
    if (!fst1.is_open()) 
    {
        /* code */
        cout<<"文件打开失败"<<endl;
        return;
    }
    //读文件
    //方法1 通过流对象右移获取  fst1>>
    // char buf[1024]={0};
    // while (fst1>>buf)  
    // { 
    //     cout<<buf;
    //     /* code */
    // }

    //方法2 通过getline()方法逐行获取文本 fst1.getline()
    // char buf[1024]={0};
    // while (fst1.getline(buf,sizeof(buf)))
    // {
    //     cout<<buf;
    //     /* code */
    // }
    
    //方法3 通过string字符串获取 getline()
    // string buf;
    // while (getline(fst1,buf))
    // {
    //     cout<<buf<<endl;
    //     /* code */
    // }
    //关闭
     
    //方法4 通过char接收 fst1.get()
    char c=0;
    while ((c=fst1.get())!=EOF)
    {
        cout<<c;
        /* code */
    }
    fst1.close();

}
int main(){
    // write_file();
    read_file();

}
