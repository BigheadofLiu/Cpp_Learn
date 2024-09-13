#pragma once
#include<iostream>
#include<vector>
#include"speaker.h"
#include<map>
using namespace std;
class speak_manager{
    public:
    speak_manager();
    ~speak_manager();
    int showmenu();
    void sys_exit();
    void choice(int);
    void init(); //先不实现
    void create_speaker();

    public:
    vector<int> v_all; //12个选手容器 12
    vector<int> v_g1; //第一轮容器 6
    vector<int> v_g2; //第二轮容器 3
    map<int,speaker> m_victor; //存放获胜者编号和选手类 3
    int speak_game_count; //比赛轮数 2
};
