/*******************************************************************************
 * Author: Matt Arnold
 * Description:
 * Date Created: 07 April 2014
 * Date Last Modified: 07 April 2014 - Matt Arnold
 ******************************************************************************/
#include "Player.h"


Player::Player(string name)
{
    this->name = name;
    highScore = 0;
    gamesPlayed = 0;
    totalScore = 0;
}

double Player::pointsPerGame() const
{
    return static_cast<double>(totalScore) / gamesPlayed;
}

bool Player::operator < (const Player& other) const
{
    bool result = false;
    
    if(this->highScore < other.highScore)
    {
        result = true;
    }
    
    if(!result && this->gamesPlayed < other.gamesPlayed)
    {
        result = true;
    }
    
    if(!result && this->pointsPerGame() < other.pointsPerGame())
    {
        result = true;
    }
    
    return result;
}

bool Player::operator == (const Player& other) const
{
    return this->name == other.name;
}

