#include "consoleview.h"
#include <iostream>
#include <windows.h>   // WinApi header

void consoleView::setColor(uint8_t color)
{
    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
