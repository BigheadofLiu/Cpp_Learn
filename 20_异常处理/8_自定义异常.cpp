#include<iostream>
#include<exception>
using namespace std;
class my_expection:public exception{
    public:
    string str;
    my_expection(){
    }
    my_expection(string msg){
        this->str=msg;
    }
    virtual const char* what() const throw(){  //const throw() 用于防止父类在字类前抛出异常
        return str.c_str();
    }  
};
void test(){
    throw my_expection("this my exception");
}
int main(){
    try
    {
        test();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}