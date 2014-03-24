#include <iostream>
#include <string>

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
};
