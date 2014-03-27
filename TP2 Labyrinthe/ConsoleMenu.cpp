#include <iostream>
#include "ConsoleMenu.h"
#include "Labyrinth.h"

ConsoleMenu::ConsoleMenu()
{

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
	return 'a';
}

void ConsoleMenu::displayMenu()
{
	cout << "Entrez «V» pour visualiser le Labyrinthe, «S» pour solutionner le Labyrinthe ou «Q» pour quitter : ";
}

bool ConsoleMenu::manageChoice(char _input)
{
	Labyrinth lab("exemple1.txt");
	cout << "Done" << endl;
	cout << lab.ToString();
	system("pause");
	return true;
}

ConsoleMenu::~ConsoleMenu()
{

}