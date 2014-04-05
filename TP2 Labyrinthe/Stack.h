#pragma once

#include <string>
#include <iostream>
#include "Square.h"

using namespace std;

/** @file Stack.h
	Fichier contenant les entêtes de méthodes et procédures.

	@date 4 avril 2014
	@author Gabriel Frenette-Lareault
	@author Jean-David Moisan
	@version 1.0
*/

class Stack
{
public:
	Stack();
	~Stack();
	void Pop();
	void Push(Square* _element);
	Square* Top();
	bool isEmpty();
	string ToStringReverse();
private:
	class Cell
	{
	public:
		Cell(Square* _element, Cell* _next);
		Square* element;
		Cell* next;
	};

	Cell* first;
};