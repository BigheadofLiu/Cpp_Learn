using namespace std;
#include"iostream"
#include<vector>
#include<deque>
#include <algorithm>

class player{
    public:
    player(int score ,string name ){
    this->name=name;
    this->score=score;
    }
    public:
    int score ;
    string name;
};
void creat_person(vector<player>& v){  //选手使用vector生成
    string nameNeed="ABCED";
    for(int i=0;i<nameNeed.size();i++){
        string name="选手";
        name+=nameNeed[i];
        int scoere=0;
        player p(scoere,name);
        v.push_back(p);
    }
}
void set_score(vector<player>& v){
    for (vector<player>::iterator it = v.begin(); it !=v.end(); it++)
    {   deque<int> q1;
        for(int i=0;i<10;i++){
            int score=rand()%41+60;
            q1.push_back(score);
        }
        sort(q1.begin(),q1.end());
        /* code */
        q1.pop_back();
        q1.pop_front();
        int sum_score=0;
        for(deque<int>::iterator it1=q1.begin();it1!=q1.end();it1++){
            sum_score+=*it1;
        }
        int ave_socre=sum_score/q1.size();
        it->score=ave_socre;   
    }
}
void print_player(vector<player>& v){
    for (vector<player>::iterator it = v.begin(); it !=v.end(); it++){
        cout<<"名字："<<it->name<<" "<<"分数:"<<it->score<<endl;
    }
}
int main(){
    vector<player> v1;
    creat_person(v1);
    set_score(v1);
    print_player(v1);
}