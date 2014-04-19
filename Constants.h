/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Contains various constants to be used in the Tetris game       *
 * Date Created:02 April 2014                                                  *
 * Date Last Modified:19 April 2014 - Brennan Saul                             *
 ******************************************************************************/


#ifndef Tetris_Constants_h
#define Tetris_Constants_h

using namespace std;

//Matrix Dimensions
const int MAX_ROWS = 30;
const int MAX_COLS = 50;
const int MIN_ROWS = 0;
const int MIN_COLS = 0;

//pieceTypes - const integers for switch statements used in the piece class
const int I = 0;
const int J = 1;
const int S = 2;
const int T = 3;
const int L = 4;
const int O = 5;
const int Z = 6;

//Piece Colors
const unsigned int CYAN   = 0x00FFFF;
const unsigned int PURPLE = 0x6600FF;
const unsigned int GREEN  = 0x00FF00;
const unsigned int RED    = 0xFF0000;
const unsigned int BLUE   = 0x0000FF;
const unsigned int YELLOW = 0xFFFF00;
const unsigned int ORANGE = 0xFF6600;

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
const int BORDER_WIDTH              = 6;            //Width of the border around the gameplay area
const int SCREEN_WIDTH              = 800;          //Width of the window
const int SCREEN_HEIGHT             = 600;          //Height of the window

//Booleans
const bool MATT_IS_THE_BEST = true;                 //Just me being a narcissist

#endif
