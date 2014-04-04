#include <iostream>
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

			setPosition(1, 1, 500);

			setPosition(2, 1, 500);

			setPosition(0, 20, 500);

			//cout << rob.getSolution();
			//TODO: Bonus point: Parse the return and animate the solution on screen.
			system("pause");
			return true;
		}
		case 'Q':
		case 'q':
			return false;
	}
}