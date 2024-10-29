//
// Created by ZYB on 2024/10/24.
//

#ifndef VSCODE_ORDER_H
#define VSCODE_ORDER_H
#include <iostream>
#include <string>
#include <map>
#include "save_file.h"
#include "fstream"
class order {
public:
    order();
    void update_order();

    int order_num;
    struct is_empty{
        int busy[6][3];
    };
    std::map<int,is_empty> is_empty_map;
    std::map<int ,std::map<std::string,std::string>> order_map;  //<<预约号，<预约，信息>>
};
#endif //VSCODE_ORDER_H
