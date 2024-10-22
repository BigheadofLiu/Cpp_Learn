

#include"order_login.cpp"
#include"save_file.h"
#include <string>
#include"admin.h"
/*using namespace login;*/
int main(){
    int select=0;
    while(true){
        std::cout << "======================  欢迎来到机房预约系统  =====================" << endl;
		std::cout << endl << "请输入您的身份" << endl;
		std::cout << "\t\t -------------------------------\n";
		std::cout << "\t\t|                               |\n";
		std::cout << "\t\t|          1.学生代表           |\n";
		std::cout << "\t\t|                               |\n";
		std::cout << "\t\t|          2.老    师           |\n";
		std::cout << "\t\t|                               |\n";
		std::cout << "\t\t|          3.管 理 员           |\n";
		std::cout << "\t\t|                               |\n";
		std::cout << "\t\t|          0.退    出           |\n";
		std::cout << "\t\t|                               |\n";
		std::cout << "\t\t -------------------------------\n";
		std::cout << "输入您的选择: ";
		std::cin >> select; //接受用户选择
        switch(select){
            case 1:	
			/*login::*/
			/* admin::login(STUDENT_FILE,select); */	//学生
                login::login(STUDENT_FILE,select);
			break;
            case 2:
			/* admin::login(TEACHER_FILE,select); */		//老师
                login::login(TEACHER_FILE,select);
			break;
            case 3:
			/* admin::login(ADMIN_FILE,select); */		//管理员
                login::login(ADMIN_FILE,select);
			break;
            case 0:{    	//退出
			int c1=0;
			std::cout<<"确认退出？"<<endl;
			std::cout<<"1.确认"<<endl;
			std::cout<<"2.取消"<<endl;
			std::cin>>c1;
			switch(c1){
				case 1: system("pause >nul"); return 0; break;
				case 2: system("cls");break;
				default:
				std::cout << "输入有误，请重新选择！" << endl;
				system("pause >nul");
				system("cls");
				break;
			}
			break;
            }
			default:
			std::cout << "输入有误，请重新选择！" << endl;
			system("pause >nul");
			system("cls");
			break;
        }
    }

}