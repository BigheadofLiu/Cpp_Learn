#include "iostream"
using namespace std;

int main() {
    bool b = true; //true本质为1
    bool b2 = false; //false本质为0
    cout <<b<<endl;
    cout <<"b2占用内存大小为："<<sizeof(b2)<<endl;
}
