/*
 * Tetris.h - Tetris game class header
 *
 *  Created on: Mar 28, 2014
 *  Created on: Mar 28, 2014
 *      Author: Dr. Booth
 */

#ifndef TETRIS_H_
#define TETRIS_H_
#include "GLUT_Plotter.h"


class Tetris{
private:
	GLUT_Plotter *g;

public:
	//constructor
	Tetris(GLUT_Plotter* g);

	//Main GAIM FUNCTION
	void Play(void);
};

#endif /* TETRIS_H_ */