#include"speak_game_manager.cpp"

// #include"speed_game_manager.h"
int main(){
    speak_manager sm;
    // int c=sm.showmenu();
    // for (auto i = sm.v_all.begin(); i !=sm.v_all.end(); i++)
    // {   std::cout<<i->name<<" "<<i->number<<" "<<i->m_score[0]<<" "<<i->m_score[1]<<endl;
    //     /* code */
    // }
    sm.choice(sm.showmenu());
    return 0;
}