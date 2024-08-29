/*vector构造函数
四个
*/
#include<iostream>
#include<vector>
using namespace std;
void print_vector(vector<int>& v){
    for (vector<int>::iterator i = v.begin(); i !=v.end(); i++)
    {
        cout<<*i<<" " ;
        /* code */
    }
    cout<<endl;
    
}
int main(){
    vector<int> v1; //1.无参构造 
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v2.push_back(i);
        
    }
    print_vector(v2);
    vector<int> v3(v2.begin(),v2.end());//2.有参构造1
    print_vector(v3);
    vector<int> v4(10,8); //3.有参构造2
    print_vector(v4);
    vector<int> v5(v4); //4.拷贝构造
    print_vector(v5);
}