/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines a class InputBox, a graphics object designed for the   *
 *              user to enter data                                             *
 * Date Created: 26 April 2014                                                 *
 * Date Last Modified: 26 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#ifndef __InputBox__
#define __InputBox__

#include "GLUT_Plotter.h"
#include "Button.h"
#include "Rectangle.h"
#include "Text.h"
#include "Constants.h"
#include <string>

using namespace std;
using namespace stdRect;

class InputBox
{
    private:
        stdRect::Rectangle background, dataBox;
        Button enter, cancel;
        string data, prompt;
        bool alNumErr, exceedsLength;

    public:
        InputBox(string prompt = "Enter data",
                 unsigned int backgroundColor = BACKGROUND_GRAY,
                 unsigned int buttonColor = YELLOW, string data = "");
        ~InputBox();
        InputBox(const InputBox& other);
        InputBox& operator = (const InputBox& other);
        stdRect::Rectangle& getBackground();
        stdRect::Rectangle& getDataBox();
        Button& getEnter();
        Button& getCancel();
        string& getData();
        void setData(string d);
        void draw(GLUT_Plotter *g);
        void erase(GLUT_Plotter *g);
        void setAlNumErr(bool val);
        void setExcedesLength(bool val);

};

#endif
