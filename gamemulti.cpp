#include "gamemulti.h"
#include <iostream>
using namespace std;

uint8_t whoseTurn();

gameMulti::gameMulti()
{
    iam = player::PLAYER_1;
}

gameMulti::~gameMulti()
{
    cout << "Destroy gameMulti()" << endl;
}

void gameMulti::init()
{
    cout << "Creating gameMulti()" << endl;
    cout << "1. Server" << endl;
    cout << "2. Client" << endl;
    cout << "gameMulti init()" << endl;
    char choice = 0;
    cin >> choice;
    switch (choice)
    {
    case '1':
        cs.initServer();
        iam = player::PLAYER_1;
        break;
    case '2':
        cs.initClient();
        iam = player::PLAYER_2;
        break;
    }
}

bool gameMulti::myTurn()
{
    bool fRetVal = false;
    if(iam == whoseTurn())
    {
        fRetVal = true;
    }
    return fRetVal;
}

void gameMulti::waitForPlayer()
{
    uint8_t turn = game::whoseTurn();
    cout << "Waiting for Player" << turn << "move..." << endl;
    sMove recMove;
    cs.receiveMove(recMove);
    mBoard.putChar(mPlayers.at(turn)->getCharacter(), recMove.row, recMove.col);
}


bool gameMulti::makeMove()
{
    bool fRetVal = false;
    cout << "MakeMove MultiPlayer turn" << (int)game::whoseTurn() << endl;

    fRetVal = game::makeMove();
    if( fRetVal == true )
    {
        cs.sendMove(mPlayers.at(whoseTurn())->getLastMove());
    }

    return fRetVal;
}

