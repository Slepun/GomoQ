#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include <string>


class consoleView
{
    virtual void print() = 0;
    virtual void message(std::string *msg) = 0;

public:
    static void setColor(uint8_t color = 14);
};

#endif // CONSOLEVIEW_H
