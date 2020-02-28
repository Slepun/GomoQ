#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <iomanip>

#include "mainmenu.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::unique_ptr<mainMenu> vpMenu(new mainMenu);

    vpMenu->print();
    while (!vpMenu->chooseOption(vpMenu)) {
    }

    vpMenu->execute();
    vpMenu = nullptr;

    QTimer::singleShot(500, &a, SLOT(quit())); //stop after 0,5 seconds
    return a.exec();
}
