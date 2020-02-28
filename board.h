#ifndef BOARD_H
#define BOARD_H
#include "consoleview.h"
#include <vector>
#include <stdint.h>

using std::vector;

class board : public consoleView
{
public:
    board();
    void print() override;
    void putChar(char character, uint8_t row, uint8_t col);
    char getChar(const uint8_t &row, const uint8_t &col);
    bool isOccupied(uint8_t row, uint8_t col);
    bool scopeCheck(uint8_t row, uint8_t col);
    void getSize(uint8_t &row, uint8_t &col) const;
    void resetBoard();


private:
    void printUpDownEdge(void);
    void printMiddle(void);
    void printUpDownLegend(void);
    void message(std::string *msg) override;

private:
    const int COLS = 15;    //TODO get from settings
    const int ROWS = 15;    //TODO get from settings
    const char INIT_SIGN;

    vector<vector<char> > mBoard;
};

#endif // BOARD_H
