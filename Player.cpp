/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementatin of the Player struct                             *
 * Date Created: 07 April 2014                                                 *
 * Date Last Modified: 10 April 2014 - Matt Arnold                             *
 ******************************************************************************/
#include "Player.h"

/*******************************************************************************
 * Description: constructor for the Player struct                              *
 * Return: nothing                                                             *
 * Pre: none                                                                   *
 * Post: Player object constructed                                             *
 ******************************************************************************/
Player::Player(string name)
{
    this->name = name;
    highScore = 0;
    gamesPlayed = 0;
    totalScore = 0;
}

/*******************************************************************************
 * Description: Calculates the average number of points a Player has earned per*
 *              game.                                                          *
 * Return: a double representing the average points per game                   *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
double Player::pointsPerGame() const
{
    return static_cast<double>(totalScore) / gamesPlayed;
}

/*******************************************************************************
 * Description: Adds data from a game to the Player                            *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: gamesPlayed incremented, totalScore updated. If score > highScore,    *
 *        value of highScore changed to value of score                         *
 ******************************************************************************/
void Player::addGame(int score)
{
    gamesPlayed += 1;
    totalScore += score;
    
    if(score > highScore)
    {
        highScore = score;
    }
    
}

/*******************************************************************************
 * Description: Less than operator for the Player class                        *
 * Return: true if Player's score is less than other's score                   *
 * Pre: Object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
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

/*******************************************************************************
 * Description: Tests Players' names for equality                              *
 * Return: true if the Players have the same name, false otherwise             *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
bool Player::operator == (const Player& other) const
{
    return this->name == other.name;
}

/*******************************************************************************
 * Description: Greater than operator for Players                              *
 * Return: True if Player is not less than and not equal to other, false       *
 *         otherwise                                                           *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
bool Player::operator > (const Player& other) const
{
    return ! (*this <other) && !(*this == other);
}

