#ifndef SETTINGS_H
#define SETTINGS_H
#include "mainmenu.h"

class settings : public mainMenu
{
public:
    settings();

    void execute() override;
};

#endif // SETTINGS_H
