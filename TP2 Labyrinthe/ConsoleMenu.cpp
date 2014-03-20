#include "ConsoleMenu.h"

ConsoleMenu::ConsoleMenu()
{

}

void ConsoleMenu::Run()
{
	char menuInput;
	cout << "Entrez «V» pour visualiser le Labyrinthe, «S» pour solutionner le Labyrinthe ou «Q» pour quitter : ";
	cin >> menuInput;
}

char ConsoleMenu::readValidInput(int _tabValidInput, int _nbElements)
{
	return 'a';
}

void ConsoleMenu::displayMenu()
{

<<<<<<< HEAD
}

bool ConsoleMenu::manageChoice(char _input)
{
	return true;
}

ConsoleMenu::~ConsoleMenu()
{

=======
>>>>>>> 8488e1bd5a877481ac14150074ae783d0a9631a5
}