#ifndef _QOBJ_
#define _QOBJ_

#include <iostream>
#include <string>
//Lucas Christianson
//header file for QObj (queue object)

#include <cstdlib>
using namespace std;

class QObj {

private:
	int r, c;
	char** M;
public:
	QObj(int R, int C, char** MZ);
	~QObj();
	int getr();
	int getc();
	char** getM();
};
#endif