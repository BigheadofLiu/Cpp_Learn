#include<iostream>
class my_exception{
public:
virtual void My_Error_Exception()=0;
};

class null_point_error:public my_exception{
    public:
    virtual void My_Error_Exception(){
        std::cout<<"空指针异常"<<std::endl;
    }
};
class out_of_range_point_expection:public my_exception{
    public:
    virtual void My_Error_Exception(){
        std::cout<<"指针越界异常"<<std::endl;
    }
};
void test01(){

}
int main(){
    try
    {
        throw null_point_error();
    }
    catch(my_exception &e) //使用父类引用接异常
    {
        e.My_Error_Exception();
    }
    
}
