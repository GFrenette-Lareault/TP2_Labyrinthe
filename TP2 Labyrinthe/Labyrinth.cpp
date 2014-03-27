#include "labyrinth.h"

Labyrinth::Labyrinth(string _fileName)
{
	cout << "File reading start" << endl;
	ifstream file("Ressources/" + _fileName);
	string str;
	for(int i = 0; i < 20; i++)
	{
		getline(file, str);
		for(int j = 0; j < 20; j++)
		{
			tabSquare[i][j] = new Square(j, i, str[j]);
		}
		cout << str.length() << endl;
	}
	for(int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << tabSquare[i][j]->value;
		}
		cout << endl;
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