#include "Stack.h"

/** @file Stack.cpp
	Fichier responsable de contenir une pile de cases.

	@author Jean-David Moisan
	@author Gabriel Frenette-Lareault
	@date 4 avril 2014
	@version 1.0
 */

/**
	Constructeur de la classe interne Cell.
	@param _element Un square venant du labyrinth.
	@param _next Le prochain square dans la pile.
*/
Stack::Cell::Cell(Square* _element, Cell* _next)
{
	element = _element;
	next = _next;
}

/**
	Constructeur, s'assure que le premier node n'est pas initializé.
*/
Stack::Stack()
{
	first = NULL;
}

/**
	Vide la pile de ses éléments.
*/
Stack::~Stack()
{
	//TODO: Essentially, you'll have to pop until there is nothing left.
	while(!isEmpty())
	{
		Pop();
	}
}

/**
	Vérifie si la pile est vide.
	@return Vrai si la pile est vide. Faux sinon.
*/
bool Stack::isEmpty()
{
	if (first == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
	Insert un élément sur le dessus de la pile.
	@param _element Un square à ajouter à la pile.
*/
void Stack::Push(Square* _element)
{
	first = new Cell (_element, first);
}

/**
	Se départie de l'élément sur le dessus de la pile s'il y en a un.
*/
void Stack::Pop()
{
	if (!isEmpty())
	{
		Cell* temp = first->next;
		delete first;
		first = temp;
	}
}

/**
	Retourne l'élément sur le dessus de la pile.
	@return Le premier élément s'il y en a un. Null sinon.
*/
Square* Stack::Top()
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		return first->element;
	}
}

/**
	ToStringReverse est une fonction récursive qui retourne une version textuelle inversé
	de la pile.
	@return Une version textuelle inversé de la pile.
*/
string Stack::ToStringReverse()
{
	if(!isEmpty())
	{
		string current = "(" + to_string(Top()->x) + ", " + to_string(Top()->y) + ")\n";
		Pop();
		return ToStringReverse() + current;
	}
	return "";
}
