/*******************************************************************************
 * Author: Matt Arnold
 * Description:
 * Date Created: 07 April 2014
 * Date Last Modified: 24 April 2014 - Matt Arnold
 ******************************************************************************/

#ifndef Tetris_ScoreTable_h
#define Tetris_ScoreTable_h

#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "GLUT_Plotter.h"
#include "Player.h"
#include "Constants.h"
#include "Point.h"
#include "Text.h"
#include "Button.h"

using namespace std;

class NoScores{};

class ScoreTable
{
    private:
        vector<Player> players;
        Button menuButton;
        unsigned int backgroundColor;
        bool run;

        void drawBackground(GLUT_Plotter *g);

    public:
        ScoreTable();
        ScoreTable& addPlayer(string);
        ScoreTable& addPlayer(Player p);
        void draw(GLUT_Plotter *g);
        int search(Player key);
        int search(string key);
        void sort();
        void save();
        void get() throw(NoScores);
        bool getRun();
        void setRun(bool newVal);
        operator bool();
        Button getMenuButton();
};

#endif
