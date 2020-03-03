#include "gamesingle.h"
#include <iostream>
#include "userinput.h"
using namespace std;

gameSingle::gameSingle()
{
    cout << "Creating gameSignle()" << endl;
}

gameSingle::~gameSingle()
{
    cout << "Destroy gameSingle()" << endl;
}

//bool gameSingle::makeMove()
//{
//    //cout << "MakeMove singlePlayer" << endl;
//    bool fRetVal = true;

//    setColor(mPlayers.at(whoseTurn())->getColor());
//    cout << mPlayers.at(whoseTurn())->getName() << " put coordinates: ";
//    setColor();
//    sMove move = userInput::getRowCol();
//    uint8_t row, col;
//    row = move.row;
//    col = move.col;

//    if(mBoard.scopeCheck(row, col))
//    {
//        if(!mBoard.isOccupied(row, col))
//        {
//            weak_ptr<player> pwActivePlayer = mPlayers.at(whoseTurn());
//            if(auto pActivePlayer = pwActivePlayer.lock())
//            {
//                mBoard.putChar(pActivePlayer->getCharacter(), row, col);
//                setLastMove(pwActivePlayer, row, col);
//            }
//            else
//            {
//                cout << "No player referance" << endl;
//                fRetVal = false;
//            }
//        }
//        else
//        {
//            cout << "Field occupied" << endl;
//            fRetVal = false;
//        }
//    }
//    else
//    {
//        cout << "Out of scope!" << endl;
//        fRetVal = false;
//    }

//    return fRetVal;
//}
