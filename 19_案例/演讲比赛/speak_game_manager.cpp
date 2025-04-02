#include"speak_game_manager.h"
int speak_manager::speak_game_count=1;
/**�����¶ �Ǿ�̬��Ա������֧������ֱ�ӷ��� ��Ҫͨ�����廯�Ķ�����з��� */

speak_manager::speak_manager(){ //����д��ʵ�� ��Ȼ������������Ϊ��
this->init();
this->create_speaker();
}
speak_manager::~speak_manager(){
    //��ʱ��ʵ��
}
int speak_manager::showmenu() {
        while (true) {
        cout << "********************************************" << endl;
        cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
        cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
        cout << "*************  2.�鿴�����¼  *************" << endl;
        cout << "*************  3.��ձ�����¼  *************" << endl;
        cout << "*************  0.�˳���������  *************" << endl;
        cout << "********************************************" << endl;
        int c=0;
        cin >> c;
        if (cin.fail()) {
            cout << "�Ƿ����룬�������룡";
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
std::cout<<"��ӭ�´�ʹ��";
system("pause >nul");
std::exit(0);
}
void speak_manager::choice(int c){
switch (c)
{
        case 1:  //��ʼ����
        // cout<<"��ʼ"<<endl;
		system("cls");
		start_game();
			break;
		case 2:  //�鿴��¼  
			/*cout<<"�鿴"<<endl;*/
            this->show_speaker();

			break;
		case 3:  //��ռ�¼
			/*cout<<"���"<<endl;*/
            this->clear_speak();
			break;
		case 0:  //�˳�ϵͳ
		    sys_exit();
			break;
		default:
			cout<<"��������,�������룡"<<endl;
			Sleep(2000);
			system("cls"); //����
			choice(speak_manager::showmenu());
			break;
}
}
void speak_manager::init(){
	//��ʼ����Ա��������
	this->v_all.clear();
	this->v_g1.clear();
	this->v_g2.clear();
	this->save_member.clear();
	// this->speak_game_count=1;  //��ģ�黯Ϊһ��init()��Ա������������ʲô��
	this->speak_ref=10;
	this->file_is_empty=1;  //Ĭ��1Ϊ�� 0Ϊ�ǿ�
}
void speak_manager::create_speaker(){
	string name_need="ABCDEFGHIJKL";
	for (int i = 0; i < name_need.size(); i++)
	{
		string name="ѡ��";
		name+=name_need[i];
		speaker sp;
		sp.name=name;   //������ʼ��
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j]=0.0;  //���ַ�����ʼ��
			/* code */
		}
        //��ų�ʼ��
		sp.number=i+10087459;
		// this->m_member=make_pair()
		this->v_all.push_back(sp);
		
		// cout<<"name_need.size()"<<name_need.size()<<endl;
	}
}
void speak_manager::start_game(){
	// create_speaker();  //���캯������ʵ��
	
	//1.��һ�ֱ���
	//��ǩ
	//����
	//����
	start_draw();
    start_speak();

	//2.�ڶ��ֱ���
	//��ǩ
	//����
	//����
	//�������
	start_draw();
    start_speak();
	
}
void speak_manager::start_draw(){
//��ǩ
std::cout<<"��ʼ��"<<this->speak_game_count<<"�ֳ�ǩ"<<std::endl;
// cout<<"------------------------"<<endl;
cout<<"��ǩ���˳������"<<std::endl;
cout<<"���"<<"       "<<"����"<<endl;
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
cout<<"��ǩ���"<<endl;
system("pause >nul");
system("cls");
}
void speak_manager::start_speak(){
std::cout<<"��"<<speak_game_count<<"�ֱ������ڿ�ʼ"<<endl;
// std::cout<<endl<<endl;
vector<speaker> v_temp; //��ʱ����
// v_temp.resize(12);
// int s_num=0; //������
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
	deque<double> s_d;  //�������
	for (int i = 0; i <speak_ref; i++)
	{	auto score=double((rand()%40+61));
//        cout<<score<<endl;
	    s_d.push_back(score);
		/* code */
	}
	sort(s_d.begin(),s_d.end(),greater<>());
	s_d.pop_back();
	s_d.pop_front();   //�޳���߷ֺ���ͷ�
	double sum_score=0;
	sum_score=accumulate(s_d.begin(),s_d.end(),0);
	double ave_score=sum_score/double(s_d.size());
//    cout<<"ƽ���ɼ���"<<ave_score<<endl;
	i->m_score[this->speak_game_count-1]=ave_score;
	s_d.clear();
	/* code */
	// if (s_num%6==0)
	// {
		// cout<<"��"<< s_num/6 <<"С������ɼ����£�"<<endl;
		// cout<<"--���--"<<"--����--"<<"--����--"<<endl;
		// for (auto j=v_temp.begin();j!=v_temp.end();j++)
		// {
		// 	cout<<j->number<<" "<<j->name<<" "<<*j->m_score<<endl;
		// 	// v_temp.pop_back();
		// }	
}
if(this->speak_game_count==1){
	//��һ�ֱ���
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
		std::cout<<"��1С��ɼ�����:"<<endl;
		cout<<"���"<<"    "<<"����"<<"    "<<"����"<<endl;
		for(auto i=d1.begin();i!=d1.end();i++){
			std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[speak_game_count-1]<<endl;
		}
		std::cout<<"��ϲ����ѡ�ֽ�����һ�ֱ���"<<endl;
		d1.pop_back();
		d1.pop_back();
		d1.pop_back();
		for(auto i=d1.begin();i!=d1.end();i++){
			std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[speak_game_count-1]<<endl;
			*i->m_score=0;
			this->v_g1.push_back(*i);
		}

		cout<<"-------------------------"<<endl;

		std::cout<<"��2С��ɼ�����:"<<endl;
		for(auto i=d2.begin();i!=d2.end();i++){
			std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[speak_game_count-1]<<endl;
		}
		std::cout<<"��ϲ����ѡ�ֽ�����һ�ֱ���"<<endl;
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
    std::cout<<"��"<<this->speak_game_count<<"�ֱ�������"<<endl;
	v_temp.clear();
    this->speak_game_count=2;
	cout<<"����ѡ�ֽ������ֱ�����"<<endl;
	for(auto i=v_g1.begin();i!=v_g1.end();i++){
		std::cout<<i->number<<" "<<i->name<<" "<<endl;
	}
	// continue;
	break;
}else{
	//�ڶ��ֱ���
	deque<speaker> d3;
	// std::cout<<"��ʼ�ڶ��ֱ���"<<endl;
	// cout<<this->speak_game_count<<endl;
	for(auto i=v_temp.begin();i!=v_temp.end();i++){
		// std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[this->speak_game_count-1]<<endl;
		d3.push_back(*i);
	}
	sort(d3.begin(),d3.end(),mycompare_sort());
	std::cout<<"�ڶ��ֱ���������£�"<<endl;
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
	cout<<"���α���ǰ����Ϊ��"<<endl;
	for (auto i = v_g2.begin(); i != v_g2.end(); i++)
	{
		std::cout<<i->number<<" "<<i->name<<" "<<i->m_score[this->speak_game_count-1]<<endl;
		/* code */
	}
	speak_manager::save_speaker(v_g2);

    system("pause >nul");
	system("cls");
	this->choice(this->showmenu());
	break;
}
}
}
bool mycompare_sort::operator()(const speaker &s1, const speaker &s2) {
	// if(speak_manager::speak_game_count)
    return s1.m_score[speak_manager::speak_game_count-1] > s2.m_score[speak_manager::speak_game_count-1];
}
void speak_manager::save_speaker(vector<speaker> &v) {
    fstream  fst1;
    fst1.open("win_speaker.txt",ios::out|ios::app);
	for (auto i = v.begin(); i != v.end(); i++)
	{
		// fst1.write((const char*)&i,sizeof(*i));
		// /* code */
		fst1<<","<<i->name<<" "/*<<i->m_score[0]*/<<" "<<i->m_score[1]<<","<<endl;   //��Ϊv_g1��v_g2�ֿ��洢���ַ���������ֻд��ڶ��ַ���
	}
	// fst1<<"11111"<<endl;
	fst1.close();
	std::cout<<"����ɹ�"<<endl;
}
void speak_manager::get_speaker(){
	fstream fst2;
	fst2.open("win_speaker.txt",ios::in);
	if (!fst2.is_open())
	{	
		std::cout<<"�ļ���ʧ��"<<endl;
		this->file_is_empty=1; //�ļ���ʶ�ÿ�	
		fst2.close();
		/* code */
	}
	char ch;
	fst2>>ch;
	if(fst2.eof()){
		cout<<"�ļ����ڵ���Ϊ��"<<endl;
		this->file_is_empty=1;
		fst2.close();
		return;
	}else{
		this->file_is_empty=0;  //�ļ���ʶ�ǿ�
		fst2.putback(ch);
		string data;  //�����ַ��������ַ�  stringҲ��������һ��
		int index=0;

		while(fst2>>data){
			//���ַ������д���
			std::vector<string> v;
			int pos=-1;
			int start=0;
			while(true){
				pos=data.find(",",start);
				if(pos==-1){
					break;
				}
				string temp=data.substr(start,pos-start);
				v.push_back(temp);
				start=pos+1;
			}
			this->save_member.insert(make_pair(index,v));
			index++;
		}
		fst2.close();
	}
}
void speak_manager::show_speaker(){
	for(auto i=0;i<this->save_member.size();i++){
        cout<<this->save_member[i][0]<<this->save_member[i][1]<<endl;
    }
    system("pause >nul");
    system("cls");
}
void speak_manager::clear_speak() {
    cout<<"ȷ����գ�"<<endl;
    cout<<"----1.ȷ��----"<<endl;
    cout<<"----2.ȡ��----"<<endl;
    auto select=0;
    cin>>select;
    if(select==1){
        fstream fst("win_speaker.txt",ios ::trunc);  //ɾ���ļ�
        fst.close();
		this->init();//�ÿպ�����д��
		this->create_speaker();
		this->get_speaker();
        cout<<"��ճɹ�"<<endl;
    }
    system("pause");
    system("cls");
}