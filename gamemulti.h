#ifndef GAMEMULTI_H
#define GAMEMULTI_H
#include "game.h"
#include "multiplayer/clientserver.h"

class gameMulti : public game
{
public:
    gameMulti();
    ~gameMulti();

private:
    clientServer cs;
    uint8_t iam;
    bool makeMove() override;
    void init() override;
    bool myTurn() override;
    void waitForPlayer() override;
};

#endif // GAMEMULTI_H
