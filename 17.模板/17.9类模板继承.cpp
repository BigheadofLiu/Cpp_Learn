//类模板的继承
//1.父类是模板，子类需要指定T的类型才可以分配内存创建子类对象
template <class T>
class Base{
    public:
    T m;
};

//1.声明子类类型
class son1 : public Base<int>{
};

//2.子类也为模板
template<class T1,class T2> 
class son2:public Base<T1>{
};


