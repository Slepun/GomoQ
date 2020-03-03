#include "player.h"
uint8_t player::numOfPlayers = 0;
bool player::isPlayer1 = true;

player::player()
{
    if(numOfPlayers == PLAYER_1)
    {
        name = "Player1";
        character = 'O';
        color = 10;//green
    }
    else
    {//PLAYER_2
        name = "Player2";
        character = 'X';
        color = 12;//red
    }
    lastCol = 0xFF;
    lastRow = 0xFF;
}

player::~player()
{
    numOfPlayers--;
}

std::string player::getName() const
{
    return name;
}

void player::setName(const std::string &value)
{
    name = value;
}

uint32_t player::getColor() const
{
    return color;
}

void player::setColor(const uint32_t &value)
{
    color = value;
}

uint16_t player::getPoints() const
{
    return points;
}

void player::incrementPoints(const uint16_t &value)
{
    points += value;
}

char player::getCharacter() const
{
    return character;
}

uint8_t player::getLastRow() const
{
    return lastRow;
}

uint8_t player::getLastCol() const
{
    return lastCol;
}

sMove player::getLastMove() const
{
    sMove retVal = { .row = lastRow, .col = lastCol };
    return retVal;
}
