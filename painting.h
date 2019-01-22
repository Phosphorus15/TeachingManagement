//
// Created by Phosphorus15 on 2019/1/22.
//

#ifndef TEACHINGMANAGEMENT_PAINTING_H
#define TEACHINGMANAGEMENT_PAINTING_H

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#include <iostream>
#include <windows.h>
#include <cstdio>

HBITMAP loadBitmap(const char *file, int width, int height) {
    return (HBITMAP) LoadImage(nullptr, file, IMAGE_BITMAP, width, height,
                               LR_LOADFROMFILE);
}

void paintSizedBitmap(HBITMAP hBitmap, int x, int y, int width, int height) {
    HWND console = GetConsoleWindow();
    HDC hdc = GetDC(console);
    HBRUSH brush = CreatePatternBrush(hBitmap);
    RECT r2 = {x, y, x + width, y + height};
    FillRect(hdc, &r2, brush);
    DeleteObject(brush);
    ReleaseDC(console, hdc);
}

#endif //TEACHINGMANAGEMENT_PAINTING_H
