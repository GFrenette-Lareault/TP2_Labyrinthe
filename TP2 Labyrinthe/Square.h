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