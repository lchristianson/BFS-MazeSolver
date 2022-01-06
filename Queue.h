//Lucas Christianson
//header file for the queue class
//The queue is used to hold unexplored QObj (queue objects) which pg3.cc uses to solve the maze

#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
#include "QObj.h"
using namespace std;

class LLN;
class Queue {

private:
	LLN* head, * tail;
public:
	Queue();
	~Queue();
	void ENQUEUE(QObj* obj);
	QObj* DEQUEUE();
	bool EMPTY();
};
#endif