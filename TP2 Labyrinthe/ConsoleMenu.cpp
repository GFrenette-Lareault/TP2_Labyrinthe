#include <iostream>
#include <vector>
#include "ConsoleMenu.h"

using namespace System;

/** @file ConsoleMenu.cpp
	Fichier responsable de l'affichage, de l'interaction entre les menus et des entrées.

	@data 4 avril 2014
	@author Jean-David Moisan
	@author Gabriel Frenette-Laureault
	@version 1.0
*/

/**
	Permet de placer le curseur à une certaine position sur la console.
	Ensuite, pause pendant un certain nombre de milisecondes.
*/
void ConsoleMenu::setPosition(int x, int y, int time)
{
   try
   {
      Console::SetCursorPosition(x, y);
	_sleep(time);
   }
   catch (ArgumentOutOfRangeException^ e) 
   {
      Console::Clear();
      Console::WriteLine(e->Message);
   }
}

/**
	Reçoit en entrée un string représentant des coordonnées.
	Parse ces coordonnées et deplace le curseur d'après ces coordonnées.
*/
void ConsoleMenu::parseAndShowSolution(string s)
{
	vector<pair<int, int>> coordinates;

	int i = 0;
	while (i < s.size())
	{
		while (i < s.size() && s[i] != '(')
		{
			i++;
		}
		if (s[i] == '(')
		{
			string tokenX = "";
			string tokenY = "";
			i++;
			while (s[i] != ',')
			{
				tokenX += s[i];
				i++;
			}
			i += 2;
			while (s[i] != ')')
			{
				tokenY += s[i];
				i++;
			}
			coordinates.push_back(pair<int, int> (atoi(tokenX.c_str()), atoi(tokenY.c_str())));
			i++;
		}
	}

	for (int i = 0; i < coordinates.size(); i++)
	{
		setPosition(coordinates[i].first, coordinates[i].second, 500);
	}
}

/**
	Le coeur du programme. C'est ici que le programme est géré au niveau le plus haut.
*/
void ConsoleMenu::Run()
{
	char input;
	char tabValidInputs[] = {'V', 'v', 'S', 's', 'Q', 'q'};
	const int NB_ELEMENTS = 6;
	do
	{
		system("cls");
		input = readValidInput(tabValidInputs, NB_ELEMENTS);
	}
	while(manageChoice(input));
}

/** 
	readValidInput permet de lire une entrée des entrées par l'utilisateur tant et aussi longtemps que l'entrée n'est pas valide.
	@param _tabValidInputs Un tableau contenant les entrées valides.
	@param nbElements Le nombre d'éléments dans le tableau.
	@return Un charactère valide.
*/
char ConsoleMenu::readValidInput(char _tabValidInput[], int _nbElements)
{
	string inputStr;

	for (;;)
	{
		displayMenu();
		getline(cin, inputStr);

		for (int i = 0; i < _nbElements; i++)
		{
			string element = "";
			element.append(1, _tabValidInput[i]);
			if (inputStr == element)
			{
				return _tabValidInput[i];
			}
		}
		cout << "Veuillez entrer une donnée valide." << endl;
	}
}

/**
	displayMenu permet d'afficher le menu principale avec les actions permises.
*/
void ConsoleMenu::displayMenu()
{
	cout << "Entrez «V» pour visualiser le Labyrinthe, «S» pour solutionner le Labyrinthe ou «Q» pour quitter : ";
}

/**
	manageChoice fait les actions appropriées basées sur l'entré de l'utilisateur.
	@param _input Un entré valide.
	@return true si le programme doit continuer, false si il faut quitter.
*/
bool ConsoleMenu::manageChoice(char _input)
{
	Labyrinth lab("exemple1.txt");
	switch (_input)
	{
		case 'V':
		case 'v':
		{
			system("cls");
			cout << lab.ToString();
			system("pause");
			return true;
		}
		case 'S':
		case 's':
		{
			system("cls");
			Robot rob;
			rob.Explore(&lab);

			cout << lab.ToString();

			parseAndShowSolution(rob.getSolution());
			setPosition(0, 20, 0);
			system("pause");
			return true;
		}
		case 'Q':
		case 'q':
			return false;
	}
}