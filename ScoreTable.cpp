/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation of the ScoreTable class, which represents the   *
 *              high scores table                                              *
 * Date Created: 07 April 2014                                                 *
 * Date Last Modified: 10 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#include "ScoreTable.h"

/*******************************************************************************
 * Description: constructor for the ScoreTable Class
 * Return: nothing
 * Pre: none
 * Post: object created
 ******************************************************************************/
ScoreTable::ScoreTable()
{
    //This block intentionally left empty
}

/*******************************************************************************
 * Description: adds a player to the vector                                    *
 * Return: a reference to self                                                 *
 * Pre: object exists, name is a string                                        *
 * Post: Player with name name added to the end of vector players              *
 ******************************************************************************/
ScoreTable& ScoreTable::addPlayer(string name)
{
    players.push_back(Player(name));
    
    return *this;
}

/*******************************************************************************
 * Description: adds a player to the vector                                    *
 * Return: a reference to self                                                 *
 * Pre: object exists, p is of type Player                                     *
 * Post: Player with name name added to the end of vector players              *
 ******************************************************************************/
ScoreTable& ScoreTable::addPlayer(Player p)
{
    players.push_back(Player(p));
    
    return *this;
}


/*******************************************************************************
 * Description: will draw a ScoreTable to the screen onece Cam finishes text   *
 * Return: void                                                                *
 * Pre: object exists, Cameron has finished text                               *
 * Post: ScoreTable is drawn to the screen. Object unchanged                   *
 ******************************************************************************/
void ScoreTable::draw(GLUT_Plotter *g)
{
    
}

/*******************************************************************************
 * Description: Searches players for a given Player. If the Player is not found*
 *              it is added to the back of the vector players                  *
 * Return: an integer value representing the index of the Player in the vector *
 * Pre: object exists, key is valid, of type Player                            *
 * Post: if key is not found, it is added to players                           *
 ******************************************************************************/
int ScoreTable::search(Player key)
{
    int position = -1;
    
    //Search list using linear search
    for(int i = 0; i < players.size() && position == -1; i++)
    {
        if(players[i] == key)
        {
            position = i;
        }
    }
    
    //If Player not found, add to players
    if(position == -1)
    {
        position = players.size();
        addPlayer(key);
    }
    
    return position;
}

/*******************************************************************************
 * Description: Searches players for a given Player. If the Player is not found*
 *              it is added to the back of the vector players                  *
 * Return: an integer value representing the index of the Player in the vector *
 * Pre: object exists, key is valid, of type string                            *
 * Post: if key is not found, it is added to players                           *
 ******************************************************************************/
int ScoreTable::search(string key)
{
    int position = -1;
    
    //Search list using linear search
    for(int i = 0; i < players.size() && position == -1; i++)
    {
        if(players[i].name == key)
        {
            position = i;
        }
    }
    
    //If Player not found, add to players
    if(position == -1)
    {
        position = players.size();
        addPlayer(key);
    }
    
    return position;
}

/*******************************************************************************
 * Description: sorts the players vector using std::sort                       *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: players vector sorted in descending order                             *
 ******************************************************************************/
void ScoreTable::sort()
{
    //sort elements in ascending order
    std::sort(players.begin(), players.end());
    
    //reverse to have elements sorted in ascending order
    std::reverse(players.begin(), players.end());
}

/*******************************************************************************
 * Description: Writes the ScoreTable data to a binary file                    *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object unchanged, data written to binary file                         *
 ******************************************************************************/
void ScoreTable::save()
{
    fstream data;
    
    //open file and write data
    data.open("scores.bin", ios::out|ios::binary);
    data.write(reinterpret_cast<char*>(players.data()),
               players.size() * sizeof(Player));
    
    data.close();
}

/*******************************************************************************
 * Description: Reads data to the ScoreTable from a binary file                *
 * Return: void                                                                *
 * Pre: object exists, file is valid                                           *
 * Error: if file fails to open, a NoScores exception is thrown                *
 * Post: data from binary file read in to players                              *
 ******************************************************************************/
void ScoreTable::get() throw(NoScores)
{
    fstream data;
    int num;
    
    
    //Open and test file
    data.open("scores.bin", ios::in|ios::binary);
    
    if(!data)
    {
        throw(NoScores());
    }
    
    //Calculate number of Players in the file
    data.seekg(0L, ios::end);
    num = data.tellg() / sizeof(Player);
    data.seekg(0L, ios::beg);
    
    //read data
    data.read(reinterpret_cast<char*>(players.data()), num * sizeof(Player));
    
    data.close();
}
