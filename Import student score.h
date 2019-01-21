//
// Created by Bario on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_IMPORT_STUDENT_SCORE_H
#define TEACHINGMANAGEMENT_IMPORT_STUDENT_SCORE_H

#endif //TEACHINGMANAGEMENT_IMPORT_STUDENT_SCORE_H

#include <iostream>
#include <conio.h>
#include "console.h"

using namespace console::color;

namespace import_score {

    bool confirm(std::string msg, int line) {
        console::setcursor(0, line);
        std::cout << msg << std::endl;
        unsigned long long n = msg.length();
        bool yes = true;
        while (true) {
            console::setcursor(n + 2, line);
            if (yes) std::cout << setc(black, white, false);
            std::cout << "Yes" << resetc() << "/";
            if (!yes) std::cout << setc(black, white, false);
            std::cout << "No" << resetc();
            if (yes) console::setcursor(n + 2, line);
            else console::setcursor(n + 6, line);
            int ch = getch();
            if (ch == 224) {
                ch = getch();
                if (ch == KEY_LEFT) yes = true;
                if (ch == KEY_RIGHT) yes = false;
            } else {
                if (ch == '\r') return yes;
            }
        }
    }

    struct Score {
        std::string id;
        std::string name;
        int score;
    };


    void save_student_score(Score score) {
         // TODO
    }

    void import_score() {
        console::clearscreen();
        Score score;
        std::cout << "¼��ѧ���ɼ�--------------";
        std::cout << "����ѧ�ţ� ";
        std::cin >> score.id;
        std::cout << "ѧ����";
        std::cin >> score.name;
        std::cout << "�ɼ���";
        std::cin >> score.score;
        std::cout <<setc(yellow)<< "����ɹ�!" << std::endl;
        save_student_score(score);
        if (confirm("����ɹ����Ƿ����¼��?", 6)) {
            import_score();
        } else {
            console::clearscreen();
        }
    }

}