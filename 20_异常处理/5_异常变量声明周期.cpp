#include<iostream>
using namespace std;
 class my_exception{
    public:
    my_exception(){
        cout<<"myexceptionĬ�Ϲ���"<<endl;
    }
    my_exception(const my_exception& e){
        cout<<"myexception��������"<<endl;
    }
    ~my_exception(){
        cout<<"myexception��������"<<endl;
    }
 };
 void test01(){ //ʹ����ͨ������쳣ֵ
    try{
        throw my_exception();
    }catch(my_exception e){
        cout<<"��ͨ�������쳣"<<endl;
    }

//���
/* 
myexceptionĬ�Ϲ���
myexception��������
��ͨ�������쳣
myexception��������
myexception�������� */
 }

 void test02(){
    //ʹ�ö���ָ����쳣
    try{
        throw my_exception();
    }catch(my_exception* e){
        cout<<"����ָ���"<<endl;
        delete e;   //�ǵ��ͷ�ָ��
    }
// �����
// myexceptionĬ�Ϲ���
// terminate called after throwing an instance of 'my_exception'
// myexception��������
 }

 void test03(){
    //�������ý��쳣
    try{
        throw my_exception();
    }catch(my_exception &e){
        cout<<"����ָ���"<<endl;
        /* delete e; */
    }
//���
// myexceptionĬ�Ϲ���
// ����ָ���
// myexception��������

 }


 int main(){
   /*  test01(); */
   /* test02(); */
   test03();

 }
