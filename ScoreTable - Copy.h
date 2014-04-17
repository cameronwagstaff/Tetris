/*******************************************************************************
 * Author: Matt Arnold
 * Description:
 * Date Created: 07 April 2014
 * Date Last Modified: 07 April 2014 - Matt Arnold
 ******************************************************************************/

#ifndef Tetris_ScoreTable_h
#define Tetris_ScoreTable_h

#include <vector>
#include <fstream>
#include <algorithm>
#include "GLUT_Plotter.h"
#include "Player.h"

class NoScores{};

class ScoreTable
{
    private:
        vector<Player> players;
    
    public:
        ScoreTable();
        ScoreTable& addPlayer(string);
        void draw(GLUT_Plotter *g);
        int search(Player key);
        int search(string key);
        void sort();
        void save();
        void get() throw(NoScores);
    
};

#endif
