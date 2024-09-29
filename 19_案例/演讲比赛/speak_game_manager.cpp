#include"speak_game_manager.h"
int speak_manager::speak_game_count=1;
/**错误揭露 非静态成员变量不支持类外直接访问 需要通过具体化的对象进行访问 */

speak_manager::speak_manager(){ //必须写空实现 不然报错。。。这是为何
this->init();
this->create_speaker();
}
speak_manager::~speak_manager(){
    //暂时空实现
}
int speak_manager::showmenu() {
        while (true) {
        cout << "********************************************" << endl;
        cout << "*************  欢迎参加演讲比赛 ************" << endl;
        cout << "*************  1.开始演讲比赛  *************" << endl;
        cout << "*************  2.查看往届记录  *************" << endl;
        cout << "*************  3.清空比赛记录  *************" << endl;
        cout << "*************  0.退出比赛程序  *************" << endl;
        cout << "********************************************" << endl;
        int c=0;
        cin >> c;
        if (cin.fail()) {
            cout << "非法输入，重新输入！";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Sleep(2000);
			system("cls");
            continue;
        }
        return c;
        /*break;*/
    }
}
void speak_manager::sys_exit(){
system("cls");
std::cout<<"欢迎下次使用";
system("pause >nul");
std::exit(0);
}
void speak_manager::choice(int c){
switch (c)
{
        case 1:  //开始比赛
        // cout<<"开始"<<endl;
		system("cls");
		start_game();
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
			cout<<"输入有误,重新输入！"<<endl;
			Sleep(2000);
			system("cls"); //清屏
			choice(speak_manager::showmenu());
			break;
}
}
void speak_manager::init(){
	//初始化成员函数属性
	this->v_all.clear();
	this->v_g1.clear();
	this->v_g2.clear();
	this->m_member.clear();
	// this->speak_game_count=1;  //再模块化为一个init()成员函数的意义是什么？
	this->speak_ref=10;
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
		
		// cout<<"name_need.size()"<<name_need.size()<<endl;
	}
}
void speak_manager::start_game(){
	// create_speaker();  //构造函数中已实现
	
	//1.第一轮比赛
	//抽签
	//比赛
	//晋级
	start_draw();
    start_speak();

	//2.第二轮比赛
	//抽签
	//比赛
	//晋级
	//保存分数
	start_draw();
    start_speak();
	
}
void speak_manager::start_draw(){
//抽签
std::cout<<"开始第"<<this->speak_game_count<<"轮抽签"<<std::endl;
// cout<<"------------------------"<<endl;
cout<<"抽签后的顺序如下"<<std::endl;
cout<<"编号"<<"       "<<"姓名"<<endl;
if(this->speak_game_count==1){
	random_shuffle(this->v_all.begin(),this->v_all.end());
    for (auto i = v_all.begin(); i !=v_all.end(); i++)
	{	
		cout<<i->number<<"    "<<i->name<<std::endl;
		/* code */
	}	
}else{
	random_shuffle(v_g1.begin(),v_g1.end());
	for (auto i = v_g1.begin(); i !=v_g1.end(); i++)
	{	
		cout<<i->number<<"    "<<i->name<<std::endl;
		/* code */
	}
}
cout<<"抽签完毕"<<endl;
system("pause >nul");
system("cls");
}
void speak_manager::start_speak(){
std::cout<<"第"<<speak_game_count<<"轮比赛现在开始"<<endl;
// std::cout<<endl<<endl;
vector<speaker> v_temp; //临时容器
// v_temp.resize(12);
// int s_num=0; //计数器
while(true){
if(this->speak_game_count==1){
	v_temp.resize(12);
	v_temp=this->v_all;
}else{
	v_temp.resize(6);
	v_temp=this->v_g1;
}

for (auto i = v_temp.begin(); i != v_temp.end(); i++)
{	
	// s_num++;
    /*cout<<"----"<<s_num<<"----"<<endl;*/
	deque<double> s_d;  //打分容器
	for (int i = 0; i <speak_ref; i++)
	{	auto score=double((rand()%40+61));
//        cout<<score<<endl;
	    s_d.push_back(score);
		/* code */
	}
	sort(s_d.begin(),s_d.end(),greater<>());
	s_d.pop_back();
	s_d.pop_front();   //剔除最高分和最低分
	double sum_score=0;
	sum_score=accumulate(s_d.begin(),s_d.end(),0);
	double ave_score=sum_score/double(s_d.size());
//    cout<<"平均成绩："<<ave_score<<endl;
	i->m_score[this->speak_game_count-1]=ave_score;
	s_d.clear();
	/* code */
	// if (s_num%6==0)
	// {
		// cout<<"第"<< s_num/6 <<"小组比赛成绩如下："<<endl;
		// cout<<"--编号--"<<"--姓名--"<<"--分数--"<<endl;
		// for (auto j=v_temp.begin();j!=v_temp.end();j++)
		// {
		// 	cout<<j->number<<" "<<j->name<<" "<<*j->m_score<<endl;
		// 	// v_temp.pop_back();
		// }	
}
if(this->speak_game_count==1){
	//第一轮比赛
	deque<speaker> d1;
	deque<speaker> d2;
	for(auto i=0;i<v_temp.size()/2&&i<v_temp.size();++i){
				// cout<<v_temp[i].number<<" "<<v_temp[i].name<<" "<<*v_temp[i].m_score<<endl;
				d1.push_back(v_temp[i]);  
				// sort(d1.begin(),d1.end(),greater<>());
	}
	
	for(auto i=v_temp.size()-v_temp.size()/2;i<v_temp.size();++i){
				// std::cout<<v_temp[i].number<<" "<<v_temp[i].name<<" "<<*v_temp[i].m_score<<endl;
				d2.push_back(v_temp[i]);
			}

		sort(d1.begin(),d1.end(),mycompare_sort());
        sort(d2.begin(),d2.end(),mycompare_sort());
		cout<<"-------------------------"<<endl;
		std::cout<<"第1小组成绩如下:"<<endl;
		cout<<"编号"<<"    "<<"姓名"<<"    "<<"分数"<<endl;
		for(auto i=d1.begin();i!=d1.end();i++){
			std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[speak_game_count-1]<<endl;
		}
		std::cout<<"恭喜以下选手晋级下一轮比赛"<<endl;
		d1.pop_back();
		d1.pop_back();
		d1.pop_back();
		for(auto i=d1.begin();i!=d1.end();i++){
			std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[speak_game_count-1]<<endl;
			*i->m_score=0;
			this->v_g1.push_back(*i);
		}

		cout<<"-------------------------"<<endl;

		std::cout<<"第2小组成绩如下:"<<endl;
		for(auto i=d2.begin();i!=d2.end();i++){
			std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[speak_game_count-1]<<endl;
		}
		std::cout<<"恭喜以下选手晋级下一轮比赛"<<endl;
		d2.pop_back();
		d2.pop_back();
		d2.pop_back();
		for(auto i=d2.begin();i!=d2.end();i++){
			std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[speak_game_count-1]<<endl;
			// *i->m_score=0;
			this->v_g1.push_back(*i);
		}


		// cout<<"-------------------------"<<endl;
		// int s_count=0;
		// for (auto j = v_temp.begin(); j !=v_temp.end()&&s_count<3; j++,s_count++)
		// {
		// 	if (this->speak_game_count==1)
		// 	{
		// 		this->v_g1.push_back(*j);
		// 	}else{
		// 		this->v_g2.push_back(*j);
		// 	}
		// }
		//  this->speak_game_count=2;
		cout<<"-------------------------"<<endl;
		std::cout<<endl;
	// }
    std::cout<<"第"<<this->speak_game_count<<"轮比赛结束"<<endl;
	v_temp.clear();
    this->speak_game_count=2;
	cout<<"以下选手进入下轮比赛："<<endl;
	for(auto i=v_g1.begin();i!=v_g1.end();i++){
		std::cout<<i->number<<" "<<i->name<<" "<<endl;
	}
	// continue;
	break;
}else{
	//第二轮比赛
	deque<speaker> d3;
	// std::cout<<"开始第二轮比赛"<<endl;
	// cout<<this->speak_game_count<<endl;
	for(auto i=v_temp.begin();i!=v_temp.end();i++){
		// std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[this->speak_game_count-1]<<endl;
		d3.push_back(*i);
	}
	sort(d3.begin(),d3.end(),mycompare_sort());
	std::cout<<"第二轮比赛结果如下："<<endl;
	// cout<<this->speak_game_count<<endl;
	for(auto i=d3.begin();i!=d3.end();i++){
		std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[this->speak_game_count-1]<<endl;
		// d3.push_back(*i);
	}
	d3.pop_back();
	d3.pop_back();
	d3.pop_back();
	for(auto i=d3.begin();i!=d3.end();i++){
		// std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[this->speak_game_count-1]<<endl;
		// d3.push_back(*i);
		this->v_g2.push_back(*i);
	}
	cout<<"本次比赛前三名为："<<endl;
	for (auto i = v_g2.begin(); i != v_g2.end(); i++)
	{
		std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[this->speak_game_count-1]<<endl;
		/* code */
	}
    system("pause >nul");
	break;
}
}
}

bool mycompare_sort::operator()(const speaker &s1, const speaker &s2) {
	// if(speak_manager::speak_game_count)
    return s1.m_score[speak_manager::speak_game_count-1] > s2.m_score[speak_manager::speak_game_count-1];
}

