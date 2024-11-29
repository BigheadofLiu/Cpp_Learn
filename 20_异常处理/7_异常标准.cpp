#include<iostream>
#include<exception>
using namespace std;

/*
exception	���б�׼�쳣��ĸ���
bad_alloc	��operator new and operator new[]����������ڴ�ʧ��ʱ
bad_exception	���Ǹ�������쳣������������쳣�׳��б���������badexception�쳣���������ڲ��׳����쳣�׳��б���û�е��쳣����ʱ���õ�unexpected�������׳��쳣������ʲô���ͣ����ᱻ�滻��Ϊbadexception���͡�
bad_typeid	ʹ��typeid������������һ��NULLָ�룬����ָ���Ǵ����麯�����࣬��ʱ�׳�����쳣��
bad_cast	ʹ��dynamic_castת������ʧ�ܵ�ʱ��
ios_base::failure	io�������̳��ִ���
logic_error	�߼����󣬿���������ǰ���Ĵ���
runtime_error	����ʱ���󣬽�������ʱ���ܼ��Ĵ���

logic_error�����ࣺ
����	                ����
std::invalid_argument	��ʾ���ݸ������Ĳ�����Ч��
std::domain_error	��ʾһ�������򷽷���һ����Ч����ѧ��domain���ϱ����á�
std::length_error	��ʾһ���������Գ�����Ч��Χ�ĳ��ȡ�
std::out_of_range	��ʾһ���������±곬����Ч��Χ��
std::overflow_error	��ʾһ���������������������ܱ�ʾ�����ֵ��
std::underflow_error	��ʾһ���������������������ܱ�ʾ����Сֵ��

runtime_error�����ࣺ

����	            ����
std::runtime_error	��ʾһ�������ʱ����
std::range_error	��ʾһ��ֵ��������Ч��Χ��
std::overflow_error	��ʾһ���������������������ܱ�ʾ�����ֵ��
std::underflow_error	��ʾһ���������������������ܱ�ʾ����Сֵ��
std::logic_error	��ʾ�߼�����ͨ������ֱ��ʹ����Ϊ���࣬���������ڱ�ʾδ���������า�ǵ�����ʱ����
std::bad_alloc	��ʾ�ڴ����ʧ�ܡ�
std::bad_cast	��ʾ����ת��ʧ�ܡ�
std::bad_typeid	��ʾtypeid������ڶ�̬������ʧ�ܡ�
std::bad_exception	��ʾ���쳣��������з������޷�������쳣��

*/
void test01(){
    throw std::out_of_range("��Խ����");
}
int main(){
    try
    {
        test01();
    }
    catch(std::exception& e)
    {
        cout<<e.what()<<endl;
    }

}
