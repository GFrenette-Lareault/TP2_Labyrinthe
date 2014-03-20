#include "ConsoleMenu.h"

ConsoleMenu::ConsoleMenu()
{

}

void ConsoleMenu::Run()
{
	cout << "Entrez «V» pour visualiser le Labyrinthe, «S» pour solutionner le Labyrinthe ou «Q» pour quitter : ";
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

}

bool ConsoleMenu::manageChoice(char _input)
{
	return true;
}

ConsoleMenu::~ConsoleMenu()
{

}