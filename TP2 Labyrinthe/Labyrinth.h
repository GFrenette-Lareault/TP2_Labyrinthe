#pragma once

#include "Square.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/** @file Labyrinth.h
	Fichier contenant les entêtes de méthodes et procédures.

	@date 4 avril 2014
	@author Gabriel Frenette-Lareault
	@author Jean-David Moisan
	@version 1.0
*/

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