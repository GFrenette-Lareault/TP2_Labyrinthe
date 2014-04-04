#include <iostream>
#include <vector>
#include "ConsoleMenu.h"

using namespace System;

void ConsoleMenu::setPosition(int x, int y, int time)
{
   try
   {
      Console::SetCursorPosition(x, y + 3);
	_sleep(time);
   }
   catch (ArgumentOutOfRangeException^ e) 
   {
      Console::Clear();
      Console::WriteLine(e->Message);
   }
}

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

void ConsoleMenu::displayMenu()
{
	cout << "Entrez «V» pour visualiser le Labyrinthe, «S» pour solutionner le Labyrinthe ou «Q» pour quitter : ";
}

bool ConsoleMenu::manageChoice(char _input)
{
	Labyrinth lab("exemple1.txt");
	switch (_input)
	{
		case 'V':
		case 'v':
		{
			cout << lab.ToString();
			system("pause");
			return true;
		}
		case 'S':
		case 's':
		{
			Robot rob;
			rob.Explore(&lab);

			cout << endl;

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