#include "Stack.h"

Stack::Cell::Cell(Square* _element, Cell* _next)
{
	element = _element;
	next = _next;
}

Stack::Stack()
{
	first = NULL;
}

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

void Stack::Push(Square* _element)
{

	first = new Cell (_element, first);

}