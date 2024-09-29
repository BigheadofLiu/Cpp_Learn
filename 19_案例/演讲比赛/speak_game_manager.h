#pragma once
#include<iostream>
#include<vector>
#include<deque>
#include"speaker.h"
#include<map>
#include<algorithm>
#include<ctime>
#include<numeric>
#include "limits"
#include<time.h>
#include<windows.h>
/*#include"my_compare.cpp"*/
using namespace std;
class speak_manager{
    friend class mycompare_sort;
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
    void start_speak(); //
    // class quene_grater{};
    // bool operator()(speaker s1,speaker s2){};
 
    public:
    std::vector<speaker> v_all; //12个选手容器 12
    std::vector<speaker> v_g1; //第一轮容器 6
    std::vector<speaker> v_g2; //第二轮容器 3
    std::map<int,speaker> m_member; //存放参赛者编号和选手 12
    static int speak_game_count; //比赛轮数 2
    int speak_ref; //裁判数量
};
//函数对象按分数排序
class mycompare_sort{
public:
    bool operator()(const speaker& s1, const speaker& s2);
};

