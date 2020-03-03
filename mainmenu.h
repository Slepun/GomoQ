#ifndef MAINMENU_H
#define MAINMENU_H
#include "consoleview.h"
#include <string>
#include <map>
#include <memory>

class mainMenu : public consoleView
{
public:
    typedef  void (mainMenu::*menuChoiceFnP)(void);//ptr to fcn

    mainMenu();
    mainMenu(std::map<int, std::string>&);
    mainMenu(mainMenu&& object);
    mainMenu& operator=(mainMenu&& object);
    virtual ~mainMenu();

    void print() override;
    //std::unique_ptr<mainMenu> chooseOption(std::unique_ptr<mainMenu>&);
    bool chooseOption(std::unique_ptr<mainMenu>&);
    virtual void execute();

protected:
    void message(std::string *msg) override;
    void logo();

private:
    void startLocalPvP(void);
    void startNetworkPvP(void);

private:
    std::map<int, std::string> menuOptions;
    std::map<int, menuChoiceFnP> menuOptionsBind;
};

#endif // MAINMENU_H
