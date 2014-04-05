#include "labyrinth.h"

/** @file Labyrinth.cpp
	Fichier responsable de contenir le labyrinth.

	@author Jean-David Moisan
	@author Gabriel Frenette-Lareault
	@date 4 avril 2014
	@version 1.0
 */

/**
	Constructeur, prend en paramètre le nom du fichier labyrinth à ouvrir.
	@param _filename Le nom du fichier texte labyrinth à ouvrir.
*/
Labyrinth::Labyrinth(string _fileName)
{
	ifstream file("Ressources/" + _fileName);
	string str;
	for(int i = 0; i < 20; i++)
	{
		getline(file, str);
		for(int j = 0; j < 20; j++)
		{
			tabSquare[i][j] = new Square(j, i, str[j]);
			tabSquare[i][j]->visited = false;
			if (tabSquare[i][j]->value == 'D')
			{
				startSquare = tabSquare[i][j];
			}
		}
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			tabSquare[i][j]->lowerSquare = tabSquare[i+1][j];
			tabSquare[i][j]->rightSquare = tabSquare[i][j+1];

			tabSquare[i+1][j]->upperSquare = tabSquare[i][j];
			tabSquare[i][j+1]->leftSquare = tabSquare[i][j];
		}
	}

	tabSquare[19][18]->rightSquare = tabSquare[19][19];
	tabSquare[18][19]->lowerSquare = tabSquare[19][19];

	tabSquare[19][19]->leftSquare = tabSquare[19][18];
	tabSquare[19][19]->upperSquare = tabSquare[18][19];
}

/**
	Simple déconstructeur de pointeur de tableau.
*/
Labyrinth::~Labyrinth()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			delete tabSquare[i][j];
		}
	}
}

/**
	Permet de représenter le labyrinth.
	@return Une repésentation textuelle du labyrinth.
*/
string Labyrinth::ToString()
{
	string str = "";
	for(int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			str += tabSquare[i][j]->value;
		}
		str += "\n";
	}
	return str;
}

/**
	Méthode d'accessibilité.
	@return La case de départ du labyrinth.
*/
Square* Labyrinth::GetStartSquare()
{
	return startSquare;
}