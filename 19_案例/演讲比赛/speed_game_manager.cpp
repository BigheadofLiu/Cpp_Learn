#include"speed_game_manager.h"
speed_manager::speed_manager(){ //必须写空实现 不然报错。。。这是为何
}
speed_manager::~speed_manager(){
}
int speed_manager::showmenu(){
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	int c;
	cin>>c;
	return c;
}
void speed_manager::sys_exit(){
system("cls");
std::cout<<"欢迎下次使用"<<endl;
system("pause");
std::exit(0);
}
void speed_manager::choice(int showmenu()){
switch (showmenu())
{
        case 1:  //开始比赛
        cout<<"开始"<<endl;
			break;
		case 2:  //查看记录
			cout<<"查看"<<endl;
			break;
		case 3:  //清空记录
			cout<<"清空"<<endl;
			break;
		case 0:  //退出系统
		    speed_manager::sys_exit();
			break;
		default:
			cout<<"输入有误"<<endl;
			system("cls"); //清屏
			break;
}
}

