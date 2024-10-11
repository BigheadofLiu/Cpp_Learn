#include "person.h"
class admin:public person{
public:
    admin();
    admin(int,string,string);
    virtual void main_menu();
    void add_order();
    void show_order();
    void show_computer_info();
    void clear_order();
};