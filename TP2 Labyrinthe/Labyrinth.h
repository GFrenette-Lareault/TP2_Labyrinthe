#pragma once

#include "Square.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Labyrinth
{
public:
	Labyrinth(string _fileName);
	~Labyrinth();
	string ToString();
	Square* GetStartSquare();
private:
	Square* startSquare;
	Square* tabSquare[20][20];
};