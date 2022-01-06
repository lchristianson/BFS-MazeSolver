//Lucas Christianson
//defines the Queue class.  This class is used to store LLN's containing QObj's.  The queue holds unvisited 
//coordinates of the maze.

#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"
#include "LLN.h"
#include "QObj.h"
using namespace std;

//constructor
Queue::Queue() {

	head = nullptr;
}

//destructor
Queue::~Queue() {

	delete head;
}

//adds a QObj (queue object) to the end of the queue.
void Queue::ENQUEUE(QObj* obj) {

	if (!head) head = tail = new LLN(obj);
	else {
		tail->setnext(new LLN(obj));
		tail = tail->getnext();
	}
}

//removes the head QObj (queue object) and return a pointer to it.
QObj* Queue::DEQUEUE() {

	if (!head) return nullptr;
	QObj* obj = head->getinfo();
	LLN* t = head;
	head = head->getnext();
	t->setnext(nullptr);
	t->setinfo(nullptr);
	delete t;
	return obj;
}

//checks if the queue is empty.
bool Queue::EMPTY() {

	return !head;
}