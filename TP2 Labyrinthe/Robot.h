#include <string>
#include "Square.h"
#include "Labyrinth.h"
#include "Stack.h"

using namespace std;

/** @file Robot.h
	Fichier contenant les entêtes de méthodes et procédures.

	@date 4 avril 2014
	@author Gabriel Frenette-Lareault
	@author Jean-David Moisan
	@version 1.0
*/

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