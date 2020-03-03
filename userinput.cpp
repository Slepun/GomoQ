#include "userinput.h"
#include <sstream>
#include <iostream>
using namespace std;

static uint8_t alphabetToNumber(char ch);

userInput::userInput()
{

}

sMove userInput::getRowCol()
{
    sMove move;
    string input;

    while (input.length()==0 )
        getline(cin, input);

    stringstream ss;
    ss << input;

    string temp;
    char chFound;
    int found;
    while (!ss.eof()) {
        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
        {
            move.row = found;
        }
        else
        {
            stringstream(temp) >> chFound;
            move.col = alphabetToNumber(chFound);
        }
        /* To save from space at the end of string */
        temp = "";
    }
    return move;
}

uint8_t alphabetToNumber(char ch)
{
    uint8_t num = 0xFF;
    if (ch >= 'A' && ch <= 'Z')
      num = ch - 'A';
    else if (ch >= 'a' && ch <= 'z')
      num = ch - 'a';

    return num;
}
