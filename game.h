#ifndef GAME_H
#define GAME_H
#include "mainmenu.h"
#include "board.h"
#include "player.h"

typedef union sCheckDir{
    uint8_t all;
    struct{
        uint8_t goVertical:1;
        uint8_t goHorizontal:1;
        uint8_t goDiagonal:1;
    };

    void reset();
} sCheckDir;

typedef struct sMove{
    uint8_t row;
    uint8_t col;
} sMove;

class player;

class game : public mainMenu
{
public:
    game();
    ~game();

    void execute() override;

private:
    board mBoard;
    vector<std::shared_ptr<player>> mPlayers;



    sCheckDir mCheckDir;
    //uint8_t whoseTurn();
    //uint8_t changeTurn();

protected:
    virtual bool makeMove();

private:
    bool sameArround(const char &ch, const sMove &);
    bool sameCharAt(const char &ch, const sMove &);
    bool lineCheck(std::weak_ptr<player> wpPlayer, const uint8_t &rowDir, const uint8_t &colDir);
    bool win();
    void reset();


};

#endif // GAME_H
