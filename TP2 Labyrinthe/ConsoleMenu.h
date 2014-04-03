#include <iostream>
#include <string>
#include "Stack.h"
#include "Labyrinth.h"
#include "Robot.h"

using namespace std;

class ConsoleMenu
{
public:
	void Run();
	ConsoleMenu();
	~ConsoleMenu();

private:
	char readValidInput(char _tabValidInput[], int _nbElements);
	void displayMenu();
	bool manageChoice(char _input);
	Stack stc;
};
