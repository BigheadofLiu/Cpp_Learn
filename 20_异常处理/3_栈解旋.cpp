#include<iostream>
using namespace std;
class Data{
    private:
    int m_data;
    public:
    Data(int data){
    this->m_data=data;
    cout<<"data���캯��"<<endl;
    }
    ~Data(){
    cout<<"data��������"<<endl;
    }
};
int main(){
    // data d1,d2,d3;
    try{
        Data d1(100);
        Data d2(200);
        Data d3(300);
        throw 3;
    }catch(int e){
        cout<<"�����쳣"<<endl;
    }catch(char e){
        cout<<"�ַ����쳣"<<endl;
    }catch(...){
        cout<<"�����쳣"<<endl; 
    }
    return 0;
}
/*
data���캯��
data���캯��
data���캯��
data��������
data��������
data��������
�����쳣

�쳣�׳���ջ�Ϲ�������ж��󣬱��Զ�����

*/