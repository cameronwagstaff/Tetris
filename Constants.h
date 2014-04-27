/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Contains various constants to be used in the Tetris game       *
 * Date Created:02 April 2014                                                  *
 * Date Last Modified:23 April 2014 - Cameron Wagstaff                         *
 ******************************************************************************/


#ifndef Tetris_Constants_h
#define Tetris_Constants_h

#include <string>

using namespace std;

//pieceTypes - const integers for switch statements used in the piece class
const int I = 0;
const int J = 1;
const int S = 2;
const int T = 3;
const int L = 4;
const int O = 5;
const int Z = 6;

//Piece Colors
const unsigned int CYAN             = 0x00FFFF;
const unsigned int PURPLE           = 0x6600FF;
const unsigned int GREEN            = 0x00FF00;
const unsigned int RED              = 0xFF0000;
const unsigned int BLUE             = 0x0000FF;
const unsigned int YELLOW           = 0xFFFF00;
const unsigned int ORANGE           = 0xFF6600;

//Colors
const unsigned int BACKGROUND_WHITE = 0xFBFBFF;     //White background for gameplay area
const unsigned int BACKGROUND_GRAY  = 0xADADAD;     //Gray background for main window colour
const unsigned int BLACK            = 0x000000;     //Black
const unsigned int WHITE            = 0xFFFFFF;     //White
const unsigned int MENU_BLUE        = 0x02449F;     //Blue for menu background
const unsigned int MENU_BUTTON_COLOR= 0xddbd00;     //Color for buttons in menu

//Screen Dimensions
const int GAME_RIGHT                = 500;          //x coordinate for the right edge of the gameplay area
const int GAME_BOTTOM               = 600;          //y coordinate for the bottom of the screen
const int BORDER_WIDTH              = 10;            //Width of the border around the gameplay area
const int SCREEN_WIDTH              = 800;          //Width of the window
const int SCREEN_HEIGHT             = 600;          //Height of the window
const int FALL_LENGTH               = 20;           //Defines how far shapes fall

//Shape Dimentsions
const int SQUARE_WIDTH              = 20;           //Side length of Squares
const int SQUARE_BORDER             = 2;            //Width of border on Squares

//Matrix Dimensions
const int MAX_ROWS                  = (GAME_RIGHT - 2 * BORDER_WIDTH) // Max number of Squares for width of game
                                      / SQUARE_WIDTH;
const int MAX_COLS                  = (GAME_BOTTOM - 2 * BORDER_WIDTH) // Max number of Squares for height of game
                                      / SQUARE_WIDTH;
const int MIN_ROWS                  = 0;
const int MIN_COLS                  = 0;

//Text
const int characterHeight           = 16; //Height of characters in Font.h in pixels
const int characterWidth            = 10;  //Width of characters in Font.h in pixels
const int MAX_LEN                   = 10; //Maximum number of characters a user's name may have

//Oddities
const string WINDOW_TITLE = "AWESOME TETRIS GAME"; //The string displayed on the title bar of the game

//Booleans
const bool MATT_IS_THE_BEST = true;                 //Just me being a narcissist

#endif
