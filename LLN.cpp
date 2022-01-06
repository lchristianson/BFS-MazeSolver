//Lucas Christianson
//This class defines the nodes used to store QObj's which are then used in the queue

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"
#include "LLN.h"
using namespace std;

//constructor
LLN::LLN(QObj* obj) {

	info = obj;
	next = nullptr;
}

//destructor
LLN::~LLN() {

	delete info;
	delete next;
}

//returns info of queue object
QObj* LLN::getinfo() {

	return info;
}

//sets info of queue object
void LLN::setinfo(QObj* obj) {

	info = obj;
}

//returns a pointer to the node following this.
LLN* LLN::getnext() {

	return next;
}

//sets the next node to n.
void LLN::setnext(LLN* n) {

	next = n;
}