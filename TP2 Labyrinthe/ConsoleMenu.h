#include <iostream>
#include <string>
#include "Stack.h"
#include "Labyrinth.h"
#include "Robot.h"

using namespace std;

/** @file ConsoleMenu.h
	Fichier contenant les entêtes de méthodes et procédures.

	@date 4 avril 2014
	@author Gabriel Frenette-Lareault
	@author Jean-David Moisan
	@version 1.0
*/

class ConsoleMenu
{
public:
	void Run();

private:
	char readValidInput(char _tabValidInput[], int _nbElements);
	void displayMenu();
	bool manageChoice(char _input);
	void setPosition(int x, int y, int time);
	void parseAndShowSolution(string s);
};
