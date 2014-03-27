#include "labyrinth.h"

Labyrinth::Labyrinth(string _fileName)
{
	cout << "File reading start" << endl;
	ifstream file("Ressources/" + _fileName);
	string str;
	while (getline(file, str))
	{
		for(int i = 0; i < 20; i++)
		{

		}
		cout << str.length() << endl;
	}
}

Labyrinth::~Labyrinth()
{

}

string Labyrinth::ToString()
{
	return "A string representation of the Labyrinth.";
}

Square* Labyrinth::GetStartSquare()
{
	return NULL;
}