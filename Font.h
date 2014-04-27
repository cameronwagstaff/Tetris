/******************************************************************************
Author: Cameron Wagstaff
Date Last Edited: 4/24/2014 - Matt Arnold - A E Y J

This file holds the font that the Text class uses to draw text.

MAKE SURE THAT CAMERON KNOWS ABOUT CHANGES TO THIS FILE PLEASE
******************************************************************************/

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

const int characters16[][16][10] = {

//0
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,1,1,1,0,0},
 {0,1,1,0,1,1,1,1,0,0},
 {0,1,1,0,1,0,1,1,0,0},
 {0,1,1,1,1,0,1,1,0,0},
 {0,1,1,1,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//1
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,1,1,1,0,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,1,1,1,1,1,0,0},
 {0,0,0,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//2
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,1,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,1,1,0},
 {0,0,1,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,0,0,0,0}},

//3
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,0,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,1,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,1,1,1,0,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,1,0,0},
 {0,0,1,0,0,0,1,1,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,0,1,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//4
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//5
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,1,1,1,1,0,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//6
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,1,1,1,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//7
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,1,1,0},
 {0,0,1,1,1,1,1,1,1,0},
 {0,0,1,0,0,0,0,1,1,0},
 {0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,1,1,1,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,1,1,1,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//8
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//9
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,1,0,0,0},
 {0,0,0,1,1,0,1,1,0,0},
 {0,0,1,0,0,0,0,1,1,0},
 {0,0,1,0,0,0,0,1,1,0},
 {0,0,1,0,0,0,0,1,1,0},
 {0,0,0,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,1,1,1,0},
 {0,0,0,0,0,0,0,1,1,0},
 {0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,1,1,1,0,0,0},
 {0,0,0,0,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//A
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,1,1,1,0,0,1,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,0,0,0,0,0,0,0,0,0}},

//b
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,0,0,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,1,1,0,1,1,0,0,0,0},
 {0,1,1,1,1,0,0,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//C
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,1,1,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,1,1,0,0,0,1,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,0,1,1,0,0,0,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//D
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,0,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//E
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//F
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//G
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,1,1,1,0,0},
 {0,1,1,0,0,1,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//H
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//I
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,0,0,0,0}},

//J
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,0,0,0,0,1,1,0,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//K
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,1,1,0,1,1,0,0,0,0},
 {0,1,1,1,1,0,0,0,0,0},
 {0,1,1,1,1,1,0,0,0,0},
 {0,1,1,0,1,1,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//L
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//M
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,1,0,0,1,1,1,0},
 {0,1,1,1,0,0,1,1,1,0},
 {0,1,1,1,0,0,1,1,1,0},
 {0,1,1,0,1,1,0,1,1,0},
 {0,1,1,0,1,1,0,1,1,0},
 {0,1,1,0,1,1,0,1,1,0},
 {0,1,1,0,1,1,0,1,1,0},
 {0,1,1,0,1,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,0,0,0,0,0,0,0,0,0}},

//N
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,1,0,0,0,1,1,0},
 {0,1,1,1,0,0,0,1,1,0},
 {0,1,1,1,0,0,0,1,1,0},
 {0,1,1,1,1,0,0,1,1,0},
 {0,1,1,0,1,0,0,1,1,0},
 {0,1,1,0,1,1,0,1,1,0},
 {0,1,1,0,0,1,0,1,1,0},
 {0,1,1,0,0,0,1,1,1,0},
 {0,1,1,0,0,0,1,1,1,0},
 {0,1,1,0,0,0,1,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,0,0,0,0,0,0,0,0,0}},

//O
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//P
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//Q
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,1,0,1,1,0,0},
 {0,1,1,0,1,1,1,1,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,1,1,1,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//R
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,1,1,1,1,1,0,0,0,0},
 {0,1,1,1,1,0,0,0,0,0},
 {0,1,1,0,1,1,0,0,0,0},
 {0,1,1,0,0,1,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//S
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,1,1,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,1,1,1,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,0,1,1,1,1,1,0,0,0},
 {0,0,0,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//T
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//U
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,0,1,1,1,1,1,1,0,0},
 {0,0,1,1,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//V
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,0,1,0,0,1,1,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//W
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,1,1,0,1,1,0,1,1,0},
 {0,1,1,0,1,1,0,1,1,0},
 {0,1,1,1,1,1,1,1,1,0},
 {0,1,1,1,0,0,1,1,1,0},
 {0,1,1,1,0,0,1,1,1,0},
 {0,1,1,1,0,0,1,1,1,0},
 {0,1,1,0,0,0,0,1,1,0},
 {0,0,0,0,0,0,0,0,0,0}},

//X
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,0,1,0,0,0,1,0,0,0},
 {0,0,1,1,0,1,1,0,0,0},
 {0,0,0,1,0,1,0,0,0,0},
 {0,0,0,0,1,0,0,0,0,0},
 {0,0,0,1,1,1,0,0,0,0},
 {0,0,1,1,0,1,1,0,0,0},
 {0,0,1,1,0,1,1,0,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,1,1,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//Y
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,1,1,0,0,1,1,0,0},
 {0,0,0,1,1,1,1,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//Z
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,1,0,0},
 {0,0,0,0,0,1,1,1,0,0},
 {0,0,0,0,1,1,1,0,0,0},
 {0,0,0,0,1,1,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,1,1,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,1,1,1,1,1,1,1,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//SPACE
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//PERIOD
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//COLON
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

//COMMA
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,0,1,1,0,0,0,0,0},
 {0,0,1,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,1,0,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,1,1,1,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}},

/*
{{,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,},
 {,,,,,,,,,}},*/

};

#endif // FONT_H_INCLUDED
