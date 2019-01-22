//
// Created by Bario on 2019/1/21.
//

#ifndef TEACHINGMANAGEMENT_COURSE_INFORMATION_H
#define TEACHINGMANAGEMENT_COURSE_INFORMATION_H

#endif //TEACHINGMANAGEMENT_COURSE_INFORMATION_H

using namespace console::color;

namespace course_information{

    const std::string options[5]={"Browse  course","Append  course","Edit    course","Remove  course","Return"};


    void course_information(){
        console::clearscreen();
        std::string text ="|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n"
                          "|~                                                   ~|\n"
                          "|*              Course management menu               *|\n"
                          "|~                                                   ~|\n"
                          "|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~                                                   ~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~                                                   ~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~                                                   ~|\n"
                          "|*                                                   *|\n"
                          "|~                                                   ~|\n"
                          "|~***~***~***~***~***~***~***~***~***~***~***~***~***~|\n";
        int ch;
        int s = 0;
        while (true) {
            console::clearscreen();
            std::cout<<text<<std::endl;
            const int x = 18;
            for (int i = 0; i < 5; i++) {
                console::setcursor(x, static_cast<console::u16>(6+ 2*i));
                if (i == s) std::cout << setc(black, white, false);
                std::cout << options[i] << std::flush;
                if (i == s) std::cout << resetc();
            }
            ch = getch();
            if (ch == 224) {
                ch = getch();
                if (ch == KEY_UP) {
                    if (s > 0) s--;
                } else if (ch == KEY_DOWN) {
                    if (s < 4) s++;
                }
            } else {
                if (ch == '\r') {
                    if (s == 4) return;
                    if (s == 0) course_list::courselist();
                    if (s == 1) add_course_information::add_course_information();
                    if (s == 2) edit_course_information::edit_course_information();
                    if (s == 3) delete_course_information::delete_course_information();
                    course_information();
                    return;
                }
            }
        }
    }

}
