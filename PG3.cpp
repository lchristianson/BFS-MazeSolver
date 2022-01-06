//Lucas Christianson
//This is a program which takes a user entered maze and finds the shortest path through the maze and prints
//out said path. It accomplishes this through the use of a queue and breadth-first searching.

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG3.h"
#include "Queue.h"
using namespace std;

char** Maze;
int w, h;
Queue* Q;

//This is the main method of the program.  The method prompts the user to enter the dimensions of the maze and then 
//enter the maze which coresponds to those dimensions.  Then the solve() method is called which does the majority of the
//maze solving.
int main(int argc, char** argv) {
	string columns;
	string rows;
	cout << "Please enter the width of your maze: ";
	getline(cin, columns);
	w = stoi(columns);
	cout << "Please enter the height of your maze: ";
	getline(cin, rows);
	h = stoi(rows);

	cout << "Build the maze using asterisks for walls and spaces for traversable areas." << endl;
	cout << "The upper left (starting) position must be a space." << endl << endl;
	
	GetMaze();
	cout << endl << "--------------------" << endl << "SOLUTION: " << endl << endl;

	Solve();

}

//Method allows the user to enter a maze using the keyboard.
void GetMaze() {
	Maze = new char* [h];
	for (int i = 0; i < h; i++) {
		Maze[i] = new char[w];
		for (int j = 0; j < w; j++)
			Maze[i][j] = NULL;
	}
	string temp;
	for (int i = 0; i < h; i++) {
		getline(cin, temp);
		for (int j = 0; j < w; j++) {
			Maze[i][j] = temp[j];
		}
	}
}

//Deletes the maze M.
void DisposeMaze(char** M) {

	for (int i = 0; i < h; i++)
		delete[] M[i];
	delete[] M;
}

//Prints a given maze M.
void PrintMaze(char** M) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//returns height of the maze
int height() {

	return h;
}

//returns width of the maze
int width() {

	return w;
}

//Uses a queue and breadth-first searching to find the fastest path through a given maze.
void Solve() {
	QObj* start = new QObj(0, 0, Maze);       //Enqueues the starting position
	Q = new Queue();
	Q->ENQUEUE(start);
	int row;
	int column;
	char** temp;
	while (Q != nullptr) {
		QObj* current = Q->DEQUEUE();        //declares a pointer to the dequeued object from the queue.
		row = current->getr();				//copies the current QObj's coordinates to new variables for ease of use.
		column = current->getc();           //
		temp = copyMaze(current->getM());   //stores a new copy of currents maze.
		temp[row][column] = 'x';            //marks currents position on the maze
		if (row == (h - 1) && column == (w - 1)) {     //if currents position is the end of the maze...
			PrintMaze(temp);                           //print solution
			delete current;                            //delete current
			break;                                     //stop while loop
		}
		if (row + 1 < h && Maze[row + 1][column] == ' ')         //This section checks if the adjacent locations
			Q->ENQUEUE(new QObj(row + 1, column, temp));         //are out of bounds.  If they are not, add to queue.
		if (row - 1 >= 0 && Maze[row - 1][column] == ' ')
			Q->ENQUEUE(new QObj(row - 1, column, temp));
		if (column + 1 < w && Maze[row][column + 1] == ' ') 
			Q->ENQUEUE(new QObj(row, column + 1, temp));
		if (column - 1 >= 0 && Maze[row][column - 1] == ' ') 
			Q->ENQUEUE(new QObj(row, column - 1, temp));

		delete current;                                         //deallocates current
	}
	DisposeMaze(Maze);  //deletes maze
	delete Q;          //deletes Q
}

//Dynamically allocates a new copy of the maze M and returns it.
char** copyMaze(char** M) {
	char** maze = new char*[h];
	for (int i = 0; i < h; i++) {
		maze[i] = new char[w];
		for (int j = 0; j < w; j++) {
			maze[i][j] = M[i][j];
		}
	}
	return maze;
}

