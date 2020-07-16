#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "PersonQueue.h"
#include "DogQueue.h"
#include <curses.h>
#include <iostream>
class Simulator
{
private:
	void drawBoard();// draw the misgeret
	DogQueue _dq ;
	PersonQueue _pq;

public:
	static const int _numOfMoves = 17;
	static int _rows, _cols;
	Simulator(int rows, int cols);
	void run();
	
	~Simulator();
};

#endif