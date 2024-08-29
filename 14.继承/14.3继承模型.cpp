#include<iostream>  
using namespace std;
//利用开发工具分析继承（类的对象）
//cd 文件所在目录
//  cl /d1 reportSingleClassLayout类名 文件名
class dad {
    public:
    int a;
    protected:
    int b;
    private:
    int c;
};
class son:public dad{
    public:
    int d;
};

//pravite属性可以继承（但是被隐藏）
/*
class dad       size(12):
        +---
 0      | a
 4      | b
 8      | c
        +---
*/

/*
class son       size(16):
        +---
 0      | +--- (base class dad)
 0      | | a
 4      | | b
 8      | | c
        | +---
12      | d
        +---
*/