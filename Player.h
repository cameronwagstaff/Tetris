/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines a Player struct to hold data about a player            *
 * Date Created: 07 April 2014                                                 *
 * Date Last Modified: 10 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#ifndef __Player__
#define __Player__

#include <string>

using namespace std;

struct Player
{
    string name;
    int highScore, gamesPlayed, totalScore;
    
    Player(string name = "");
    double pointsPerGame() const;
    void addGame(int score);
    bool operator < (const Player& other) const;
    bool operator == (const Player& other) const;
    bool operator > (const Player& other) const;
};


#endif