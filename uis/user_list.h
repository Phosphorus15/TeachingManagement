//
// Created by 18145 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_USER_LIST_H
#define TEACHINGMANAGEMENT_USER_LIST_H

#include <iostream>
#include "../console.h"
#include <vector>

using namespace console::color;


namespace user_list {

    struct User {
        std::string name;
        int password;
        std::string account_type;
    };

    std::vector<User> get_user() {
        return {{"studemt1",123456,"student"},
                {"teacher1",123457,"teacher"}};
    }

    const std::string header = "|-------------------------------------------------|\n"
                               "|                  User    List                   |\n"
                               "|------------------+------------+-----------------|\n"
                               "|     Name         | Password   |   Account_Type  |\n"
                               "|------------------+------------+-----------------|\n";

    const std::string item = "|%18s|%12d|%17s|\n"
                             "|------------------+------------+-----------------|\n";

    void userlist() {
        std::cout << setc(black, white, false) << "Back" << resetc() << std::endl << std::endl;
        std::cout << header << std::flush;
        auto users = get_user();
        for (auto &user : users) {
            printf(item.c_str(), user.name.c_str(), user.password, user.account_type.c_str());
        }
        std::cin.get();
    }

}


#endif //TEACHINGMANAGEMENT_USER_LIST_H
