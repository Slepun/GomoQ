#include "gamesingle.h"
#include <iostream>
using namespace std;

gameSingle::gameSingle()
{
    cout << "Creating gameSignle()" << endl;
}

gameSingle::~gameSingle()
{
    cout << "Destroy gameSingle()" << endl;
}

bool gameSingle::makeMove()
{
    //cout << "MakeMove singlePlayer" << endl;
    return game::makeMove();
}
