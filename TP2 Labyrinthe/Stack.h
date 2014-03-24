#include <string>
#include "Square.h"

using namespace std;

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

	Cell* first();
};