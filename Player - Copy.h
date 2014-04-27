/*******************************************************************************
 * Author: Matt Arnold
 * Description:
 * Date Created: 07 April 2014
 * Date Last Modified: 07 April 2014 - Matt Arnold
 ******************************************************************************/

#ifndef __Player__
#define __Player__

#include <string>

using namespace std;

struct Player
{
    string name;
    int highScore, gamesPlayed, totalScore;
    
    Player(string name);
    double pointsPerGame() const;
    bool operator < (const Player& other) const;
    bool operator == (const Player& other) const;
};


#endif