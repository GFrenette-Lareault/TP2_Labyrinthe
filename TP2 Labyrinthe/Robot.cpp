#include "robot.h"

Robot::Robot()
{
	pathStartToExit = new Stack();
}

Robot::~Robot()
{
	
}

void Robot::Explore(Labyrinth* _labyrinth)
{
	currentSquare = _labyrinth->GetStartSquare();
	searchPath(currentSquare, _labyrinth);
}

string Robot::getSolution()
{
	return "";
}

Square* Robot::findUnvisited(Square* fromSquare, Labyrinth* _labyrinth)
{
	Square* unvisitedSquare;
	if(fromSquare->rightSquare != NULL && fromSquare->rightSquare->value != 'X' && !fromSquare->rightSquare->visited)
	{
		unvisitedSquare = fromSquare->rightSquare;
	}
	else if(fromSquare->lowerSquare != NULL && fromSquare->lowerSquare->value != 'X' && !fromSquare->lowerSquare->visited)
	{
		unvisitedSquare = fromSquare->lowerSquare;
	}
	else if(fromSquare->leftSquare != NULL && fromSquare->leftSquare->value != 'X' && !fromSquare->leftSquare->visited)
	{
			unvisitedSquare = fromSquare->leftSquare;
	}
	else if(fromSquare->upperSquare != NULL && fromSquare->upperSquare->value != 'X' && !fromSquare->upperSquare->visited)
	{
		unvisitedSquare = fromSquare->upperSquare;
	}
	else
	{
		unvisitedSquare = fromSquare;
	}

	return unvisitedSquare;
}

bool Robot::searchPath(Square* fromSquare, Labyrinth* _labyrinth)
{
	if (fromSquare->value != 'S')
	{
		fromSquare->visited = true;
		Square* nextSquare = findUnvisited(fromSquare, _labyrinth);

		while (fromSquare != nextSquare)
		{
			pathStartToExit->Push(fromSquare);
			if (searchPath(nextSquare, _labyrinth))
			{
				return true;
			}
			else
			{
				pathStartToExit->Pop();
			}

			nextSquare = findUnvisited(fromSquare, _labyrinth);
		}
		return false;
	}
	else
	{
		pathStartToExit->Push(fromSquare);
		return true;
	}



}