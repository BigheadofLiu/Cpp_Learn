#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include <vector>

void test01()
{
	vector<int> v;

	//预留空间  预留位置不初始化 不可访问
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
	cout << "num:" << num << endl;
    
}

int main() {

	test01();
    
	system("pause");

	return 0;
}