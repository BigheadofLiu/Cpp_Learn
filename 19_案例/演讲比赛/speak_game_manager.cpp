#include"speak_game_manager.h"
speak_manager::speak_manager(){ //必须写空实现 不然报错。。。这是为何
//初始化成员函数属性
this->v_all.clear();
this->v_g1.clear();
this->v_g2.clear();
this->m_victor.clear();
this->speak_game_count=1;  //再模块化为一个init()成员函数的意义是什么？
}
speak_manager::~speak_manager(){
}
int speak_manager::showmenu(){
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
void speak_manager::sys_exit(){
system("cls");
std::cout<<"欢迎下次使用"<<endl;
system("pause >nul");
std::exit(0);
}
void speak_manager::choice(int c){
switch (c)
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
		    sys_exit();
			break;
		default:
			cout<<"输入有误"<<endl;
			system("cls"); //清屏
			break;
}
}
void speak_manager::init(){

}
void speak_manager::create_speaker(){
	string name_need="ABCDEFGHIJKL";
	
	for (int i = 0; i < name_need.size(); i++)
	{
		string name="选手";
		name+=name_need[i];
		speaker sp;
		sp.name=name;
	}
	

}
