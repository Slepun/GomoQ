#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include <string>

struct sMove;

class player
{
public:
    player();
    player(uint8_t id);
    ~player();


    std::string getName() const;
    void setName(const std::string &value);

    uint32_t getColor() const;
    void setColor(const uint32_t &value);

    uint16_t getPoints() const;
    void incrementPoints(const uint16_t &value);

    friend uint8_t whoseTurn();//in game.cpp
    friend void changeTurn();//in game.cpp
    friend void setLastMove(std::weak_ptr<player> pplayer, const uint8_t& row, const uint8_t &col);//in game.cpp

    char getCharacter() const;
    uint8_t getLastRow() const;
    uint8_t getLastCol() const;
    sMove getLastMove() const;

private:
    static uint8_t numOfPlayers;
    static bool isPlayer1;
    const uint8_t PLAYER_1 = 1;
    const uint8_t PLAYER_2 = 2;
    std::string name;
    uint32_t color;
    uint16_t points;
    char character;
    uint8_t lastRow, lastCol;
};

#endif // PLAYER_H
