#include "board.h"
#include "iostream"
using namespace std;

board::board() : INIT_SIGN('_'), mBoard(ROWS, vector<char>(COLS, INIT_SIGN))
{
}

void board::print()
{
    system("cls");
    std::cout << "\t\t###########################################" << std::endl;
    std::cout << "\t\t#                   GomoQ                 #" << std::endl;
    std::cout << "\t\t###########################################" << std::endl;
    printUpDownLegend();
    printUpDownEdge();
    printMiddle();
    printUpDownEdge();
    printUpDownLegend();
}

void board::putChar(char character, uint8_t row, uint8_t col)
{
    if( (character == 'O' || character == 'X' || character == '#') && (row < ROWS) && (col < COLS))
    {
        mBoard[row][col] = character; //TODO check if not occupied
    }
}

char board::getChar(const uint8_t &row, const uint8_t &col)
{
    return mBoard[row][col];
}

void board::getSize(uint8_t &row, uint8_t &col) const
{
    row = mBoard.size();
    col = mBoard.begin()->size();
}

void board::resetBoard()
{
    for(int i = 0; i < static_cast<int>(mBoard.size()); i++)
    {
        for(int j = 0; j < static_cast<int>(mBoard[i].size()); j++)
        {
            mBoard[i][j] = INIT_SIGN;
        }
    }
}


/*************************************/
/*          PRIVATE FCNs             */
/*************************************/
void board::printUpDownLegend()
{
    cout << "\t\t";
    char col_legend = 'A';
    cout << "    ";
    for(int i = 0; i <= static_cast<int>(mBoard.size()-1); i++)
    {
        cout << " " << col_legend;
        col_legend++;
    }
    cout << endl;
}

void board::message(string *msg)
{
    cout << *msg;
}

bool board::isOccupied(uint8_t row, uint8_t col)
{
    bool fRetVal = false;
    if(mBoard[row][col] != INIT_SIGN)
    {
        fRetVal = true;
    }
    return fRetVal;
}

bool board::scopeCheck(uint8_t row, uint8_t col)
{
    bool fRetVal = false;
    if(row < ROWS && col < COLS)
    {
        fRetVal = true;
    }
    return fRetVal;
}

void board::printUpDownEdge()
{
    cout << "\t\t   ";
    for(int i = 0; i <= static_cast<int>(mBoard.size()*2+2); i++)
    {
        cout << "=";
    }
    cout << endl;
}

void board::printMiddle()
{
    for(int i = 0; i < static_cast<int>(mBoard.size()); i++)
    {
        cout << "\t\t";
        cout.width(2);
        cout << i << " | ";

        for(int j = 0; j < static_cast<int>(mBoard[i].size()); j++)
        {
            if(mBoard[i][j] == 'O')
                setColor(10);
            else if(mBoard[i][j] == 'X')
                setColor(12);
            else
                setColor();
            cout << mBoard[i][j] << " ";
        }

        cout << "| " << i << endl;
    }
}
