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
	char readValidInput(int _tabValidInput, int _nbElements);
	void displayMenu();
	bool manageChoice(char _input);
};
