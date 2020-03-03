#include "game.h"
#include "userinput.h"
#include <iostream>
#include <memory>
#include <cctype>
#include <limits>
#include <stdlib.h>
using namespace std;

uint8_t whoseTurn();
void changeTurn();

game::game()
{
    mPlayers.push_back(shared_ptr<player>(new player));//p1
    mPlayers.push_back(shared_ptr<player>(new player));//p2
    mCheckDir.all = 0;
    cout << "Creating game()" << endl;
}

game::~game()
{
    cout << "Destroy game()";
}

void game::execute()
{
    cout << "Execute game..." << endl;
    init();
    do{
        //cout << "a shared pointers: " << mPlayers[0].use_count() << " " << mPlayers[1].use_count() << endl;
        //cout << "b shared pointers: " << mPlayers[0].use_count() << " " << mPlayers[1].use_count() << endl;
        mBoard.print();
        if(myTurn())
        {
            while(!makeMove()){};
            if(win())
            {
                mBoard.print();
                reset();
                cout << "KONIEC";
            }
        }
        else
        {
            waitForPlayer();
        }
        changeTurn();
    }while(true);

}

void game::init()
{
    //Do nothing
}


/*************************************/
/*          PRIVATE FCNs             */
/*************************************/
bool game::makeMove()
{
    bool fRetVal = true;

    setColor(mPlayers.at(whoseTurn())->getColor());
    cout << mPlayers.at(whoseTurn())->getName() << " put coordinates: ";
    setColor();
    sMove move = userInput::getRowCol();
    uint8_t row, col;
    row = move.row;
    col = move.col;

    if(mBoard.scopeCheck(row, col))
    {
        if(!mBoard.isOccupied(row, col))
        {
            weak_ptr<player> pwActivePlayer = mPlayers.at(whoseTurn());
            if(auto pActivePlayer = pwActivePlayer.lock())
            {
                mBoard.putChar(pActivePlayer->getCharacter(), row, col);
                setLastMove(pwActivePlayer, row, col);
            }
            else
            {
                cout << "No player referance" << endl;
                fRetVal = false;
            }
        }
        else
        {
            cout << "Field occupied" << endl;
            fRetVal = false;
        }
    }
    else
    {
        cout << "Out of scope!" << endl;
        fRetVal = false;
    }

    return fRetVal;
}

bool game::myTurn()
{
    return true;
}

void game::waitForPlayer()
{

}

bool game::sameArround(const char &ch, const sMove &move)
{
    sMove checkMove = move;

    uint8_t maxRow, maxCol;
    mBoard.getSize(maxRow, maxCol);
    if( move.col > 0)//Middle
    {
        checkMove.col = move.col - 1;
        checkMove.row = move.row;
        //Check Middle Left
        mCheckDir.goHorizontal |= sameCharAt(ch, checkMove);
    }
    if( move.col < maxCol)
    {
        checkMove.col = move.col + 1;
        checkMove.row = move.row;
        //Check Middle Right
        mCheckDir.goHorizontal |= sameCharAt(ch, checkMove);
    }


    if( move.row > 0 )//Top
    {
        checkMove.col = move.col;
        checkMove.row = move.row - 1;
        //Check Top Middle
        mCheckDir.goVertical |= sameCharAt(ch, checkMove);

        if(move.col > 0)
        {//Check Top Left
            checkMove.col = move.col - 1;
            mCheckDir.goDiagonal |= sameCharAt(ch, checkMove);

        }
        if( move.col < maxCol)
        {//Check Top Right
            checkMove.col = move.col + 1;
            mCheckDir.goDiagonal |= sameCharAt(ch, checkMove);
        }
    }
    if( move.row < maxRow )//Bottom
    {
        checkMove.row = move.row + 1;
        checkMove.col = move.col;
        //Check Bottom Middle
        mCheckDir.goVertical |= sameCharAt(ch, checkMove);

        if( move.col > 0)
        {//Check Bottom Left
            checkMove.col = move.col -1;
            mCheckDir.goDiagonal |= sameCharAt(ch, checkMove);
        }
        if( move.col < maxCol)
        {//Check Bottom right
            checkMove.col = move.col + 1;
            mCheckDir.goDiagonal |= sameCharAt(ch, checkMove);
        }
    }

    return (mCheckDir.all > 0);
}

bool game::sameCharAt(const char &ch, const sMove &move)
{
    bool fRetVal = false;
    uint8_t maxRow, maxCol;

    mBoard.getSize(maxRow, maxCol);
    if( move.row < maxRow && move.col < maxCol )
    {
        //mBoard.putChar('#', row, col);//TODO Remove while debug finished
        fRetVal = (ch == mBoard.getChar(move.row, move.col));
    }

    return fRetVal;
}

bool game::lineCheck(std::weak_ptr<player> wpPlayer, const uint8_t &rowDir, const uint8_t &colDir)
{
    bool win = false;
    const uint8_t MAX_POINT = 6;

    if( auto pPlayer = wpPlayer.lock() )
    {
        sMove checkDir = pPlayer->getLastMove();
        char ch = pPlayer->getCharacter();
        uint8_t points = 1;//Center point

        for(uint8_t i = 0; i < MAX_POINT; i++)
        {
            checkDir.row += rowDir;
            checkDir.col += colDir;
            if( sameCharAt(ch, checkDir) )
            {
                points++;
            }
            else
            {//Break in line
                break;
            }
        }

        checkDir = pPlayer->getLastMove();
        for(uint8_t i = 0; points < MAX_POINT && i < MAX_POINT; i++)
        {
            checkDir.row -= rowDir;
            checkDir.col -= colDir;
            if( sameCharAt(ch, checkDir) )
            {
                points++;
            }
            else
            {//Break in line
                break;
            }
        }
        if(points == (MAX_POINT - 1))
            win = true;
    }
    return win;
}

bool game::win()
{
    bool win = false;
    weak_ptr<player> pwActivePlayer = mPlayers.at(whoseTurn());
    if( auto pPlayer = pwActivePlayer.lock() )
    {
        sameArround(pPlayer->getCharacter(), pPlayer->getLastMove());
        if(mCheckDir.goDiagonal > 0)
        {
           win = lineCheck(pwActivePlayer, 1, 1);
        }
        if(!win && mCheckDir.goHorizontal > 0)
        {
           win = lineCheck(pwActivePlayer, 0, 1);
        }
        if(!win && mCheckDir.goVertical > 0)
        {
           win = lineCheck(pwActivePlayer, 1, 0);
        }

        if(win)
        {
            string msg = pPlayer->getName() + " WIN!";
            message(&msg);
        }
    }

    mCheckDir.reset();

    return win;
}

void game::reset()
{
    mBoard.resetBoard();
}


/*************************************/
/*          FRIEND FCNs              */
/*************************************/
uint8_t game::whoseTurn()
{
    uint8_t activePlayer = player::PLAYER_1;//player1
    if(!player::isPlayer1)
    {
        activePlayer =  player::PLAYER_1;//player2
    }
    //cout << "game WhoseTurn turn" << (int)activePlayer <<endl;
    return activePlayer;
}

void game::changeTurn()
{
    player::isPlayer1 = !player::isPlayer1;
}

void game::setLastMove(weak_ptr<player> pplayer, const uint8_t& row, const uint8_t &col)
{
    auto p = pplayer.lock();
    if(p)
    {
        p->lastRow = row;
        p->lastCol = col;
    }
}

void sCheckDir::reset()
{
    all = 0;
}
