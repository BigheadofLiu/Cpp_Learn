#pragma once
#include<iostream>
#include<vector>
#include"speaker.h"
#include<map>
#include<algorithm>
#include<time.h>
using namespace std;
class speak_manager{
    public:
    speak_manager();
    ~speak_manager();
    int showmenu();
    void sys_exit();
    void choice(int);
    void init(); //先不实现
    void create_speaker(); //创建选手
    void start_game();  //开始比赛
    void start_draw();  //抽签函数
    void start_speak();
 
    public:
    vector<speaker> v_all; //12个选手容器 12
    vector<speaker> v_g1; //第一轮容器 6
    vector<speaker> v_g2; //第二轮容器 3
    map<int,speaker> m_member; //存放参赛者编号和选手 12
    int speak_game_count; //比赛轮数 2
};
