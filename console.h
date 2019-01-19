//
// Created by Phosphorus15 on 2019/1/18.
//

#ifndef TEACHINGMANAGEMENT_CONSOLE_H
#define TEACHINGMANAGEMENT_CONSOLE_H

#ifndef __linux__ // linux system embedded macro
#define __windows__
#endif

#ifdef __windows__

#include <windows.h>

#endif

#include <cstdlib>
#include <cstdio>
#include <iostream>

namespace console {

    using u16 = unsigned short;

    void setcursor(u16 x, u16 y) {
#ifdef __windows__
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hStdout, {static_cast<short>(x), static_cast<short>(y)});
#else
        printf("\033[%d;%dH", x + 1, y + 1); // ANSI control approach
#endif
    }

    void clearscreen() {
#ifdef __windows__
        system("cls");
#else
        system("clear");
#endif
    }

    namespace color {

        enum _color_comps {
            blue = 1,
            green = 2,
            red = 4,
            yellow = 6,
            cyan = 3,
            magenta = 5,
            white = 7,
            black = 0,
            intensify = 8,
            _default = 9
        };

        struct mode {

            int foreground;

            int background;

            bool reset;

            bool set_bg;

            friend std::ostream &operator<<(std::ostream &out, const mode &m) {
#ifdef __windows__
                HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hStdout, static_cast<WORD>(m.foreground | m.background));
#else
                if (m.reset)
                    out << "\033[0m";
                else {
                    out << "\x1B[" << m.foreground << "m"
                    if(m.set_bg) out << "\x1B[" << m.background << "m";
                }
#endif
                return out;
            }

        };

#ifdef __windows__
        const bool default_intensify = true;
#else
        const bool default_intensify = false;
#endif

        unsigned short as_unix_color(_color_comps c) {
            switch (c) {
                case red:
                    return 31;
                case green:
                    return 32;
                case yellow:
                    return 33;
                case blue:
                    return 34;
                case magenta:
                    return 35;
                case cyan:
                    return 36;
                case white:
                    return 37;
                case black:
                    return 30;
                default:
                    return 37;
            }
        }

        mode setc(_color_comps foreground, _color_comps background = _default, bool bold = default_intensify) {
            if (foreground == _default) foreground = white;
#ifdef __windows__
            if (background == _default) background = black;
            WORD fore = (static_cast<WORD>(foreground));
            if (bold) fore |= intensify;
            WORD back = (static_cast<WORD>(background) << 4);
            return mode{fore, back, false, true};
#else
            unsigned short fore = 0, back = 0;
            fore = as_unix_color(foreground);
            back = as_unix_color(background) + 10;
            if(bold) fore += 60;
            return mode{fore, back, false, background != _default};
#endif
        }

        mode resetc() {
#ifdef __windows__
            return setc(white);
#else
            return mode{0, 0, true};
#endif
        }

    }

}

#endif //TEACHINGMANAGEMENT_CONSOLE_H
