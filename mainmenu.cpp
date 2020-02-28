#include "mainmenu.h"
#include "game.h"
#include "gamesingle.h"
#include "gamemulti.h"
#include "settings.h"

#include <iostream>
#include <stdlib.h>


mainMenu::mainMenu()
{
    std::cout << "Creating mainMenu()" << std::endl;
    menuOptions[1] = "Local PvP";
    menuOptions[2] = "Network PvP";
    menuOptions[3] = "Settings";
    menuOptions[4] = "Exit";
    menuOptionsBind[1] = &mainMenu::startLocalPvP;
    menuOptionsBind[2] = &mainMenu::startNetworkPvP;

}

mainMenu::~mainMenu()
{
    std::cout << "Destroy mainMenu()" << std::endl;
}

void mainMenu::print()
{
    setColor();
    system("cls");
    logo();
    std::cout << std::endl;
    for (auto x : menuOptions)
          std::cout << x.first << ". " << x.second << std::endl;
}

//std::unique_ptr<mainMenu> mainMenu::chooseOption(std::unique_ptr<mainMenu>& action)
bool mainMenu::chooseOption(std::unique_ptr<mainMenu>& action)
{
    //std::unique_ptr<mainMenu> retPtr = std::unique_ptr<mainMenu>(this);
    bool fRetVal = true;
    std::cout << "Choice: ";
    int choice = 0;
    std::cin >> choice;

    system("cls");
    switch (choice)
    {
        case 1:
        {
            //std::unique_ptr<mainMenu> pg(new gameSingle);
            action.reset(new gameSingle);
            //return  pg;
            break;
        }
        case 2:
        {
            //std::unique_ptr<mainMenu> pg(new gameMulti);
            action.reset(new gameMulti);
            //return  pg;
            break;
        }
        case 3:
        {
            //std::unique_ptr<mainMenu> ps(new settings);
            action.reset(new settings);
            //return ps;
            break;
        }
        case 4:
        {
            action.release();
            system("exit");
            break;
        }
        default:
        {
            system("cls");
            print();
            std::string msg = "Wrong item id. Pissible choice " + std::to_string(menuOptions.begin()->first) + \
                    " - " + std::to_string(menuOptions.size()) + "\n";
            message(&msg);
            fRetVal = false;
            //action.reset(new gameSingle);
            //chooseOption();
            break;
        }
    }
    //return  std::unique_ptr<mainMenu>(this);
    return fRetVal;
}

void mainMenu::execute()
{
    std::cout << "Execute mainMenu..." << std::endl;
}



/*************************************/
/*          PROTECTED FCNs           */
/*************************************/
void mainMenu::message(std::string *msg)
{
    std::cout << *msg;
}

void mainMenu::logo()
{
    std::cout << "###########################################" << std::endl;
    std::cout << "#                   GomoQ                 #" << std::endl;
    std::cout << "###########################################" << std::endl;
}


/*************************************/
/*          PRIVATE FCNs             */
/*************************************/
void mainMenu::startLocalPvP()
{

}

void mainMenu::startNetworkPvP()
{

}


