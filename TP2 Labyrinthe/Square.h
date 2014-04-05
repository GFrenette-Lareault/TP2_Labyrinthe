#pragma once

/** @file Square.h
	Contient la définition de la structure Square.

	@date 4 avril 2014
	@author Gabriel Frenette-Lareault
	@author Jean-David Moisan
	@version 1.0
*/

struct Square 
{
	int x;
	int y;
	char value;
	bool visited;
	Square* upperSquare;
	Square* rightSquare;
	Square* leftSquare;
	Square* lowerSquare;

	Square(int _x, int _y, char _value) : x(_x), y(_y), value(_value){}
};