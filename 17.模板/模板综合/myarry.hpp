#pragma once
#include<iostream>
#include"string.h"
using namespace std;
template<class T>
class myarry{
    public:
    //普通构造
    myarry(int capacity){
        this->m_capacity=capacity;
        this->m_size=0;
        this->m_address=new T[m_capacity];
    }
    //拷贝构造
    myarry(const myarry &arr1){
        this->m_capacity=arr1.m_capacity;
        this->m_size=arr1.m_size;
        //深拷贝
        this->m_address=new T[m_capacity];
        for(int i=0;i<this->m_size;i++){
            this->m_address[i]=arr1.m_address[i];
        }
    }
    //重载=
    myarry &operator=(const myarry& arr2 ){
        if(this->m_address!=NULL){
            //初始化
            delete[] this->m_address;
            this->m_capacity=0;
            this->m_size=0;           
        }
        this->m_capacity=arr2.m_capacity;
        this->m_size=arr2.m_size;
        this->m_capacity=new T[m_capacity];
        for (int i = 0; i < this->m_size; i++)
        {   /* code */
            this->m_address[i]=arr2.m_address[i];
            
        }
        return *this;
    }
    //重载[] 干嘛用的？
    T& operator[](int index){
        return this->m_address[index];
    }
    //尾插法
    void end_ins(const T &val){
        if(this->m_size==this->m_capacity){
            return;
        }else{
            this->m_address[this->m_size]=val;
            this->m_size++;
        }
    }
    //尾删法
    void end_del(){
        if(this->m_size==0){
            return;
        }
        this->m_size--;
    }
    //获取容量
    int get_capacity(){
        return this->m_capacity;
    }
    //获取大小
    int get_size(){
        return this->m_size; 
    }
    //析构
    ~myarry(){
        if(this->m_address!=NULL){
            delete [] this->m_address;
            this->m_address=NULL;
            this->m_capacity=0;
            this->m_size=0;
        }
    }
    private:
    T *m_address; //堆区数据指针
    int m_size;  //大小
    int m_capacity;   //容量
};