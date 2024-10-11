using namespace std;
#include<iostream>
#include"order.h"
int main(){
    int select=0;
    while(true){
        cout << "======================  欢迎来到机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择
        switch(select){
            case 1:		//学生
			break;
            case 2:		//老师
			break;
            case 3:		//管理员
			break;
            case 0:{    	//退出
			int c1=0;
			cout<<"确认退出？"<<endl;
			cout<<"1.确认"<<endl;
			cout<<"2.取消"<<endl;
			cin>>c1;
			switch(c1){
				case 1: system("pause >nul"); return 0; break;
				case 2: system("cls");break;
				default:
				cout << "输入有误，请重新选择！" << endl;
				system("pause >nul");
				system("cls");
				break;
			}
			break;}
			default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause >nul");
			system("cls");
			break;
        }
    }

}