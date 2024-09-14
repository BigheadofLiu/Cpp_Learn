#include"speak_game_manager.h"
speak_manager::speak_manager(){ //必须写空实现 不然报错。。。这是为何
this->init();
this->create_speaker();

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
		create_speaker();
		start_draw();
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
	//初始化成员函数属性
	this->v_all.clear();
	this->v_g1.clear();
	this->v_g2.clear();
	this->m_member.clear();
	this->speak_game_count=1;  //再模块化为一个init()成员函数的意义是什么？
}
void speak_manager::create_speaker(){
	string name_need="ABCDEFGHIJKL";
	for (int i = 0; i < name_need.size(); i++)
	{
		string name="选手";
		name+=name_need[i];
		speaker sp;
		sp.name=name;   //姓名初始化
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j]=0.0;  //两轮分数初始化
			/* code */
		}
        //编号初始化
		sp.number=i+10087459;
		// this->m_member=make_pair()
		this->v_all.push_back(sp);
	}
}
void speak_manager::start_game(){
	//1.第一轮比赛
	//抽签
	//比赛
	//晋级

	//2.第二轮比赛
	//抽签
	//比赛
	//晋级
	//保存分数
}
void speak_manager::start_draw(){
//抽签
std::cout<<"开始第"<<this->speak_game_count<<"轮抽签"<<std::endl;
cout<<"------------------------"<<endl;
cout<<"抽签后的顺序如下"<<std::endl;
cout<<"----编号------姓名-------"<<endl;
if(this->speak_game_count==1){
	random_shuffle(this->v_all.begin(),this->v_all.end());
    for (auto i = v_all.begin(); i !=v_all.end(); i++)
	{	
		cout<<i->number<<"----"<<i->name<<std::endl;
		/* code */
	}	
}else{
	random_shuffle(v_g1.begin(),v_g1.end());
	for (auto i = v_g1.begin(); i !=v_g1.end(); i++)
	{	
		cout<<i->number<<"----"<<i->name<<std::endl;
		/* code */
	}
}
cout<<"抽签完毕"<<endl;
system("pause");
cout<<endl;
}
void start_speak(){

}