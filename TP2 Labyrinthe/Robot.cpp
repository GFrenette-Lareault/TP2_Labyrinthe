#include "robot.h"

/** @file Robot.cpp
	Fichier responsable de résoudre le labyrinth.

	@author Jean-David Moisan
	@author Gabriel Frenette-Lareault
	@date 4 avril 2014
	@version 1.0
 */

/**
	Constructeur, initialize un nouveau stack.
*/
Robot::Robot()
{
	pathStartToExit = new Stack();
}

/**
	Déconstructeur, détruit la référence vers le stack.
*/
Robot::~Robot()
{
	delete pathStartToExit;
}

/**
	Explore lance la recherche vers la sortie du labyrinth.
	@param _labyrinth Le labyrinth.
*/
void Robot::Explore(Labyrinth* _labyrinth)
{
	currentSquare = _labyrinth->GetStartSquare();
	searchPath(currentSquare, _labyrinth);
}

/**
	getSolution retourne la liste des cases jusqu'à la sortie.
	@return Un string contenant le chemin jusqu'à la sortie.
*/
string Robot::getSolution()
{
	return pathStartToExit->ToStringReverse();
}

/**
	findUnvisited est une fonction récursive qui permet de trouver une case encore non explorée
	à partir d'une case donnée.
	@param fromSquare La case qui doit être examinée.
	@param _labyrinth Le labyrinth à explorer.
*/
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

/**
	searchPath est une fonction récursive qui permet de trouver un chemin jusqu'à la sortie.
	@param fromSquare La case qui doit être examinée.
	@param _labyrinth Le labyrinth à explorer.
*/
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