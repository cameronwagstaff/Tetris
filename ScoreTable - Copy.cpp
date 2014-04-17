/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation of the ScoreTable class, which represents the   *
 *              high scores table                                              *
 * Date Created: 07 April 2014                                                 *
 * Date Last Modified: 07 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#include "ScoreTable.h"

ScoreTable::ScoreTable()
{
    
}

ScoreTable& ScoreTable::addPlayer(string name)
{
    players.push_back(Player(name));
    
    return *this;
}

void ScoreTable::draw(GLUT_Plotter *g)
{
    
}

int ScoreTable::search(Player key)
{
    int position = -1;
    
    for(int i = 0; i < players.size() && position == -1; i++)
    {
        if(players[i] == key)
        {
            position = i;
        }
    }
    
    if(position == -1)
    {
        position = players.size();
        players.push_back(key);
    }
    
    return position;
}

int ScoreTable::search(string key)
{
    int position = -1;
    
    for(int i = 0; i < players.size() && position == -1; i++)
    {
        if(players[i].name == key)
        {
            position = i;
        }
    }
    
    if(position == -1)
    {
        position = players.size();
        players.push_back(Player(key));
    }
    
    return position;
}

void ScoreTable::sort()
{
    std::sort(players.data(), players.data() + players.size());
}

void ScoreTable::save()
{
    fstream data;
    
    data.open("scores.bin", ios::out|ios::binary);
    data.write(reinterpret_cast<char*>(players.data()),
               players.size() * sizeof(Player));
    
    data.close();
}

void ScoreTable::get() throw(NoScores)
{
    fstream data;
    int num;
    
    data.open("scores.bin", ios::in|ios::binary);
    
    if(!data)
    {
        throw(NoScores());
    }
    
    data.seekg(0L, ios::end);
    num = data.tellg() / sizeof(Player);
    data.seekg(0L, ios::beg);
    
    data.read(reinterpret_cast<char*>(players.data()), num * sizeof(Player));
}
