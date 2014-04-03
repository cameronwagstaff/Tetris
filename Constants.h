/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Contains various constants to be used in the Tetris game       *
 * Date Created:02 April 2014                                                  *
 * Date Last Modified:02 April 2014 - Matt Arnold                              *
 ******************************************************************************/


#ifndef Tetris_Constants_h
#define Tetris_Constants_h

using namespace std;

//Type - enumerated type to represent the shape of the block.
enum Type {I,J,S,T,L,O,Z};

//Colors
const unsigned int BACKGROUND_WHITE = 0xFBFBFF;     //White background for gameplay area
const unsigned int BACKGROUND_GRAY  = 0xADADAD;     //Gray background for main window colour
const unsigned int BLACK            = 0x000000;     //Black
const unsigned int WHITE            = 0xFFFFFF;     //White

//Screen Dimensions
const int GAME_RIGHT                = 500;          //x coordinate for the right edge of the gameplay area
const int GAME_BOTTOM               = 600;          //y coordinate for the bottom of the screen
const int BORDER_WIDTH              = 6;            //Width of the border around the gameplay area
const int SCREEN_WIDTH              = 800;          //Width of the window
const int SCREEN_HEIGHT             = 600;          //Height of the window

//Booleans
const bool MATT_IS_THE_BEST = true;                 //Just me being a narcissist


#endif
