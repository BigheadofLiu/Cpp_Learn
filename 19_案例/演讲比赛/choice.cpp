#include"choice.h"
#include"speed_game_manager.h"
void choice(int c){
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
			
			break;
		default:
			cout<<"输入有误"<<endl;
			system("cls"); //清屏
			break;
}
}