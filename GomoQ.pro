QT -= gui
QT += network

CONFIG += c++14 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        board.cpp \
        consoleview.cpp \
        game.cpp \
        gamemulti.cpp \
        gamesingle.cpp \
        main.cpp \
        mainmenu.cpp \
        multiplayer/clientserver.cpp \
        player.cpp \
        settings.cpp \
        userinput.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    board.h \
    consoleview.h \
    game.h \
    gamemulti.h \
    gamesingle.h \
    mainmenu.h \
    multiplayer/clientserver.h \
    player.h \
    settings.h \
    userinput.h

LIBS += -lws2_32
