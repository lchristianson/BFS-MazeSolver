//Lucas Christianson
//Source code which defines a QObj (queue object).  These objects are synonomous to a coordinate in the entered maze
//and are used to enqueue its neighbors and pass along the correctly updated maze.

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"
#include "PG3.h"
using namespace std;

//constructor.  Initializes r to R, c to C, and sets the objects maze (M) to MZ
QObj::QObj(int R, int C, char** MZ) {

	r = R;
	c = C;
	M = new char* [height()];
	for (int i = 0; i < height(); i++) {
		M[i] = new char[width()];
		for (int j = 0; j < width(); j++)
			M[i][j] = MZ[i][j];
	}
}

//destructor
QObj::~QObj() {

	for (int i = 0; i < height(); i++)
		delete M[i];
	delete M;
}

//returns row index of the queue object
int QObj::getr() {

	return r;
}

//returns column index of the queue object
int QObj::getc() {

	return c;
}

//returns the maze of the queue object
char** QObj::getM() {

	return M;
}
