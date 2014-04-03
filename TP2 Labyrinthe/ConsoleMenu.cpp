#include <iostream>
#include "ConsoleMenu.h"

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
			cout << rob.getSolution();
			system("pause");
			return true;
		}
		case 'Q':
		case 'q':
			return false;
	}
}