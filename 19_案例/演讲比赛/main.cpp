#include"speak_game_manager.cpp"


/*#include "speak_game_manager.h"*/
int main(){
    srand(time(0));
    speak_manager sm;
    // int c=sm.showmenu();
    // for (auto i = sm.v_all.begin(); i !=sm.v_all.end(); i++)
    // {   std::cout<<i->name<<" "<<i->number<<" "<<i->m_score[0]<<" "<<i->m_score[1]<<endl;
    //     /* code */
    // }
    sm.choice(sm.showmenu());
    return 0;
}