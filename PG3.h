//Lucas Christianson
//header file for Maze solving program

#ifndef _PG3_
#define _PG3_

#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"
using namespace std;

int main(int argc, char** argv);
void GetMaze();
void DisposeMaze(char**);
void PrintMaze(char** M);
char** copyMaze(char**);
int height();
int width();
void Solve();
// bool isDeadEnd(QObj*);
#endif