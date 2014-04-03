#include <string>
#include "Square.h"
#include "Labyrinth.h"
#include "Stack.h"

using namespace std;

class Robot
{
public:
	Robot();
	~Robot();
	void Explore(Labyrinth* _labyrinth);
	string getSolution();
private:
	Stack* pathStartToExit;
	Square* currentSquare;

	Square* findUnvisited(Square* fromSquare, Labyrinth* _labyrinth);
	bool searchPath(Square* fromSquare, Labyrinth* _labyrinth);
};