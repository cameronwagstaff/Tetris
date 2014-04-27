/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation of the ScoreTable class, which represents the   *
 *              high scores table                                              *
 * Date Created: 07 April 2014                                                 *
 * Date Last Modified: 26 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#include "ScoreTable.h"

using namespace std;

/*******************************************************************************
 * Description: constructor for the ScoreTable Class                           *
 * Return: nothing                                                             *
 * Pre: none                                                                   *
 * Post: object created                                                        *
 ******************************************************************************/
ScoreTable::ScoreTable()
: menuButton("Return to Menu", Point(95, 506), Point(95 + BUTTON_LENGTH,
                                                     506 + BUTTON_WIDTH),
                                                            WHITE, BLACK)
{
    backgroundColor = 0x22DC45;
    run = false;
}

/*******************************************************************************
 * Description: class destructor                                               *
 * Return: nothing                                                             *
 * Pre: object exists                                                          *
 * Post: saves the data. That should probably happen elsewhere, but for now,   *
 *       it's here                                                             *
 ******************************************************************************/
ScoreTable::~ScoreTable()
{
    save();
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
    int leftEdge = 3 * BORDER_WIDTH;
    int tab = 15 * characterWidth;
    int gap = 2.5 * characterHeight;

    drawBackground(g);

    drawCenteredString(g, "High Scores", Point(GAME_RIGHT / 2, 2 * BORDER_WIDTH)
                       , BLACK);

    //cursor will be the starting point for text drawing
    Point cursor(leftEdge, 6 * BORDER_WIDTH);

    //Draw Header
    drawString(g, "Name", cursor, BLACK);
    cursor.x += tab;
    drawString(g, "High Score", cursor, BLACK);
    cursor.x += tab;
    drawString(g, "Average Score", cursor, BLACK);

    cursor.x = leftEdge;
    cursor.y += gap + .5 * characterHeight;

    for(int i = 0; i < players.size() && i < 10; i++)
    {
        //Draw Player's daat.
        stringstream contentSS;

        contentSS << players[i].highScore;

        drawString(g, players[i].name, cursor, BLACK);
        cursor.x += tab;
        drawString(g, contentSS.str(), cursor, BLACK);
        contentSS.clear();
        contentSS << players[i].pointsPerGame();
        cursor.x += tab;
        drawString(g, contentSS.str(), cursor, BLACK);
        contentSS.clear();

        cursor.y += gap;
        cursor.x = leftEdge;
    }
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

    //reverse to have elements sorted in descending order
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
    Player *a;


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

    a = new Player [num];

    //read data
    data.read(reinterpret_cast<char*>(a), num * sizeof(Player));

    for(int i = 0; i < num; i++)
    {
        players.push_back(a[i]);
    }

    data.close();
}

/*******************************************************************************
 * Description: reduces the amount of spaghetti in ScoreTable::draw()          *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object unchanged, background drawn to screen                          *
 ******************************************************************************/
void ScoreTable::drawBackground(GLUT_Plotter *g)
{
    g->setColor(BACKGROUND_GRAY);
    for(int i = 0; i < SCREEN_WIDTH; i++)
    {
        for(int j = 0; j < SCREEN_HEIGHT; j++)
        {
            g->plot(i, j);
        }
    }

    g->setColor(BLACK);

    for(int i = 0; i < GAME_BOTTOM; i++)
    {
        g->plot(GAME_RIGHT, i);
    }


    g->setColor(backgroundColor);

    for(int i = BORDER_WIDTH; i < GAME_RIGHT - BORDER_WIDTH; i++)
    {
        for(int j = BORDER_WIDTH; j < GAME_BOTTOM - BORDER_WIDTH; j++)
        {
            g->plot(i, j);
        }
    }

    menuButton.draw(g);
}

/*******************************************************************************
 * Description: returns the value of the run variable                          *
 * Return: bool - the value of run                                             *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
bool ScoreTable::getRun()
{
    return run;
}

/*******************************************************************************
 * Description: sets the value of run                                          *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: run is assigned a value newVal                                        *
 ******************************************************************************/
void ScoreTable::setRun(bool newVal)
{
    run = newVal;
}

/*******************************************************************************
 * Description: allows us to be lazy by casting a ScoreTable into a bool       *
 * Return: technically nothing, effectually, the value of run                  *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
ScoreTable::operator bool()
{
    return getRun();
}

/*******************************************************************************
 * Description: getter for the menuButton Button                               *
 * Return: a reference to menuButton                                           *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Button& ScoreTable::getMenuButton()
{
    return menuButton;
}

/*******************************************************************************
 * Description: overloaded square brackets                                     *
 * Return: a reference to the Player at players[index]                         *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Player& ScoreTable::operator[](int index)
{
    return players[index];
}
