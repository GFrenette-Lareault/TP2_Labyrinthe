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

Stack::~Stack()
{
	//TODO: Essentially, you'll have to pop until there is nothing left.
	while(!isEmpty())
	{
		Pop();
	}
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

void Stack::Pop()
{
	if (!isEmpty())
	{
		Cell* temp = first->next;
		delete first;
		first = temp;
	}
}

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
